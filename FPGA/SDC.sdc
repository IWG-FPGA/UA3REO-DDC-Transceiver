set_time_format -unit ns -decimal_places 3

create_clock -name "clock_crystal" -period 122.880MHz [get_ports {clk_sys_lvpecl_p}]
create_clock -name "clock_adc" -period 122.880MHz [get_ports {ADC_CLK}]
create_clock -name "clock_tcxo" -period 12.288MHz [get_ports {TCXO_CLK_IN}]
create_clock -name "clock_stm32" -period 12.288MHz [get_ports {STM32_CLK}]
create_clock -name "RX1_CICCOMP_Q_clk" -period 0.384MHz {rx_ciccomp:RX1_CICCOMP_Q|rx_ciccomp_0002:rx_ciccomp_inst|rx_ciccomp_0002_ast:rx_ciccomp_0002_ast_inst|auk_dspip_avalon_streaming_source_hpfir:source|data_valid}
create_clock -name "RX1_CICCOMP_I_clk" -period 0.384MHz {rx_ciccomp:RX1_CICCOMP_I|rx_ciccomp_0002:rx_ciccomp_inst|rx_ciccomp_0002_ast:rx_ciccomp_0002_ast_inst|auk_dspip_avalon_streaming_source_hpfir:source|data_valid}
create_clock -name "RX2_CICCOMP_Q_clk" -period 0.384MHz {rx_ciccomp:RX2_CICCOMP_Q|rx_ciccomp_0002:rx_ciccomp_inst|rx_ciccomp_0002_ast:rx_ciccomp_0002_ast_inst|auk_dspip_avalon_streaming_source_hpfir:source|data_valid}
create_clock -name "RX2_CICCOMP_I_clk" -period 0.384MHz {rx_ciccomp:RX2_CICCOMP_I|rx_ciccomp_0002:rx_ciccomp_inst|rx_ciccomp_0002_ast:rx_ciccomp_0002_ast_inst|auk_dspip_avalon_streaming_source_hpfir:source|data_valid}
create_clock -name "RX_IQ_ST_CLK" -period 0.384MHz {stm32_interface:STM32_INTERFACE|IQ_RX_READ_CLK}
create_clock -name "TX_IQ_ST_CLK" -period 0.048MHz {stm32_interface:STM32_INTERFACE|tx_iq_valid} 

set_clock_groups -asynchronous -group clock_crystal -group clock_adc -group clock_tcxo -group clock_stm32

derive_clock_uncertainty

derive_pll_clocks -create_base_clocks

set_output_delay -clock TX_PLL|altpll_component|auto_generated|pll1|clk[0] -max 36ps [get_ports {DAC_CLK}]
set_output_delay -clock TX_PLL|altpll_component|auto_generated|pll1|clk[0] -min 0ps [get_ports {DAC_CLK}]
set_output_delay -clock TX_PLL|altpll_component|auto_generated|pll1|clk[0] -max 36ps [get_ports {DAC_OUTPUT[*]}]
set_output_delay -clock TX_PLL|altpll_component|auto_generated|pll1|clk[0] -min 0ps [get_ports {DAC_OUTPUT[*]}]
set_output_delay -clock clock_stm32 -max 36ps [get_ports {STM32_DATA_BUS[*]}]
set_output_delay -clock clock_stm32 -min 0ps [get_ports {STM32_DATA_BUS[*]}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[1] -max 36ps [get_ports {AUDIO_48K_CLOCK}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[1] -min 0ps [get_ports {AUDIO_48K_CLOCK}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[0] -max 36ps [get_ports {AUDIO_I2S_CLOCK}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[0] -min 0ps [get_ports {AUDIO_I2S_CLOCK}]
set_output_delay -clock DCDC_PLL|altpll_component|auto_generated|pll1|clk[0] -max 36ps [get_ports {DCDC_SYNC}]
set_output_delay -clock DCDC_PLL|altpll_component|auto_generated|pll1|clk[0] -min 0ps [get_ports {DCDC_SYNC}]
set_output_delay -clock DCDC_PLL|altpll_component|auto_generated|pll1|clk[2] -max 36ps [get_ports {VCXO_CHARGE_PUMP}]
set_output_delay -clock DCDC_PLL|altpll_component|auto_generated|pll1|clk[2] -min 0ps [get_ports {VCXO_CHARGE_PUMP}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -max 36ps [get_ports {FLASH_C}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -min 0ps [get_ports {FLASH_C}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -max 36ps [get_ports {FLASH_MOSI}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -min 0ps [get_ports {FLASH_MOSI}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -max 36ps [get_ports {FLASH_S}]
set_output_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -min 0ps [get_ports {FLASH_S}]
set_output_delay -clock clock_stm32 1 [get_ports {ADC_DITH}]
set_output_delay -clock clock_stm32 1 [get_ports {ADC_PGA}]
set_output_delay -clock clock_stm32 1 [get_ports {ADC_RAND}]
set_output_delay -clock clock_stm32 1 [get_ports {ADC_SHDN}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_DIV0}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_DIV1}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_HP1}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_HP2}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_PD}]
set_output_delay -clock clock_stm32 1 [get_ports {DAC_X4}]
set_output_delay -clock clock_stm32 1 [get_ports {PREAMP}]

set_input_delay -clock clock_adc -max 36ps [get_ports ADC_INPUT[*]]
set_input_delay -clock clock_adc -min 0ps [get_ports ADC_INPUT[*]]
set_input_delay -clock clock_adc -max 36ps [get_ports ADC_OTR]
set_input_delay -clock clock_adc -min 0ps [get_ports ADC_OTR]
set_input_delay -clock clock_stm32 -max 36ps [get_ports STM32_DATA_BUS[*]]
set_input_delay -clock clock_stm32 -min 0ps [get_ports STM32_DATA_BUS[*]]
set_input_delay -clock clock_stm32 -max 36ps [get_ports STM32_SYNC]
set_input_delay -clock clock_stm32 -min 0ps [get_ports STM32_SYNC]
set_input_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -max 36ps [get_ports FLASH_MISO]
set_input_delay -clock MAIN_PLL|altpll_component|auto_generated|pll1|clk[2] -min 0ps [get_ports FLASH_MISO]

#set_false_path -from [get_clocks {TX_PLL|altpll_component|auto_generated|pll1|clk[0]}] -to [get_clocks {clock_crystal}]
set_false_path -from [get_clocks {TX_PLL|altpll_component|auto_generated|pll1|clk[0]}] -to [get_clocks {clock_stm32}]
set_false_path -from [get_clocks {TX_PLL|altpll_component|auto_generated|pll1|clk[0]}] -to [get_clocks {clock_adc}]
#set_false_path -from [get_clocks {clock_stm32}] -to [get_clocks {MAIN_PLL|altpll_component|auto_generated|pll1|clk[2]}]
set_false_path -from [get_clocks {clock_stm32}] -to [get_clocks {TX_PLL|altpll_component|auto_generated|pll1|clk[0]}]
set_false_path -from [get_clocks {clock_stm32}] -to [get_clocks {DCDC_PLL|altpll_component|auto_generated|pll1|clk[0]}]
#set_false_path -from [get_clocks {MAIN_PLL|altpll_component|auto_generated|pll1|clk[2]}] -to [get_clocks {clock_stm32}]
#set_false_path -from [get_clocks {RX1_CICOMP_Q_clk}] -to [get_clocks {clock_stm32}]
set_false_path -from [get_clocks {clock_adc}] -to [get_clocks {TX_PLL|altpll_component|auto_generated|pll1|clk[0]}]
set_false_path -from [get_clocks {DCDC_PLL|altpll_component|auto_generated|pll1|clk[1]}] -to [get_clocks {DCDC_PLL|altpll_component|auto_generated|pll1|clk[0]}]
