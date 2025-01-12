#include "screen_layout.h"
#include "lcd_driver.h"
#include "fonts.h"

#if (defined(LAY_800x480))

extern "C" constexpr STRUCT_LAYOUT_THEME LAYOUT_THEMES[LAYOUT_THEMES_COUNT] =
	{
		//Default
		{
			.TOPBUTTONS_X1 = 0,
			.TOPBUTTONS_X2 = (LCD_WIDTH - 1),
			.TOPBUTTONS_Y1 = 95,
			.TOPBUTTONS_COUNT = 11,
			.TOPBUTTONS_WIDTH = (float32_t)((float32_t)LCD_WIDTH / (float32_t)LAYOUT_THEMES[0].TOPBUTTONS_COUNT),
			.TOPBUTTONS_HEIGHT = 50,
			.TOPBUTTONS_PRE_X = (float32_t)LAYOUT_THEMES[0].TOPBUTTONS_X1,
			.TOPBUTTONS_PRE_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_ATT_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_PRE_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_ATT_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_PGA_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_ATT_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_PGA_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_DRV_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_PGA_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_DRV_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_AGC_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_DRV_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_AGC_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_DNR_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_AGC_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_DNR_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_NB_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_DNR_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_NB_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_NOTCH_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_NB_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_NOTCH_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_SQL_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_NOTCH_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_SQL_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_FAST_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_SQL_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_FAST_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_MUTE_X = (float32_t)(LAYOUT_THEMES[0].TOPBUTTONS_FAST_X + LAYOUT_THEMES[0].TOPBUTTONS_WIDTH),
			.TOPBUTTONS_MUTE_Y = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			//clock
			.CLOCK_POS_Y = 17,
			.CLOCK_POS_HRS_X = (LCD_WIDTH - 75),
			.CLOCK_POS_MIN_X = (uint16_t)(LAYOUT_THEMES[0].CLOCK_POS_HRS_X + 25),
			.CLOCK_POS_SEC_X = (uint16_t)(LAYOUT_THEMES[0].CLOCK_POS_MIN_X + 25),
			.CLOCK_FONT = &FreeSans9pt7b,
			//WIFI
			.STATUS_WIFI_ICON_X = (LCD_WIDTH - 98),
			.STATUS_WIFI_ICON_Y = 3,
			//SD
			.STATUS_SD_ICON_X = (LCD_WIDTH - 98 - 18),
			.STATUS_SD_ICON_Y = 3,
			// frequency output VFO-A
			.FREQ_A_LEFT = 0,
			.FREQ_X_OFFSET_100 = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 37),
			.FREQ_X_OFFSET_10 = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 73),
			.FREQ_X_OFFSET_1 = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 113),
			.FREQ_X_OFFSET_KHZ = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 170),
			.FREQ_X_OFFSET_HZ = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 307),
			.FREQ_HEIGHT = 51,
			.FREQ_WIDTH = 370,
			.FREQ_TOP_OFFSET = 4,
			.FREQ_LEFT_MARGIN = 37,
			.FREQ_RIGHT_MARGIN = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[0].FREQ_LEFT_MARGIN - LAYOUT_THEMES[0].FREQ_WIDTH),
			.FREQ_BOTTOM_OFFSET = 8,
			.FREQ_BLOCK_HEIGHT = (uint16_t)(LAYOUT_THEMES[0].FREQ_HEIGHT + LAYOUT_THEMES[0].FREQ_TOP_OFFSET + LAYOUT_THEMES[0].FREQ_BOTTOM_OFFSET),
			.FREQ_Y_TOP = 0,
			.FREQ_Y_BASELINE = (uint16_t)(LAYOUT_THEMES[0].FREQ_Y_TOP + LAYOUT_THEMES[0].FREQ_HEIGHT + LAYOUT_THEMES[0].FREQ_TOP_OFFSET),
			.FREQ_Y_BASELINE_SMALL = (uint16_t)(LAYOUT_THEMES[0].FREQ_Y_BASELINE - 2),
			.FREQ_FONT = &FreeSans36pt7b,
			.FREQ_SMALL_FONT = &Quito32pt7b,
			.FREQ_DELIMITER_Y_OFFSET = 0,
			.FREQ_DELIMITER_X1_OFFSET = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 151),
			.FREQ_DELIMITER_X2_OFFSET = (uint16_t)(LAYOUT_THEMES[0].FREQ_A_LEFT + 287),
			// frequency output VFO-B
			.FREQ_B_LEFT = (LCD_WIDTH - 375),
			.FREQ_B_X_OFFSET_100 = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 37),
			.FREQ_B_X_OFFSET_10 = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 73),
			.FREQ_B_X_OFFSET_1 = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 105),
			.FREQ_B_X_OFFSET_KHZ = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 153),
			.FREQ_B_X_OFFSET_HZ = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 268),
			.FREQ_B_HEIGHT = 51,
			.FREQ_B_WIDTH = 288,
			.FREQ_B_TOP_OFFSET = 4,
			.FREQ_B_LEFT_MARGIN = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 37),
			.FREQ_B_RIGHT_MARGIN = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[0].FREQ_B_LEFT_MARGIN - LAYOUT_THEMES[0].FREQ_B_WIDTH),
			.FREQ_B_BOTTOM_OFFSET = 8,
			.FREQ_B_BLOCK_HEIGHT = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_HEIGHT + LAYOUT_THEMES[0].FREQ_B_TOP_OFFSET + LAYOUT_THEMES[0].FREQ_B_BOTTOM_OFFSET),
			.FREQ_B_Y_TOP = 0,
			.FREQ_B_Y_BASELINE = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_Y_TOP + LAYOUT_THEMES[0].FREQ_B_HEIGHT + LAYOUT_THEMES[0].FREQ_B_TOP_OFFSET),
			.FREQ_B_Y_BASELINE_SMALL = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_Y_BASELINE - 2),
			.FREQ_B_FONT = &FreeSans32pt7b,
			.FREQ_B_SMALL_FONT = &FreeSans18pt7b,
			.FREQ_B_DELIMITER_Y_OFFSET = 0,
			.FREQ_B_DELIMITER_X1_OFFSET = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 142),
			.FREQ_B_DELIMITER_X2_OFFSET = (uint16_t)(LAYOUT_THEMES[0].FREQ_B_LEFT + 256),
			// display statuses under frequency
			.STATUS_Y_OFFSET = (uint16_t)(LAYOUT_THEMES[0].FREQ_Y_TOP + LAYOUT_THEMES[0].FREQ_BLOCK_HEIGHT + 1),
			.STATUS_HEIGHT = 30,
			.STATUS_BAR_X_OFFSET = 60,
			.STATUS_BAR_Y_OFFSET = 16,
			.STATUS_BAR_HEIGHT = 10,
			.STATUS_TXRX_X_OFFSET = 3,
			.STATUS_TXRX_Y_OFFSET = -50,
			.STATUS_TXRX_FONT = &FreeSans9pt7b,
			.STATUS_VFO_X_OFFSET = 0,
			.STATUS_VFO_Y_OFFSET = -43,
			.STATUS_VFO_BLOCK_WIDTH = 37,
			.STATUS_VFO_BLOCK_HEIGHT = 22,
			.STATUS_ANT_X_OFFSET = 0,
			.STATUS_ANT_Y_OFFSET = -23,
			.STATUS_ANT_BLOCK_WIDTH = 37,
			.STATUS_ANT_BLOCK_HEIGHT = 22,
			.STATUS_TX_LABELS_OFFSET_X = 5,
			.STATUS_TX_LABELS_MARGIN_X = 55,
			.STATUS_SMETER_ANALOG = false,
			.STATUS_SMETER_TOP_OFFSET = 0,
			.STATUS_SMETER_ANALOG_HEIGHT = 0,
			.STATUS_SMETER_WIDTH = 282,
			.STATUS_SMETER_MARKER_HEIGHT = 25,
			.STATUS_PMETER_WIDTH = 200,
			.STATUS_AMETER_WIDTH = 70,
			.STATUS_ALC_BAR_X_OFFSET = 10,
			.STATUS_LABELS_OFFSET_Y = 0,
			.STATUS_LABELS_FONT_SIZE = 1,
			.STATUS_LABEL_S_VAL_X_OFFSET = 10,
			.STATUS_LABEL_S_VAL_Y_OFFSET = 10,
			.STATUS_LABEL_S_VAL_FONT = &FreeSans7pt7b,
			.STATUS_LABEL_DBM_X_OFFSET = 5,
			.STATUS_LABEL_DBM_Y_OFFSET = 20,
			.STATUS_LABEL_BW_X_OFFSET = 457,
			.STATUS_LABEL_BW_Y_OFFSET = 20,
			.STATUS_LABEL_RIT_X_OFFSET = 457,
			.STATUS_LABEL_RIT_Y_OFFSET = 5,
			.STATUS_LABEL_THERM_X_OFFSET = 532,
			.STATUS_LABEL_THERM_Y_OFFSET = 20,
			.STATUS_LABEL_NOTCH_X_OFFSET = 650,
			.STATUS_LABEL_NOTCH_Y_OFFSET = 20,
			.STATUS_LABEL_FFT_BW_X_OFFSET = 740,
			.STATUS_LABEL_FFT_BW_Y_OFFSET = 20,
			.STATUS_LABEL_CPU_X_OFFSET = 532,
			.STATUS_LABEL_CPU_Y_OFFSET = 5,
			.STATUS_LABEL_AUTOGAIN_X_OFFSET = 650,
			.STATUS_LABEL_AUTOGAIN_Y_OFFSET = 5,
			.STATUS_LABEL_LOCK_X_OFFSET = 740,
			.STATUS_LABEL_LOCK_Y_OFFSET = 5,
			.STATUS_LABEL_REC_X_OFFSET = 775,
			.STATUS_LABEL_REC_Y_OFFSET = 5,
			.STATUS_SMETER_PEAK_HOLDTIME = 1000,
			.STATUS_SMETER_TXLABELS_MARGIN = 55,
			.STATUS_SMETER_TXLABELS_PADDING = 23,
			.STATUS_TX_LABELS_VAL_WIDTH = 25,
			.STATUS_TX_LABELS_VAL_HEIGHT = 8,
			.STATUS_TX_LABELS_SWR_X = (uint16_t)(LAYOUT_THEMES[0].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[0].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_LABELS_FWD_X = (uint16_t)(LAYOUT_THEMES[0].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[0].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_MARGIN + LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_LABELS_REF_X = (uint16_t)(LAYOUT_THEMES[0].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[0].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_MARGIN * 2 + LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_ALC_X_OFFSET = 40,
			.STATUS_MODE_X_OFFSET = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[0].FREQ_RIGHT_MARGIN + 5),
			.STATUS_MODE_Y_OFFSET = -42,
			.STATUS_MODE_BLOCK_WIDTH = 48,
			.STATUS_MODE_BLOCK_HEIGHT = 22,
			.STATUS_MODE_B_X_OFFSET = (uint16_t)(LCD_WIDTH - (LCD_WIDTH - LAYOUT_THEMES[0].FREQ_B_LEFT_MARGIN - LAYOUT_THEMES[0].FREQ_B_WIDTH) + 4),
			.STATUS_MODE_B_Y_OFFSET = -30,
			.STATUS_ERR_OFFSET_X = (LCD_WIDTH - 40),
			.STATUS_ERR_OFFSET_Y = 25,
			.STATUS_ERR_WIDTH = 50,
			.STATUS_ERR_HEIGHT = 8,
			//text bar under wtf
			.TEXTBAR_FONT = 2,
			//bottom buttons
			.BOTTOM_BUTTONS_BLOCK_HEIGHT = 30,
			.BOTTOM_BUTTONS_BLOCK_TOP = (uint16_t)(LCD_HEIGHT - LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_HEIGHT),
			.BOTTOM_BUTTONS_COUNT = 8,
			.BOTTOM_BUTTONS_ARROWS_WIDTH = 32,
			.BOTTOM_BUTTONS_ONE_WIDTH = (uint16_t)((LCD_WIDTH - LAYOUT_THEMES[0].BOTTOM_BUTTONS_ARROWS_WIDTH * 2) / LAYOUT_THEMES[0].BOTTOM_BUTTONS_COUNT),
			// FFT and waterfall
			.FFT_HEIGHT_STYLE1 = 95,
			.WTF_HEIGHT_STYLE1 = 195,
			.FFT_HEIGHT_STYLE2 = 145,
			.WTF_HEIGHT_STYLE2 = 145,
			.FFT_HEIGHT_STYLE3 = 165,
			.WTF_HEIGHT_STYLE3 = 125,
			.FFT_PRINT_SIZE = LCD_WIDTH,
			.FFT_CWDECODER_OFFSET = 17,
			.FFT_FFTWTF_POS_Y = (uint16_t)(LCD_HEIGHT - LAYOUT_THEMES[0].FFT_HEIGHT_STYLE1 - LAYOUT_THEMES[0].WTF_HEIGHT_STYLE1 - LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_HEIGHT),
			.FFT_FFTWTF_BOTTOM = (uint16_t)(LAYOUT_THEMES[0].FFT_FFTWTF_POS_Y + LAYOUT_THEMES[0].FFT_HEIGHT_STYLE1 + LAYOUT_THEMES[0].WTF_HEIGHT_STYLE1),
			.FFT_FREQLABELS_HEIGHT = 10,
			// system menu
			.SYSMENU_X1 = 5,
			.SYSMENU_X2 = 400,
			.SYSMENU_W = 458,
			.SYSMENU_ITEM_HEIGHT = 18,
			.SYSMENU_MAX_ITEMS_ON_PAGE = (uint16_t)(LCD_HEIGHT / LAYOUT_THEMES[0].SYSMENU_ITEM_HEIGHT),
			//Tooltip
			.TOOLTIP_TIMEOUT = 1000,
			.TOOLTIP_MARGIN = 5,
			.TOOLTIP_POS_X = (LCD_WIDTH / 4),
			.TOOLTIP_POS_Y = 15,
			//BW Trapezoid
			.BW_TRAPEZ_POS_X = 352,
			.BW_TRAPEZ_POS_Y = 65,
			.BW_TRAPEZ_HEIGHT = 25,
			.BW_TRAPEZ_WIDTH = 96,
			//Touch buttons layout
			.BUTTON_PADDING = 1,
			.BUTTON_LIGHTER_WIDTH = 0.4f,
			.BUTTON_LIGHTER_HEIGHT = 4,
			//Windows
			.WINDOWS_BUTTON_WIDTH = 80,
			.WINDOWS_BUTTON_HEIGHT = 50,
			.WINDOWS_BUTTON_MARGIN = 10,
		},
		//analog meter
		{
			.TOPBUTTONS_X1 = LAYOUT_THEMES[0].TOPBUTTONS_X1,
			.TOPBUTTONS_X2 = LAYOUT_THEMES[0].TOPBUTTONS_X2,
			.TOPBUTTONS_Y1 = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_COUNT = LAYOUT_THEMES[0].TOPBUTTONS_COUNT,
			.TOPBUTTONS_WIDTH = LAYOUT_THEMES[0].TOPBUTTONS_WIDTH,
			.TOPBUTTONS_HEIGHT = LAYOUT_THEMES[0].TOPBUTTONS_HEIGHT,
			.TOPBUTTONS_PRE_X = LAYOUT_THEMES[0].TOPBUTTONS_PRE_X,
			.TOPBUTTONS_PRE_Y = LAYOUT_THEMES[0].TOPBUTTONS_PRE_Y,
			.TOPBUTTONS_ATT_X = LAYOUT_THEMES[0].TOPBUTTONS_ATT_X,
			.TOPBUTTONS_ATT_Y = LAYOUT_THEMES[0].TOPBUTTONS_ATT_Y,
			.TOPBUTTONS_PGA_X = LAYOUT_THEMES[0].TOPBUTTONS_PGA_X,
			.TOPBUTTONS_PGA_Y = LAYOUT_THEMES[0].TOPBUTTONS_PGA_Y,
			.TOPBUTTONS_DRV_X = LAYOUT_THEMES[0].TOPBUTTONS_DRV_X,
			.TOPBUTTONS_DRV_Y = LAYOUT_THEMES[0].TOPBUTTONS_DRV_Y,
			.TOPBUTTONS_AGC_X = LAYOUT_THEMES[0].TOPBUTTONS_AGC_X,
			.TOPBUTTONS_AGC_Y = LAYOUT_THEMES[0].TOPBUTTONS_AGC_Y,
			.TOPBUTTONS_DNR_X = LAYOUT_THEMES[0].TOPBUTTONS_DNR_X,
			.TOPBUTTONS_DNR_Y = LAYOUT_THEMES[0].TOPBUTTONS_DNR_Y,
			.TOPBUTTONS_NB_X = LAYOUT_THEMES[0].TOPBUTTONS_NB_X,
			.TOPBUTTONS_NB_Y = LAYOUT_THEMES[0].TOPBUTTONS_NB_Y,
			.TOPBUTTONS_NOTCH_X = LAYOUT_THEMES[0].TOPBUTTONS_NOTCH_X,
			.TOPBUTTONS_NOTCH_Y = LAYOUT_THEMES[0].TOPBUTTONS_NOTCH_Y,
			.TOPBUTTONS_SQL_X = LAYOUT_THEMES[0].TOPBUTTONS_SQL_X,
			.TOPBUTTONS_SQL_Y = LAYOUT_THEMES[0].TOPBUTTONS_SQL_Y,
			.TOPBUTTONS_FAST_X = LAYOUT_THEMES[0].TOPBUTTONS_FAST_X,
			.TOPBUTTONS_FAST_Y = LAYOUT_THEMES[0].TOPBUTTONS_FAST_Y,
			.TOPBUTTONS_MUTE_X = LAYOUT_THEMES[0].TOPBUTTONS_MUTE_X,
			.TOPBUTTONS_MUTE_Y = LAYOUT_THEMES[0].TOPBUTTONS_MUTE_Y,
			//clock
			.CLOCK_POS_Y = LAYOUT_THEMES[0].CLOCK_POS_Y,
			.CLOCK_POS_HRS_X = LAYOUT_THEMES[0].CLOCK_POS_HRS_X,
			.CLOCK_POS_MIN_X = LAYOUT_THEMES[0].CLOCK_POS_MIN_X,
			.CLOCK_POS_SEC_X = LAYOUT_THEMES[0].CLOCK_POS_SEC_X,
			.CLOCK_FONT = LAYOUT_THEMES[0].CLOCK_FONT,
			//WIFI
			.STATUS_WIFI_ICON_X = LAYOUT_THEMES[0].STATUS_WIFI_ICON_X,
			.STATUS_WIFI_ICON_Y = LAYOUT_THEMES[0].STATUS_WIFI_ICON_Y,
			//SD
			.STATUS_SD_ICON_X = LAYOUT_THEMES[0].STATUS_SD_ICON_X,
			.STATUS_SD_ICON_Y = LAYOUT_THEMES[0].STATUS_SD_ICON_Y,
			// frequency output VFO-A
			.FREQ_A_LEFT = 245,
			.FREQ_X_OFFSET_100 = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 36),
			.FREQ_X_OFFSET_10 = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 59),
			.FREQ_X_OFFSET_1 = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 89),
			.FREQ_X_OFFSET_KHZ = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 123),
			.FREQ_X_OFFSET_HZ = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 210),
			.FREQ_HEIGHT = 51,
			.FREQ_WIDTH = 225,
			.FREQ_TOP_OFFSET = 4,
			.FREQ_LEFT_MARGIN = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 37),
			.FREQ_RIGHT_MARGIN = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[1].FREQ_LEFT_MARGIN - LAYOUT_THEMES[1].FREQ_WIDTH),
			.FREQ_BOTTOM_OFFSET = 8,
			.FREQ_BLOCK_HEIGHT = (uint16_t)(LAYOUT_THEMES[1].FREQ_HEIGHT + LAYOUT_THEMES[1].FREQ_TOP_OFFSET + LAYOUT_THEMES[1].FREQ_BOTTOM_OFFSET),
			.FREQ_Y_TOP = 0,
			.FREQ_Y_BASELINE = (uint16_t)(LAYOUT_THEMES[1].FREQ_Y_TOP + LAYOUT_THEMES[1].FREQ_HEIGHT + LAYOUT_THEMES[1].FREQ_TOP_OFFSET),
			.FREQ_Y_BASELINE_SMALL = (uint16_t)(LAYOUT_THEMES[1].FREQ_Y_BASELINE - 0),
			.FREQ_FONT = &FreeSans24pt7b,
			.FREQ_SMALL_FONT = &FreeSans18pt7b,
			.FREQ_DELIMITER_Y_OFFSET = 0,
			.FREQ_DELIMITER_X1_OFFSET = (uint16_t)(LAYOUT_THEMES[1].FREQ_X_OFFSET_KHZ - 11),
			.FREQ_DELIMITER_X2_OFFSET = (uint16_t)(LAYOUT_THEMES[1].FREQ_X_OFFSET_HZ - 11),
			// frequency output VFO-B
			.FREQ_B_LEFT = (LCD_WIDTH - 315),
			.FREQ_B_X_OFFSET_100 = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 36),
			.FREQ_B_X_OFFSET_10 = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 59),
			.FREQ_B_X_OFFSET_1 = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 89),
			.FREQ_B_X_OFFSET_KHZ = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 123),
			.FREQ_B_X_OFFSET_HZ = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 210),
			.FREQ_B_HEIGHT = 51,
			.FREQ_B_WIDTH = 225,
			.FREQ_B_TOP_OFFSET = 4,
			.FREQ_B_LEFT_MARGIN = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_LEFT + 37),
			.FREQ_B_RIGHT_MARGIN = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[1].FREQ_B_LEFT_MARGIN - LAYOUT_THEMES[1].FREQ_B_WIDTH),
			.FREQ_B_BOTTOM_OFFSET = 8,
			.FREQ_B_BLOCK_HEIGHT = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_HEIGHT + LAYOUT_THEMES[1].FREQ_B_TOP_OFFSET + LAYOUT_THEMES[1].FREQ_B_BOTTOM_OFFSET),
			.FREQ_B_Y_TOP = 0,
			.FREQ_B_Y_BASELINE = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_Y_TOP + LAYOUT_THEMES[1].FREQ_B_HEIGHT + LAYOUT_THEMES[1].FREQ_B_TOP_OFFSET),
			.FREQ_B_Y_BASELINE_SMALL = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_Y_BASELINE - 0),
			.FREQ_B_FONT = &FreeSans24pt7b,
			.FREQ_B_SMALL_FONT = &FreeSans18pt7b,
			.FREQ_B_DELIMITER_Y_OFFSET = 0,
			.FREQ_B_DELIMITER_X1_OFFSET = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_X_OFFSET_KHZ - 11),
			.FREQ_B_DELIMITER_X2_OFFSET = (uint16_t)(LAYOUT_THEMES[1].FREQ_B_X_OFFSET_HZ - 11),
			// display statuses under frequency
			.STATUS_Y_OFFSET = LAYOUT_THEMES[0].STATUS_Y_OFFSET,
			.STATUS_HEIGHT = LAYOUT_THEMES[0].STATUS_HEIGHT,
			.STATUS_BAR_X_OFFSET = LAYOUT_THEMES[0].STATUS_BAR_X_OFFSET,
			.STATUS_BAR_Y_OFFSET = LAYOUT_THEMES[0].STATUS_BAR_Y_OFFSET,
			.STATUS_BAR_HEIGHT = LAYOUT_THEMES[0].STATUS_BAR_HEIGHT,
			.STATUS_TXRX_X_OFFSET = LAYOUT_THEMES[0].STATUS_TXRX_X_OFFSET,
			.STATUS_TXRX_Y_OFFSET = LAYOUT_THEMES[0].STATUS_TXRX_Y_OFFSET,
			.STATUS_TXRX_FONT = LAYOUT_THEMES[0].STATUS_TXRX_FONT,
			.STATUS_VFO_X_OFFSET = LAYOUT_THEMES[0].STATUS_VFO_X_OFFSET,
			.STATUS_VFO_Y_OFFSET = LAYOUT_THEMES[0].STATUS_VFO_Y_OFFSET,
			.STATUS_VFO_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_VFO_BLOCK_WIDTH,
			.STATUS_VFO_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_VFO_BLOCK_HEIGHT,
			.STATUS_ANT_X_OFFSET = LAYOUT_THEMES[0].STATUS_ANT_X_OFFSET,
			.STATUS_ANT_Y_OFFSET = LAYOUT_THEMES[0].STATUS_ANT_Y_OFFSET,
			.STATUS_ANT_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_ANT_BLOCK_WIDTH,
			.STATUS_ANT_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_ANT_BLOCK_HEIGHT,
			.STATUS_TX_LABELS_OFFSET_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_OFFSET_X,
			.STATUS_TX_LABELS_MARGIN_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_MARGIN_X,
			.STATUS_SMETER_ANALOG = true,
			.STATUS_SMETER_TOP_OFFSET = -60,
			.STATUS_SMETER_ANALOG_HEIGHT = 80,
			.STATUS_SMETER_WIDTH = 205,
			.STATUS_SMETER_MARKER_HEIGHT = LAYOUT_THEMES[0].STATUS_SMETER_MARKER_HEIGHT,
			.STATUS_PMETER_WIDTH = 120,
			.STATUS_AMETER_WIDTH = 70,
			.STATUS_ALC_BAR_X_OFFSET = LAYOUT_THEMES[0].STATUS_ALC_BAR_X_OFFSET,
			.STATUS_LABELS_OFFSET_Y = LAYOUT_THEMES[0].STATUS_LABELS_OFFSET_Y,
			.STATUS_LABELS_FONT_SIZE = LAYOUT_THEMES[0].STATUS_LABELS_FONT_SIZE,
			.STATUS_LABEL_S_VAL_X_OFFSET = 10,
			.STATUS_LABEL_S_VAL_Y_OFFSET = 20,
			.STATUS_LABEL_S_VAL_FONT = LAYOUT_THEMES[0].STATUS_LABEL_S_VAL_FONT,
			.STATUS_LABEL_DBM_X_OFFSET = 290,
			.STATUS_LABEL_DBM_Y_OFFSET = 10,
			.STATUS_LABEL_BW_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_BW_X_OFFSET,
			.STATUS_LABEL_BW_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_BW_Y_OFFSET,
			.STATUS_LABEL_RIT_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_RIT_X_OFFSET,
			.STATUS_LABEL_RIT_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_RIT_Y_OFFSET,
			.STATUS_LABEL_THERM_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_THERM_X_OFFSET,
			.STATUS_LABEL_THERM_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_THERM_Y_OFFSET,
			.STATUS_LABEL_NOTCH_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_NOTCH_X_OFFSET,
			.STATUS_LABEL_NOTCH_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_NOTCH_Y_OFFSET,
			.STATUS_LABEL_FFT_BW_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_FFT_BW_X_OFFSET,
			.STATUS_LABEL_FFT_BW_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_FFT_BW_Y_OFFSET,
			.STATUS_LABEL_CPU_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_CPU_X_OFFSET,
			.STATUS_LABEL_CPU_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_CPU_Y_OFFSET,
			.STATUS_LABEL_AUTOGAIN_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_AUTOGAIN_X_OFFSET,
			.STATUS_LABEL_AUTOGAIN_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_AUTOGAIN_Y_OFFSET,
			.STATUS_LABEL_LOCK_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_LOCK_X_OFFSET,
			.STATUS_LABEL_LOCK_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_LOCK_Y_OFFSET,
			.STATUS_LABEL_REC_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_REC_X_OFFSET,
			.STATUS_LABEL_REC_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_REC_Y_OFFSET,
			.STATUS_SMETER_PEAK_HOLDTIME = LAYOUT_THEMES[0].STATUS_SMETER_PEAK_HOLDTIME,
			.STATUS_SMETER_TXLABELS_MARGIN = LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_MARGIN,
			.STATUS_SMETER_TXLABELS_PADDING = LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_PADDING,
			.STATUS_TX_LABELS_VAL_WIDTH = LAYOUT_THEMES[0].STATUS_TX_LABELS_VAL_WIDTH,
			.STATUS_TX_LABELS_VAL_HEIGHT = LAYOUT_THEMES[0].STATUS_TX_LABELS_VAL_HEIGHT,
			.STATUS_TX_LABELS_SWR_X = (uint16_t)(LAYOUT_THEMES[1].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[1].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[1].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_LABELS_FWD_X = (uint16_t)(LAYOUT_THEMES[1].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[1].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[1].STATUS_SMETER_TXLABELS_MARGIN + LAYOUT_THEMES[1].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_LABELS_REF_X = (uint16_t)(LAYOUT_THEMES[1].STATUS_BAR_X_OFFSET + LAYOUT_THEMES[1].STATUS_TX_LABELS_OFFSET_X + LAYOUT_THEMES[1].STATUS_SMETER_TXLABELS_MARGIN * 2 + LAYOUT_THEMES[1].STATUS_SMETER_TXLABELS_PADDING),
			.STATUS_TX_ALC_X_OFFSET = LAYOUT_THEMES[0].STATUS_TX_ALC_X_OFFSET,
			.STATUS_MODE_X_OFFSET = (uint16_t)(LCD_WIDTH - LAYOUT_THEMES[1].FREQ_RIGHT_MARGIN - 50),
			.STATUS_MODE_Y_OFFSET = -62,
			.STATUS_MODE_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_MODE_BLOCK_WIDTH,
			.STATUS_MODE_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_MODE_BLOCK_HEIGHT,
			.STATUS_MODE_B_X_OFFSET = (uint16_t)(LCD_WIDTH - (LCD_WIDTH - LAYOUT_THEMES[1].FREQ_B_LEFT_MARGIN - LAYOUT_THEMES[1].FREQ_B_WIDTH) + 4),
			.STATUS_MODE_B_Y_OFFSET = LAYOUT_THEMES[0].STATUS_MODE_B_Y_OFFSET,
			.STATUS_ERR_OFFSET_X = LAYOUT_THEMES[0].STATUS_ERR_OFFSET_X,
			.STATUS_ERR_OFFSET_Y = LAYOUT_THEMES[0].STATUS_ERR_OFFSET_Y,
			.STATUS_ERR_WIDTH = LAYOUT_THEMES[0].STATUS_ERR_WIDTH,
			.STATUS_ERR_HEIGHT = LAYOUT_THEMES[0].STATUS_ERR_HEIGHT,
			//text bar under wtf
			.TEXTBAR_FONT = LAYOUT_THEMES[0].TEXTBAR_FONT,
			//bottom buttons
			.BOTTOM_BUTTONS_BLOCK_HEIGHT = LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_HEIGHT,
			.BOTTOM_BUTTONS_BLOCK_TOP = LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_TOP,
			.BOTTOM_BUTTONS_COUNT = LAYOUT_THEMES[0].BOTTOM_BUTTONS_COUNT,
			.BOTTOM_BUTTONS_ARROWS_WIDTH = LAYOUT_THEMES[0].BOTTOM_BUTTONS_ARROWS_WIDTH,
			.BOTTOM_BUTTONS_ONE_WIDTH = LAYOUT_THEMES[0].BOTTOM_BUTTONS_ONE_WIDTH,
			// FFT and waterfall
			.FFT_HEIGHT_STYLE1 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE1,
			.WTF_HEIGHT_STYLE1 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE1,
			.FFT_HEIGHT_STYLE2 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE2,
			.WTF_HEIGHT_STYLE2 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE2,
			.FFT_HEIGHT_STYLE3 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE3,
			.WTF_HEIGHT_STYLE3 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE3,
			.FFT_PRINT_SIZE = LAYOUT_THEMES[0].FFT_PRINT_SIZE,
			.FFT_CWDECODER_OFFSET = LAYOUT_THEMES[0].FFT_CWDECODER_OFFSET,
			.FFT_FFTWTF_POS_Y = LAYOUT_THEMES[0].FFT_FFTWTF_POS_Y,
			.FFT_FFTWTF_BOTTOM = LAYOUT_THEMES[0].FFT_FFTWTF_BOTTOM,
			.FFT_FREQLABELS_HEIGHT = LAYOUT_THEMES[0].FFT_FREQLABELS_HEIGHT,
			// system menu
			.SYSMENU_X1 = LAYOUT_THEMES[0].SYSMENU_X1,
			.SYSMENU_X2 = LAYOUT_THEMES[0].SYSMENU_X2,
			.SYSMENU_W = LAYOUT_THEMES[0].SYSMENU_W,
			.SYSMENU_ITEM_HEIGHT = LAYOUT_THEMES[0].SYSMENU_ITEM_HEIGHT,
			.SYSMENU_MAX_ITEMS_ON_PAGE = LAYOUT_THEMES[0].SYSMENU_MAX_ITEMS_ON_PAGE,
			//Tooltip
			.TOOLTIP_TIMEOUT = LAYOUT_THEMES[0].TOOLTIP_TIMEOUT,
			.TOOLTIP_MARGIN = LAYOUT_THEMES[0].TOOLTIP_MARGIN,
			.TOOLTIP_POS_X = (uint16_t)(LAYOUT_THEMES[1].FREQ_A_LEFT + 150),
			.TOOLTIP_POS_Y = 25,
			//BW Trapezoid
			.BW_TRAPEZ_POS_X = 340,
			.BW_TRAPEZ_POS_Y = 65,
			.BW_TRAPEZ_HEIGHT = 25,
			.BW_TRAPEZ_WIDTH = 100,
			//Touch buttons layout
			.BUTTON_PADDING = LAYOUT_THEMES[0].BUTTON_PADDING,
			.BUTTON_LIGHTER_WIDTH = LAYOUT_THEMES[0].BUTTON_LIGHTER_WIDTH,
			.BUTTON_LIGHTER_HEIGHT = LAYOUT_THEMES[0].BUTTON_LIGHTER_HEIGHT,
			//Windows
			.WINDOWS_BUTTON_WIDTH = LAYOUT_THEMES[0].WINDOWS_BUTTON_WIDTH,
			.WINDOWS_BUTTON_HEIGHT = LAYOUT_THEMES[0].WINDOWS_BUTTON_HEIGHT,
			.WINDOWS_BUTTON_MARGIN = LAYOUT_THEMES[0].WINDOWS_BUTTON_MARGIN,
		},
		//7-segment digitals
		{
			.TOPBUTTONS_X1 = LAYOUT_THEMES[0].TOPBUTTONS_X1,
			.TOPBUTTONS_X2 = LAYOUT_THEMES[0].TOPBUTTONS_X2,
			.TOPBUTTONS_Y1 = LAYOUT_THEMES[0].TOPBUTTONS_Y1,
			.TOPBUTTONS_COUNT = LAYOUT_THEMES[0].TOPBUTTONS_COUNT,
			.TOPBUTTONS_WIDTH = LAYOUT_THEMES[0].TOPBUTTONS_WIDTH,
			.TOPBUTTONS_HEIGHT = LAYOUT_THEMES[0].TOPBUTTONS_HEIGHT,
			.TOPBUTTONS_PRE_X = LAYOUT_THEMES[0].TOPBUTTONS_PRE_X,
			.TOPBUTTONS_PRE_Y = LAYOUT_THEMES[0].TOPBUTTONS_PRE_Y,
			.TOPBUTTONS_ATT_X = LAYOUT_THEMES[0].TOPBUTTONS_ATT_X,
			.TOPBUTTONS_ATT_Y = LAYOUT_THEMES[0].TOPBUTTONS_ATT_Y,
			.TOPBUTTONS_PGA_X = LAYOUT_THEMES[0].TOPBUTTONS_PGA_X,
			.TOPBUTTONS_PGA_Y = LAYOUT_THEMES[0].TOPBUTTONS_PGA_Y,
			.TOPBUTTONS_DRV_X = LAYOUT_THEMES[0].TOPBUTTONS_DRV_X,
			.TOPBUTTONS_DRV_Y = LAYOUT_THEMES[0].TOPBUTTONS_DRV_Y,
			.TOPBUTTONS_AGC_X = LAYOUT_THEMES[0].TOPBUTTONS_AGC_X,
			.TOPBUTTONS_AGC_Y = LAYOUT_THEMES[0].TOPBUTTONS_AGC_Y,
			.TOPBUTTONS_DNR_X = LAYOUT_THEMES[0].TOPBUTTONS_DNR_X,
			.TOPBUTTONS_DNR_Y = LAYOUT_THEMES[0].TOPBUTTONS_DNR_Y,
			.TOPBUTTONS_NB_X = LAYOUT_THEMES[0].TOPBUTTONS_NB_X,
			.TOPBUTTONS_NB_Y = LAYOUT_THEMES[0].TOPBUTTONS_NB_Y,
			.TOPBUTTONS_NOTCH_X = LAYOUT_THEMES[0].TOPBUTTONS_NOTCH_X,
			.TOPBUTTONS_NOTCH_Y = LAYOUT_THEMES[0].TOPBUTTONS_NOTCH_Y,
			.TOPBUTTONS_SQL_X = LAYOUT_THEMES[0].TOPBUTTONS_SQL_X,
			.TOPBUTTONS_SQL_Y = LAYOUT_THEMES[0].TOPBUTTONS_SQL_Y,
			.TOPBUTTONS_FAST_X = LAYOUT_THEMES[0].TOPBUTTONS_FAST_X,
			.TOPBUTTONS_FAST_Y = LAYOUT_THEMES[0].TOPBUTTONS_FAST_Y,
			.TOPBUTTONS_MUTE_X = LAYOUT_THEMES[0].TOPBUTTONS_MUTE_X,
			.TOPBUTTONS_MUTE_Y = LAYOUT_THEMES[0].TOPBUTTONS_MUTE_Y,
			//clock
			.CLOCK_POS_Y = LAYOUT_THEMES[0].CLOCK_POS_Y,
			.CLOCK_POS_HRS_X = LAYOUT_THEMES[0].CLOCK_POS_HRS_X,
			.CLOCK_POS_MIN_X = LAYOUT_THEMES[0].CLOCK_POS_MIN_X,
			.CLOCK_POS_SEC_X = LAYOUT_THEMES[0].CLOCK_POS_SEC_X,
			.CLOCK_FONT = LAYOUT_THEMES[0].CLOCK_FONT,
			//WIFI
			.STATUS_WIFI_ICON_X = LAYOUT_THEMES[0].STATUS_WIFI_ICON_X,
			.STATUS_WIFI_ICON_Y = LAYOUT_THEMES[0].STATUS_WIFI_ICON_Y,
			//SD
			.STATUS_SD_ICON_X = LAYOUT_THEMES[0].STATUS_SD_ICON_X,
			.STATUS_SD_ICON_Y = LAYOUT_THEMES[0].STATUS_SD_ICON_Y,
			// frequency output VFO-A
			.FREQ_A_LEFT = LAYOUT_THEMES[0].FREQ_A_LEFT,
			.FREQ_X_OFFSET_100 = LAYOUT_THEMES[0].FREQ_X_OFFSET_100,
			.FREQ_X_OFFSET_10 = LAYOUT_THEMES[0].FREQ_X_OFFSET_10,
			.FREQ_X_OFFSET_1 = LAYOUT_THEMES[0].FREQ_X_OFFSET_1,
			.FREQ_X_OFFSET_KHZ = LAYOUT_THEMES[0].FREQ_X_OFFSET_KHZ,
			.FREQ_X_OFFSET_HZ = LAYOUT_THEMES[0].FREQ_X_OFFSET_HZ,
			.FREQ_HEIGHT = LAYOUT_THEMES[0].FREQ_HEIGHT,
			.FREQ_WIDTH = LAYOUT_THEMES[0].FREQ_WIDTH,
			.FREQ_TOP_OFFSET = LAYOUT_THEMES[0].FREQ_TOP_OFFSET,
			.FREQ_LEFT_MARGIN = LAYOUT_THEMES[0].FREQ_LEFT_MARGIN,
			.FREQ_RIGHT_MARGIN = LAYOUT_THEMES[0].FREQ_RIGHT_MARGIN,
			.FREQ_BOTTOM_OFFSET = LAYOUT_THEMES[0].FREQ_BOTTOM_OFFSET,
			.FREQ_BLOCK_HEIGHT = LAYOUT_THEMES[0].FREQ_BLOCK_HEIGHT,
			.FREQ_Y_TOP = LAYOUT_THEMES[0].FREQ_Y_TOP,
			.FREQ_Y_BASELINE = LAYOUT_THEMES[0].FREQ_Y_BASELINE,
			.FREQ_Y_BASELINE_SMALL = LAYOUT_THEMES[0].FREQ_Y_BASELINE_SMALL,
			.FREQ_FONT = &DS_DIGIT36pt7b,
			.FREQ_SMALL_FONT = &DS_DIGIT32pt7b,
			.FREQ_DELIMITER_Y_OFFSET = LAYOUT_THEMES[0].FREQ_DELIMITER_Y_OFFSET,
			.FREQ_DELIMITER_X1_OFFSET = LAYOUT_THEMES[0].FREQ_DELIMITER_X1_OFFSET,
			.FREQ_DELIMITER_X2_OFFSET = LAYOUT_THEMES[0].FREQ_DELIMITER_X2_OFFSET,
			// frequency output VFO-B
			.FREQ_B_LEFT = LAYOUT_THEMES[0].FREQ_B_LEFT,
			.FREQ_B_X_OFFSET_100 = LAYOUT_THEMES[0].FREQ_B_X_OFFSET_100,
			.FREQ_B_X_OFFSET_10 = LAYOUT_THEMES[0].FREQ_B_X_OFFSET_10,
			.FREQ_B_X_OFFSET_1 = LAYOUT_THEMES[0].FREQ_B_X_OFFSET_1,
			.FREQ_B_X_OFFSET_KHZ = LAYOUT_THEMES[0].FREQ_B_X_OFFSET_KHZ,
			.FREQ_B_X_OFFSET_HZ = LAYOUT_THEMES[0].FREQ_B_X_OFFSET_HZ,
			.FREQ_B_HEIGHT = LAYOUT_THEMES[0].FREQ_B_HEIGHT,
			.FREQ_B_WIDTH = LAYOUT_THEMES[0].FREQ_B_WIDTH,
			.FREQ_B_TOP_OFFSET = LAYOUT_THEMES[0].FREQ_B_TOP_OFFSET,
			.FREQ_B_LEFT_MARGIN = LAYOUT_THEMES[0].FREQ_B_LEFT_MARGIN,
			.FREQ_B_RIGHT_MARGIN = LAYOUT_THEMES[0].FREQ_B_RIGHT_MARGIN,
			.FREQ_B_BOTTOM_OFFSET = LAYOUT_THEMES[0].FREQ_B_BOTTOM_OFFSET,
			.FREQ_B_BLOCK_HEIGHT = LAYOUT_THEMES[0].FREQ_B_BLOCK_HEIGHT,
			.FREQ_B_Y_TOP = LAYOUT_THEMES[0].FREQ_B_Y_TOP,
			.FREQ_B_Y_BASELINE = LAYOUT_THEMES[0].FREQ_B_Y_BASELINE,
			.FREQ_B_Y_BASELINE_SMALL = LAYOUT_THEMES[0].FREQ_B_Y_BASELINE_SMALL,
			.FREQ_B_FONT = &DS_DIGIT32pt7b,
			.FREQ_B_SMALL_FONT = &DS_DIGIT18pt7b,
			.FREQ_B_DELIMITER_Y_OFFSET = LAYOUT_THEMES[0].FREQ_B_DELIMITER_Y_OFFSET,
			.FREQ_B_DELIMITER_X1_OFFSET = LAYOUT_THEMES[0].FREQ_B_DELIMITER_X1_OFFSET,
			.FREQ_B_DELIMITER_X2_OFFSET = LAYOUT_THEMES[0].FREQ_B_DELIMITER_X2_OFFSET,
			// display statuses under frequency
			.STATUS_Y_OFFSET = LAYOUT_THEMES[0].STATUS_Y_OFFSET,
			.STATUS_HEIGHT = LAYOUT_THEMES[0].STATUS_HEIGHT,
			.STATUS_BAR_X_OFFSET = LAYOUT_THEMES[0].STATUS_BAR_X_OFFSET,
			.STATUS_BAR_Y_OFFSET = LAYOUT_THEMES[0].STATUS_BAR_Y_OFFSET,
			.STATUS_BAR_HEIGHT = LAYOUT_THEMES[0].STATUS_BAR_HEIGHT,
			.STATUS_TXRX_X_OFFSET = LAYOUT_THEMES[0].STATUS_TXRX_X_OFFSET,
			.STATUS_TXRX_Y_OFFSET = LAYOUT_THEMES[0].STATUS_TXRX_Y_OFFSET,
			.STATUS_TXRX_FONT = LAYOUT_THEMES[0].STATUS_TXRX_FONT,
			.STATUS_VFO_X_OFFSET = LAYOUT_THEMES[0].STATUS_VFO_X_OFFSET,
			.STATUS_VFO_Y_OFFSET = LAYOUT_THEMES[0].STATUS_VFO_Y_OFFSET,
			.STATUS_VFO_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_VFO_BLOCK_WIDTH,
			.STATUS_VFO_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_VFO_BLOCK_HEIGHT,
			.STATUS_ANT_X_OFFSET = LAYOUT_THEMES[0].STATUS_ANT_X_OFFSET,
			.STATUS_ANT_Y_OFFSET = LAYOUT_THEMES[0].STATUS_ANT_Y_OFFSET,
			.STATUS_ANT_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_ANT_BLOCK_WIDTH,
			.STATUS_ANT_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_ANT_BLOCK_HEIGHT,
			.STATUS_TX_LABELS_OFFSET_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_OFFSET_X,
			.STATUS_TX_LABELS_MARGIN_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_MARGIN_X,
			.STATUS_SMETER_ANALOG = LAYOUT_THEMES[0].STATUS_SMETER_ANALOG,
			.STATUS_SMETER_TOP_OFFSET = LAYOUT_THEMES[0].STATUS_SMETER_TOP_OFFSET,
			.STATUS_SMETER_ANALOG_HEIGHT = LAYOUT_THEMES[0].STATUS_SMETER_ANALOG_HEIGHT,
			.STATUS_SMETER_WIDTH = LAYOUT_THEMES[0].STATUS_SMETER_WIDTH,
			.STATUS_SMETER_MARKER_HEIGHT = LAYOUT_THEMES[0].STATUS_SMETER_MARKER_HEIGHT,
			.STATUS_PMETER_WIDTH = LAYOUT_THEMES[0].STATUS_PMETER_WIDTH,
			.STATUS_AMETER_WIDTH = LAYOUT_THEMES[0].STATUS_AMETER_WIDTH,
			.STATUS_ALC_BAR_X_OFFSET = LAYOUT_THEMES[0].STATUS_ALC_BAR_X_OFFSET,
			.STATUS_LABELS_OFFSET_Y = LAYOUT_THEMES[0].STATUS_LABELS_OFFSET_Y,
			.STATUS_LABELS_FONT_SIZE = LAYOUT_THEMES[0].STATUS_LABELS_FONT_SIZE,
			.STATUS_LABEL_S_VAL_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_S_VAL_X_OFFSET,
			.STATUS_LABEL_S_VAL_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_S_VAL_Y_OFFSET,
			.STATUS_LABEL_S_VAL_FONT = LAYOUT_THEMES[0].STATUS_LABEL_S_VAL_FONT,
			.STATUS_LABEL_DBM_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_DBM_X_OFFSET,
			.STATUS_LABEL_DBM_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_DBM_Y_OFFSET,
			.STATUS_LABEL_BW_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_BW_X_OFFSET,
			.STATUS_LABEL_BW_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_BW_Y_OFFSET,
			.STATUS_LABEL_RIT_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_RIT_X_OFFSET,
			.STATUS_LABEL_RIT_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_RIT_Y_OFFSET,
			.STATUS_LABEL_THERM_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_THERM_X_OFFSET,
			.STATUS_LABEL_THERM_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_THERM_Y_OFFSET,
			.STATUS_LABEL_NOTCH_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_NOTCH_X_OFFSET,
			.STATUS_LABEL_NOTCH_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_NOTCH_Y_OFFSET,
			.STATUS_LABEL_FFT_BW_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_FFT_BW_X_OFFSET,
			.STATUS_LABEL_FFT_BW_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_FFT_BW_Y_OFFSET,
			.STATUS_LABEL_CPU_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_CPU_X_OFFSET,
			.STATUS_LABEL_CPU_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_CPU_Y_OFFSET,
			.STATUS_LABEL_AUTOGAIN_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_AUTOGAIN_X_OFFSET,
			.STATUS_LABEL_AUTOGAIN_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_AUTOGAIN_Y_OFFSET,
			.STATUS_LABEL_LOCK_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_LOCK_X_OFFSET,
			.STATUS_LABEL_LOCK_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_LOCK_Y_OFFSET,
			.STATUS_LABEL_REC_X_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_REC_X_OFFSET,
			.STATUS_LABEL_REC_Y_OFFSET = LAYOUT_THEMES[0].STATUS_LABEL_REC_Y_OFFSET,
			.STATUS_SMETER_PEAK_HOLDTIME = LAYOUT_THEMES[0].STATUS_SMETER_PEAK_HOLDTIME,
			.STATUS_SMETER_TXLABELS_MARGIN = LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_MARGIN,
			.STATUS_SMETER_TXLABELS_PADDING = LAYOUT_THEMES[0].STATUS_SMETER_TXLABELS_PADDING,
			.STATUS_TX_LABELS_VAL_WIDTH = LAYOUT_THEMES[0].STATUS_TX_LABELS_VAL_WIDTH,
			.STATUS_TX_LABELS_VAL_HEIGHT = LAYOUT_THEMES[0].STATUS_TX_LABELS_VAL_HEIGHT,
			.STATUS_TX_LABELS_SWR_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_SWR_X,
			.STATUS_TX_LABELS_FWD_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_FWD_X,
			.STATUS_TX_LABELS_REF_X = LAYOUT_THEMES[0].STATUS_TX_LABELS_REF_X,
			.STATUS_TX_ALC_X_OFFSET = LAYOUT_THEMES[0].STATUS_TX_ALC_X_OFFSET,
			.STATUS_MODE_X_OFFSET = LAYOUT_THEMES[0].STATUS_MODE_X_OFFSET,
			.STATUS_MODE_Y_OFFSET = LAYOUT_THEMES[0].STATUS_MODE_Y_OFFSET,
			.STATUS_MODE_BLOCK_WIDTH = LAYOUT_THEMES[0].STATUS_MODE_BLOCK_WIDTH,
			.STATUS_MODE_BLOCK_HEIGHT = LAYOUT_THEMES[0].STATUS_MODE_BLOCK_HEIGHT,
			.STATUS_MODE_B_X_OFFSET = LAYOUT_THEMES[0].STATUS_MODE_B_X_OFFSET,
			.STATUS_MODE_B_Y_OFFSET = LAYOUT_THEMES[0].STATUS_MODE_B_Y_OFFSET,
			.STATUS_ERR_OFFSET_X = LAYOUT_THEMES[0].STATUS_ERR_OFFSET_X,
			.STATUS_ERR_OFFSET_Y = LAYOUT_THEMES[0].STATUS_ERR_OFFSET_Y,
			.STATUS_ERR_WIDTH = LAYOUT_THEMES[0].STATUS_ERR_WIDTH,
			.STATUS_ERR_HEIGHT = LAYOUT_THEMES[0].STATUS_ERR_HEIGHT,
			//text bar under wtf
			.TEXTBAR_FONT = LAYOUT_THEMES[0].TEXTBAR_FONT,
			//bottom buttons
			.BOTTOM_BUTTONS_BLOCK_HEIGHT = LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_HEIGHT,
			.BOTTOM_BUTTONS_BLOCK_TOP = LAYOUT_THEMES[0].BOTTOM_BUTTONS_BLOCK_TOP,
			.BOTTOM_BUTTONS_COUNT = LAYOUT_THEMES[0].BOTTOM_BUTTONS_COUNT,
			.BOTTOM_BUTTONS_ARROWS_WIDTH = LAYOUT_THEMES[0].BOTTOM_BUTTONS_ARROWS_WIDTH,
			.BOTTOM_BUTTONS_ONE_WIDTH = LAYOUT_THEMES[0].BOTTOM_BUTTONS_ONE_WIDTH,
			// FFT and waterfall
			.FFT_HEIGHT_STYLE1 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE1,
			.WTF_HEIGHT_STYLE1 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE1,
			.FFT_HEIGHT_STYLE2 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE2,
			.WTF_HEIGHT_STYLE2 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE2,
			.FFT_HEIGHT_STYLE3 = LAYOUT_THEMES[0].FFT_HEIGHT_STYLE3,
			.WTF_HEIGHT_STYLE3 = LAYOUT_THEMES[0].WTF_HEIGHT_STYLE3,
			.FFT_PRINT_SIZE = LAYOUT_THEMES[0].FFT_PRINT_SIZE,
			.FFT_CWDECODER_OFFSET = LAYOUT_THEMES[0].FFT_CWDECODER_OFFSET,
			.FFT_FFTWTF_POS_Y = LAYOUT_THEMES[0].FFT_FFTWTF_POS_Y,
			.FFT_FFTWTF_BOTTOM = LAYOUT_THEMES[0].FFT_FFTWTF_BOTTOM,
			.FFT_FREQLABELS_HEIGHT = LAYOUT_THEMES[0].FFT_FREQLABELS_HEIGHT,
			// system menu
			.SYSMENU_X1 = LAYOUT_THEMES[0].SYSMENU_X1,
			.SYSMENU_X2 = LAYOUT_THEMES[0].SYSMENU_X2,
			.SYSMENU_W = LAYOUT_THEMES[0].SYSMENU_W,
			.SYSMENU_ITEM_HEIGHT = LAYOUT_THEMES[0].SYSMENU_ITEM_HEIGHT,
			.SYSMENU_MAX_ITEMS_ON_PAGE = LAYOUT_THEMES[0].SYSMENU_MAX_ITEMS_ON_PAGE,
			//Tooltip
			.TOOLTIP_TIMEOUT = LAYOUT_THEMES[0].TOOLTIP_TIMEOUT,
			.TOOLTIP_MARGIN = LAYOUT_THEMES[0].TOOLTIP_MARGIN,
			.TOOLTIP_POS_X = LAYOUT_THEMES[0].TOOLTIP_POS_X,
			.TOOLTIP_POS_Y = LAYOUT_THEMES[0].TOOLTIP_POS_Y,
			//BW Trapezoid
			.BW_TRAPEZ_POS_X = LAYOUT_THEMES[0].BW_TRAPEZ_POS_X,
			.BW_TRAPEZ_POS_Y = LAYOUT_THEMES[0].BW_TRAPEZ_POS_Y,
			.BW_TRAPEZ_HEIGHT = LAYOUT_THEMES[0].BW_TRAPEZ_HEIGHT,
			.BW_TRAPEZ_WIDTH = LAYOUT_THEMES[0].BW_TRAPEZ_WIDTH,
			//Touch buttons layout
			.BUTTON_PADDING = LAYOUT_THEMES[0].BUTTON_PADDING,
			.BUTTON_LIGHTER_WIDTH = LAYOUT_THEMES[0].BUTTON_LIGHTER_WIDTH,
			.BUTTON_LIGHTER_HEIGHT = LAYOUT_THEMES[0].BUTTON_LIGHTER_HEIGHT,
			//Windows
			.WINDOWS_BUTTON_WIDTH = LAYOUT_THEMES[0].WINDOWS_BUTTON_WIDTH,
			.WINDOWS_BUTTON_HEIGHT = LAYOUT_THEMES[0].WINDOWS_BUTTON_HEIGHT,
			.WINDOWS_BUTTON_MARGIN = LAYOUT_THEMES[0].WINDOWS_BUTTON_MARGIN,
		},
};

#endif
