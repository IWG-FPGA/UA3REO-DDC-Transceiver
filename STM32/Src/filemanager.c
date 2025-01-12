#include "filemanager.h"
#include "lcd.h"
#include "sd.h"
#include "system_menu.h"
#include "wifi.h"

static bool first_start = true;
static uint16_t current_index = 0;
static FILEMANAGER_ACTION current_dialog_action = FILMAN_ACT_CANCEL;

SRAM char FILEMANAGER_CurrentPath[128] = "";
SRAM char FILEMANAGER_LISTING[FILEMANAGER_LISTING_MAX_FILES][FILEMANAGER_LISTING_MAX_FILELEN + 1] = {""};
uint16_t FILEMANAGER_files_startindex = 0;
uint16_t FILEMANAGER_files_count = 0;
bool FILEMANAGER_dialog_opened = false;
uint16_t FILEMANAGER_dialog_button_index = 0;

static void FILEMANAGER_Refresh(void);
static void FILEMANAGER_OpenDialog(void);
static void FILEMANAGER_DialogAction(void);

void FILEMANAGER_Draw(bool redraw)
{
	if (first_start)
	{
		first_start = false;
		FILEMANAGER_files_startindex = 0;
		current_index = 0;
		strcpy(FILEMANAGER_CurrentPath, "");
		FILEMANAGER_Refresh();
		return;
	}
	if (redraw)
	{
		LCDDriver_Fill(BG_COLOR);
		uint16_t cur_y = 5;
		LCDDriver_printText("SD CARD FILE MANAGER", 5, cur_y, COLOR_GREEN, BG_COLOR, 2);
		cur_y += 24;
		if (strlen(FILEMANAGER_CurrentPath) == 0)
			LCDDriver_printText("/", 5, cur_y, FG_COLOR, BG_COLOR, 2);
		else
			LCDDriver_printText(FILEMANAGER_CurrentPath, 5, cur_y, FG_COLOR, BG_COLOR, 2);
		cur_y += 24;
		if (FILEMANAGER_files_startindex == 0)
			LCDDriver_printText("..", 5, cur_y, FG_COLOR, BG_COLOR, 2);
		cur_y += LAYOUT->SYSMENU_ITEM_HEIGHT;

		for (uint16_t file_id = 0; file_id < FILEMANAGER_LISTING_ITEMS_ON_PAGE; file_id++)
		{
			LCDDriver_printText(FILEMANAGER_LISTING[file_id], 5, cur_y, FG_COLOR, BG_COLOR, 2);
			cur_y += LAYOUT->SYSMENU_ITEM_HEIGHT;
		}

		LCD_UpdateQuery.SystemMenuRedraw = false;
	}

	LCDDriver_drawFastHLine(0, 5 + 24 + 24 + LAYOUT->SYSMENU_ITEM_HEIGHT + (current_index * LAYOUT->SYSMENU_ITEM_HEIGHT) - 1, LAYOUT->SYSMENU_W, FG_COLOR);

	if(FILEMANAGER_dialog_opened)
		FILEMANAGER_OpenDialog();
	
	LCD_UpdateQuery.SystemMenu = false;
}

void FILEMANAGER_EventRotate(int8_t direction)
{
	if(FILEMANAGER_dialog_opened)
	{
		FILEMANAGER_DialogAction();
		return;
	}
	
	if (current_index == 0) //go up
	{
		if (strcmp(FILEMANAGER_CurrentPath, "") == 0) // root
		{
			SYSMENU_eventCloseSystemMenu();
		}
		else //inner folder
		{
			char *istr = strrchr(FILEMANAGER_CurrentPath, '/');
			*istr = 0;
			FILEMANAGER_files_startindex = 0;
			current_index = 0;
			FILEMANAGER_Refresh();
		}
	}
	else
	{
		char *istr = strstr(FILEMANAGER_LISTING[current_index - 1], "[DIR] ");
		if (istr != NULL && ((strlen(istr + 6) + 1) < sizeof(FILEMANAGER_CurrentPath))) //is directory
		{
			strcat(FILEMANAGER_CurrentPath, "/");
			strcat(FILEMANAGER_CurrentPath, istr + 6);
			FILEMANAGER_files_startindex = 0;
			current_index = 0;
			FILEMANAGER_Refresh();
		}
		else //is file
		{
			FILEMANAGER_dialog_button_index = 0;
			FILEMANAGER_OpenDialog();
		}
	}
}

void FILEMANAGER_EventSecondaryRotate(int8_t direction)
{
	if(FILEMANAGER_dialog_opened)
	{
		if(FILEMANAGER_dialog_button_index > 0 || direction > 0)
			FILEMANAGER_dialog_button_index += direction;
		FILEMANAGER_OpenDialog();
		return;
	}
	
	LCDDriver_drawFastHLine(0, 5 + 24 + 24 + LAYOUT->SYSMENU_ITEM_HEIGHT + (current_index * LAYOUT->SYSMENU_ITEM_HEIGHT) - 1, LAYOUT->SYSMENU_W, BG_COLOR);
	if (direction > 0 || current_index > 0)
		current_index += direction;

	int16_t real_file_index = FILEMANAGER_files_startindex + current_index - 1;

	//limit
	if (real_file_index >= FILEMANAGER_files_count)
		current_index--;

	//list down
	if (current_index > FILEMANAGER_LISTING_ITEMS_ON_PAGE && real_file_index < FILEMANAGER_files_count)
	{
		FILEMANAGER_files_startindex += FILEMANAGER_LISTING_ITEMS_ON_PAGE;
		current_index = 1;
		FILEMANAGER_Refresh();
	}

	//list up
	if (FILEMANAGER_files_startindex > 0 && current_index == 0)
	{
		FILEMANAGER_files_startindex -= FILEMANAGER_LISTING_ITEMS_ON_PAGE;
		current_index = FILEMANAGER_LISTING_ITEMS_ON_PAGE;
		FILEMANAGER_Refresh();
	}

	LCD_UpdateQuery.SystemMenu = true;
}

void FILEMANAGER_Closing(void)
{
	first_start = true;
}

static void FILEMANAGER_Refresh(void)
{
	if (!SD_doCommand(SDCOMM_LIST_DIRECTORY, false))
		SYSMENU_eventCloseSystemMenu();

	LCD_UpdateQuery.SystemMenuRedraw = true;
}

static void FILEMANAGER_OpenDialog(void)
{
	FILEMANAGER_dialog_opened = true;
	bool allow_play_wav = false;
	bool allow_flash_bin = false;
	bool allow_flash_jic = false;
	uint8_t max_buttons_index = 1; //cancel+delete
	
	
	//check play wav
	char *istr = strstr(FILEMANAGER_LISTING[current_index - 1], ".wav");
	if (istr != NULL)
	{
		max_buttons_index++;
		allow_play_wav = true;
	}
	//check flash stm32 bin
	istr = strstr(FILEMANAGER_LISTING[current_index - 1], ".bin");
	if (istr != NULL)
	{
		max_buttons_index++;
		allow_flash_bin = true;
	}
	//check flash fpga jic
	istr = strstr(FILEMANAGER_LISTING[current_index - 1], ".jic");
	if (istr != NULL)
	{
		max_buttons_index++;
		allow_flash_jic = true;
	}
	
	if(FILEMANAGER_dialog_button_index > max_buttons_index)
		FILEMANAGER_dialog_button_index = max_buttons_index;
	
	#define margin 30
	//frame
	LCDDriver_Fill_RectXY(margin, margin, LCD_WIDTH - margin, LCD_HEIGHT - margin, BG_COLOR);
	LCDDriver_drawRectXY(margin, margin, LCD_WIDTH - margin, LCD_HEIGHT - margin, FG_COLOR);
	//buttons
	uint16_t button_y = margin * 2;
	uint16_t button_x = margin * 2;
	uint16_t button_w = LCD_WIDTH - margin * 2 - button_x;
	uint16_t button_h = margin;
	uint16_t bounds_x, bounds_y, bounds_w, bounds_h;
	uint8_t print_index = 0;
	bool button_active = false;
	//back
	button_active = (FILEMANAGER_dialog_button_index == print_index);
	LCDDriver_Fill_RectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? FG_COLOR : BG_COLOR);
	LCDDriver_drawRectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? BG_COLOR : FG_COLOR);
	LCDDriver_getTextBounds("Cancel", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
	LCDDriver_printTextFont("Cancel", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
	button_y += button_h + margin;
	if(button_active)
		current_dialog_action = FILMAN_ACT_CANCEL;
	print_index++;
	//play wav
	if(allow_play_wav)
	{
		button_active = (FILEMANAGER_dialog_button_index == print_index);
		LCDDriver_Fill_RectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? FG_COLOR : BG_COLOR);
		LCDDriver_drawRectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? BG_COLOR : FG_COLOR);
		if(!SD_PlayInProcess)
		{
			LCDDriver_getTextBounds("Play WAV", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
			LCDDriver_printTextFont("Play WAV", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
		}
		else
		{
			LCDDriver_getTextBounds("Playing...", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
			LCDDriver_printTextFont("Playing...", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
		}
		button_y += button_h + margin;
		if(button_active)
			current_dialog_action = FILMAN_ACT_PLAYWAV;
		print_index++;
	}
	//flash bin
	if(allow_flash_bin)
	{
		button_active = (FILEMANAGER_dialog_button_index == print_index);
		LCDDriver_Fill_RectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? FG_COLOR : BG_COLOR);
		LCDDriver_drawRectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? BG_COLOR : FG_COLOR);
		LCDDriver_getTextBounds("Flash STM32 firmware", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
		LCDDriver_printTextFont("Flash STM32 firmware", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
		button_y += button_h + margin;
		if(button_active)
			current_dialog_action = FILMAN_ACT_FLASHBIN;
		print_index++;
	}
	//flash jic
	if(allow_flash_jic)
	{
		button_active = (FILEMANAGER_dialog_button_index == print_index);
		LCDDriver_Fill_RectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? FG_COLOR : BG_COLOR);
		LCDDriver_drawRectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? BG_COLOR : FG_COLOR);
		LCDDriver_getTextBounds("Flash FPGA firmware", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
		LCDDriver_printTextFont("Flash FPGA firmware", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
		button_y += button_h + margin;
		if(button_active)
			current_dialog_action = FILMAN_ACT_FLASHJIC;
		print_index++;
	}
	//delete
	button_active = (FILEMANAGER_dialog_button_index == print_index);
	LCDDriver_Fill_RectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? FG_COLOR : BG_COLOR);
	LCDDriver_drawRectXY(button_x, button_y, LCD_WIDTH - margin * 2, button_y + button_h, button_active ? BG_COLOR : FG_COLOR);
	LCDDriver_getTextBounds("Delete", button_x, button_y, &bounds_x, &bounds_y, &bounds_w, &bounds_h, &FreeSans9pt7b);
	LCDDriver_printTextFont("Delete", button_x + button_w / 2 - bounds_w / 2, button_y + button_h / 2 + bounds_h / 2, button_active ? BG_COLOR : FG_COLOR, button_active ? FG_COLOR : BG_COLOR, &FreeSans9pt7b);
	button_y += button_h + margin;
	if(button_active)
			current_dialog_action = FILMAN_ACT_DELETE;
	print_index++;
}

static void FILEMANAGER_DialogAction(void)
{
	if(SD_PlayInProcess)
			SD_NeedStopPlay = true;
	
	if(current_dialog_action == FILMAN_ACT_CANCEL) //back
	{
		FILEMANAGER_dialog_opened = false;
		FILEMANAGER_Refresh();
		return;
	}
	if(current_dialog_action == FILMAN_ACT_DELETE) //delete
	{
		if(!SD_CommandInProcess)
		{
			dma_memset(SD_workbuffer_A, 0, sizeof(SD_workbuffer_A));
			if(strlen(FILEMANAGER_CurrentPath) > 0)
			{
				strcat((char*)SD_workbuffer_A, FILEMANAGER_CurrentPath);
				strcat((char*)SD_workbuffer_A, "/");
			}
			strcat((char*)SD_workbuffer_A, FILEMANAGER_LISTING[current_index - 1]);
			FILEMANAGER_dialog_opened = false;
			current_index--;
			SD_doCommand(SDCOMM_DELETE_FILE, false);
		}
		return;
	}
	if(current_dialog_action == FILMAN_ACT_PLAYWAV) //play WAV
	{
		if(SD_PlayInProcess)
		{
			SD_NeedStopPlay = true;
			return;
		}
		
		println("Play WAV started");
		dma_memset(SD_workbuffer_A, 0, sizeof(SD_workbuffer_A));
		if(strlen(FILEMANAGER_CurrentPath) > 0)
		{
			strcat((char*)SD_workbuffer_A, FILEMANAGER_CurrentPath);
			strcat((char*)SD_workbuffer_A, "/");
		}
		strcat((char*)SD_workbuffer_A, FILEMANAGER_LISTING[current_index - 1]);
		SD_doCommand(SDCOMM_START_PLAY, false);
		return;
	}
	if(current_dialog_action == FILMAN_ACT_FLASHBIN) //flash stm32 bin firmware
	{
		println("[FLASH] BIN flashing started");
		TRX_Mute = true;
		dma_memset(SD_workbuffer_A, 0, sizeof(SD_workbuffer_A));
		if(strlen(FILEMANAGER_CurrentPath) > 0)
		{
			strcat((char*)SD_workbuffer_A, FILEMANAGER_CurrentPath);
			strcat((char*)SD_workbuffer_A, "/");
		}
		strcat((char*)SD_workbuffer_A, FILEMANAGER_LISTING[current_index - 1]);
		SD_doCommand(SDCOMM_FLASH_BIN, false);
		return;
	}
	if(current_dialog_action == FILMAN_ACT_FLASHJIC) //flash fpga jic firmware
	{
		println("[FLASH] JIC flashing started");
		TRX_Mute = true;
		dma_memset(SD_workbuffer_A, 0, sizeof(SD_workbuffer_A));
		if(strlen(FILEMANAGER_CurrentPath) > 0)
		{
			strcat((char*)SD_workbuffer_A, FILEMANAGER_CurrentPath);
			strcat((char*)SD_workbuffer_A, "/");
		}
		strcat((char*)SD_workbuffer_A, FILEMANAGER_LISTING[current_index - 1]);
		SD_doCommand(SDCOMM_FLASH_JIC, false);
		return;
	}
}

void FILEMANAGER_OTAUpdate_handler(void)
{
	static bool downloaded_fpga_fw = false;
	static bool downloaded_fpga_crc = false;
	static bool downloaded_stm_fw = false;
	static bool downloaded_stm_crc = false;
	
	sysmenu_ota_opened = true;
	if(sysmenu_ota_opened_state == 0)
	{
		if(WIFI_State != WIFI_READY)
		{
			LCD_showInfo("WIFI not ready", true);
			sysmenu_ota_opened = false;
			return;
		}
		if(!SD_Present || SD_RecordInProcess || SD_PlayInProcess || SD_CommandInProcess)
		{
			LCD_showInfo("SD not ready", true);
			sysmenu_ota_opened = false;
			return;
		}
		if(!WIFI_NewFW_checked)
		{
			WIFI_checkFWUpdates();
			LCD_showInfo("Checking updates", false);
			LCD_UpdateQuery.SystemMenuRedraw = true;
			return;
		}
		if(!WIFI_NewFW_STM32 && !WIFI_NewFW_FPGA)
		{
			LCD_showInfo("No updates", true);
			sysmenu_ota_opened = false;
			LCD_UpdateQuery.SystemMenuRedraw = true;
			return;
		}
		//delete old files
		LCD_showInfo("Clean old files...", false);
		strcpy((char*)SD_workbuffer_A, "firmware_stm32.bin");
		f_unlink((TCHAR*)SD_workbuffer_A);
		f_unlink((TCHAR*)SD_workbuffer_A);
		strcpy((char*)SD_workbuffer_A, "firmware_stm32.crc");
		f_unlink((TCHAR*)SD_workbuffer_A);
		f_unlink((TCHAR*)SD_workbuffer_A);
		strcpy((char*)SD_workbuffer_A, "firmware_fpga.jic");
		f_unlink((TCHAR*)SD_workbuffer_A);
		f_unlink((TCHAR*)SD_workbuffer_A);
		strcpy((char*)SD_workbuffer_A, "firmware_fpga.crc");
		f_unlink((TCHAR*)SD_workbuffer_A);
		f_unlink((TCHAR*)SD_workbuffer_A);
		downloaded_fpga_fw = false;
		downloaded_fpga_crc = false;
		downloaded_stm_fw = false;
		downloaded_stm_crc = false;
		if(WIFI_NewFW_FPGA)
			sysmenu_ota_opened_state = 1;
		else
			sysmenu_ota_opened_state = 5;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		return;
	}
	//config
	char url[128] = {0};
	//downloading FPGA FW
	if(sysmenu_ota_opened_state == 1 && WIFI_NewFW_FPGA && !downloaded_fpga_fw)
	{
		LCD_showInfo("Downloading FPGA FW to SD", false);
		sysmenu_ota_opened_state = 2;
		sprintf(url, "/trx_services/get_fw.php?type=fpga&lcd=%s&front=%s&touch=%s&tangent=%s", ota_config_lcd, ota_config_frontpanel, ota_config_touchpad, ota_config_tangent);
		WIFI_downloadFileToSD(url, "firmware_fpga.jic");
		return;
	}
	if(sysmenu_ota_opened_state == 2 && WIFI_downloadFileToSD_compleated)
	{
		LCD_showInfo("FPGA FW downloaded", true);
		downloaded_fpga_fw = true;
		sysmenu_ota_opened_state = 3;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		return;
	}
	//downloading FPGA CRC
	if(sysmenu_ota_opened_state == 3 && WIFI_NewFW_FPGA && !downloaded_fpga_crc)
	{
		LCD_showInfo("Downloading FPGA CRC to SD", false);
		sysmenu_ota_opened_state = 4;
		sprintf(url, "/trx_services/get_fw.php?type=fpga&crc&lcd=%s&front=%s&touch=%s&tangent=%s", ota_config_lcd, ota_config_frontpanel, ota_config_touchpad, ota_config_tangent);
		WIFI_downloadFileToSD(url, "firmware_fpga.crc");
		return;
	}
	if(sysmenu_ota_opened_state == 4 && WIFI_downloadFileToSD_compleated)
	{
		LCD_showInfo("FPGA CRC downloaded", true);
		downloaded_fpga_crc = true;
		if(WIFI_NewFW_STM32)
			sysmenu_ota_opened_state = 5;
		else
			sysmenu_ota_opened_state = 9;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		return;
	}
	//downloading STM32 FW
	if(sysmenu_ota_opened_state == 5 && WIFI_NewFW_STM32 && !downloaded_stm_fw)
	{
		LCD_showInfo("Downloading STM32 FW to SD", false);
		sysmenu_ota_opened_state = 6;
		sprintf(url, "/trx_services/get_fw.php?type=stm32&lcd=%s&front=%s&touch=%s&tangent=%s", ota_config_lcd, ota_config_frontpanel, ota_config_touchpad, ota_config_tangent);
		WIFI_downloadFileToSD(url, "firmware_stm32.bin");
		return;
	}
	if(sysmenu_ota_opened_state == 6 && WIFI_downloadFileToSD_compleated)
	{
		LCD_showInfo("STM32 FW downloaded", true);
		downloaded_stm_fw = true;
		sysmenu_ota_opened_state = 7;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		return;
	}
	//downloading STM32 CRC
	if(sysmenu_ota_opened_state == 7 && WIFI_NewFW_STM32 && !downloaded_stm_crc)
	{
		LCD_showInfo("Downloading STM32 CRC to SD", false);
		sysmenu_ota_opened_state = 8;
		sprintf(url, "/trx_services/get_fw.php?type=stm32&crc&lcd=%s&front=%s&touch=%s&tangent=%s", ota_config_lcd, ota_config_frontpanel, ota_config_touchpad, ota_config_tangent);
		WIFI_downloadFileToSD(url, "firmware_stm32.crc");
		return;
	}
	if(sysmenu_ota_opened_state == 8 && WIFI_downloadFileToSD_compleated)
	{
		LCD_showInfo("STM32 CRC downloaded", true);
		downloaded_stm_crc = true;
		if(WIFI_NewFW_FPGA)
			sysmenu_ota_opened_state = 9;
		else
			sysmenu_ota_opened_state = 10;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		return;
	}
	//Check CRC
	if(sysmenu_ota_opened_state == 9) //FPGA
	{
		LCD_showInfo("Check FPGA FW CRC", true);
		
		uint32_t FileCRCValue = 0;
		uint32_t NeedCRCValue = 0;
		
		hcrc.Instance = CRC;
		hcrc.Init.DefaultPolynomialUse    = DEFAULT_POLYNOMIAL_ENABLE;
		hcrc.Init.DefaultInitValueUse     = DEFAULT_INIT_VALUE_ENABLE;
		hcrc.Init.InputDataInversionMode  = CRC_INPUTDATA_INVERSION_NONE;
		hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
		hcrc.InputDataFormat              = CRC_INPUTDATA_FORMAT_BYTES;
		HAL_CRC_Init(&hcrc);
		
    //FILINFO FileInfo;
    //f_stat("firmware_fpga.jic", &FileInfo);
		//println("Filesize: ", FileInfo.fsize);
		
		if (f_open(&File, "firmware_fpga.jic", FA_READ | FA_OPEN_EXISTING) == FR_OK)
		{
			__HAL_CRC_DR_RESET(&hcrc);
			uint32_t bytesreaded;
			uint32_t bytesprocessed;
			bool read_flag = true;
			while(read_flag)
			{
				if(f_read(&File, &SD_workbuffer_A, sizeof(SD_workbuffer_A), &bytesreaded) != FR_OK || bytesreaded == 0)
				{
					read_flag = false;
				}
				else
				{
					bytesprocessed += bytesreaded;
					FileCRCValue = __REV(~HAL_CRC_Accumulate(&hcrc, (uint32_t *)SD_workbuffer_A, bytesreaded));
				}
			}
			f_close(&File);
			
			//read original CRC
			f_open(&File, "firmware_fpga.crc", FA_READ | FA_OPEN_EXISTING);
			dma_memset(SD_workbuffer_A, 0x00, sizeof(SD_workbuffer_A));
			f_read(&File, &SD_workbuffer_A, sizeof(SD_workbuffer_A), &bytesreaded);
			f_close(&File);
			println("Need CRC: ", (char*)SD_workbuffer_A);
			
			//compare
			char tmp[16] = {0};
			sprintf(tmp, "%u", FileCRCValue);
			println("File CRC: ", tmp);
			if(strstr((char*)SD_workbuffer_A, tmp) != NULL)
			{
				LCD_showInfo("CRC OK", true);
				
				if(WIFI_NewFW_STM32)
					sysmenu_ota_opened_state = 10;
				else
					sysmenu_ota_opened_state = 15;
			}
			else
			{
				LCD_showInfo("CRC ERROR", true);
				sysmenu_ota_opened_state = 1;
				downloaded_fpga_fw = false;
				LCD_UpdateQuery.SystemMenuRedraw = true;
				return;
			}
		}
		else
		{
			sysmenu_ota_opened_state = 1;
			downloaded_fpga_fw = false;
			LCD_UpdateQuery.SystemMenuRedraw = true;
			return;
		}
	}
	if(sysmenu_ota_opened_state == 10) //STM32
	{
		LCD_showInfo("Check STM32 FW CRC", true);
		
		uint32_t FileCRCValue = 0;
		uint32_t NeedCRCValue = 0;
		
		hcrc.Instance = CRC;
		hcrc.Init.DefaultPolynomialUse    = DEFAULT_POLYNOMIAL_ENABLE;
		hcrc.Init.DefaultInitValueUse     = DEFAULT_INIT_VALUE_ENABLE;
		hcrc.Init.InputDataInversionMode  = CRC_INPUTDATA_INVERSION_NONE;
		hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
		hcrc.InputDataFormat              = CRC_INPUTDATA_FORMAT_BYTES;
		HAL_CRC_Init(&hcrc);
		
    //FILINFO FileInfo;
    //f_stat("firmware_fpga.jic", &FileInfo);
		//println(FileInfo.fsize);
		
		if (f_open(&File, "firmware_stm32.bin", FA_READ | FA_OPEN_EXISTING) == FR_OK)
		{
			__HAL_CRC_DR_RESET(&hcrc);
			uint32_t bytesreaded;
			uint32_t bytesprocessed;
			bool read_flag = true;
			while(read_flag)
			{
				if(f_read(&File, &SD_workbuffer_A, sizeof(SD_workbuffer_A), &bytesreaded) != FR_OK || bytesreaded == 0)
				{
					read_flag = false;
				}
				else
				{
					bytesprocessed += bytesreaded;
					FileCRCValue = __REV(~HAL_CRC_Accumulate(&hcrc, (uint32_t *)SD_workbuffer_A, bytesreaded));
				}
			}
			f_close(&File);
			
			//read original CRC
			f_open(&File, "firmware_stm32.crc", FA_READ | FA_OPEN_EXISTING);
			dma_memset(SD_workbuffer_A, 0x00, sizeof(SD_workbuffer_A));
			f_read(&File, &SD_workbuffer_A, sizeof(SD_workbuffer_A), &bytesreaded);
			f_close(&File);
			println("Need CRC: ", (char*)SD_workbuffer_A);
			
			//compare
			char tmp[16] = {0};
			sprintf(tmp, "%u", FileCRCValue);
			println("File CRC: ", tmp);
			if(strstr((char*)SD_workbuffer_A, tmp) != NULL)
			{
				LCD_showInfo("CRC OK", true);
				sysmenu_ota_opened_state = 15;
			}
			else
			{
				LCD_showInfo("CRC ERROR", true);
				sysmenu_ota_opened_state = 5;
				downloaded_fpga_fw = false;
				LCD_UpdateQuery.SystemMenuRedraw = true;
				return;
			}
		}
		else
		{
			sysmenu_ota_opened_state = 5;
			downloaded_fpga_fw = false;
			LCD_UpdateQuery.SystemMenuRedraw = true;
			return;
		}
	}
	//flash
	if(sysmenu_ota_opened_state == 15)
	{
		LCD_showInfo("Flashing", true);
		if(WIFI_NewFW_FPGA && WIFI_NewFW_STM32)
		{
			TRX_Mute = true;
			strcpy((char*)SD_workbuffer_A, "firmware_fpga.jic");
			SDCOMM_FLASH_JIC_handler(false);
			strcpy((char*)SD_workbuffer_A, "firmware_stm32.bin");
			SDCOMM_FLASH_BIN_handler();
		}
		else if(WIFI_NewFW_FPGA)
		{
			TRX_Mute = true;
			strcpy((char*)SD_workbuffer_A, "firmware_fpga.jic");
			SDCOMM_FLASH_JIC_handler(true);
		}
		else if(WIFI_NewFW_STM32)
		{
			TRX_Mute = true;
			strcpy((char*)SD_workbuffer_A, "firmware_stm32.bin");
			SDCOMM_FLASH_BIN_handler();
		}
			
		sysmenu_ota_opened_state = 16;
	}
	//finish
	if(sysmenu_ota_opened_state == 16)
	{
		LCD_showInfo("Finished", true);
		
		sysmenu_ota_opened = false;
		sysmenu_ota_opened_state = 0;
		LCD_UpdateQuery.SystemMenuRedraw = true;
		SYSMENU_eventCloseAllSystemMenu();
	}
}
