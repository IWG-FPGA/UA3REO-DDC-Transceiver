-- -------------------------------------------------------------
-- 
-- File Name: hdlsrc\nco16\NCO_HDL_Optimized.vhd
-- Created: 2021-02-10 22:05:09
-- 
-- Generated by MATLAB 9.9 and HDL Coder 3.17
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: NCO_HDL_Optimized
-- Source Path: nco16/NCO HDL Optimized
-- Hierarchy Level: 1
-- 
-- NCO HDL Optimized
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY NCO_HDL_Optimized IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        inc                               :   IN    std_logic_vector(31 DOWNTO 0);  -- uint32
        validIn                           :   IN    std_logic;
        sine                              :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16_En15
        cosine                            :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16_En15
        validOut                          :   OUT   std_logic
        );
END NCO_HDL_Optimized;


ARCHITECTURE rtl OF NCO_HDL_Optimized IS

  -- Component Declarations
  COMPONENT WaveformGen
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          enb                             :   IN    std_logic;
          phaseIdx                        :   IN    std_logic_vector(16 DOWNTO 0);  -- ufix17_E15
          sine                            :   OUT   std_logic_vector(15 DOWNTO 0);  -- sfix16_En15
          cosine                          :   OUT   std_logic_vector(15 DOWNTO 0)  -- sfix16_En15
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : WaveformGen
    USE ENTITY work.WaveformGen(rtl);

  -- Signals
  SIGNAL outsel_reg_reg                   : std_logic_vector(0 TO 4);  -- ufix1 [5]
  SIGNAL outsel                           : std_logic;
  SIGNAL outzero                          : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL const0                           : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL inc_unsigned                     : unsigned(31 DOWNTO 0);  -- uint32
  SIGNAL pInc                             : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL validPInc                        : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL accphase_reg                     : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL addpInc                          : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL pOffset                          : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL accoffset                        : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL accoffsete_reg                   : signed(31 DOWNTO 0);  -- sfix32
  SIGNAL accQuantized                     : unsigned(16 DOWNTO 0);  -- ufix17_E15
  SIGNAL outsine                          : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL outcos                           : std_logic_vector(15 DOWNTO 0);  -- ufix16
  SIGNAL outsine_signed                   : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL validsine                        : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL sine_tmp                         : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL outcos_signed                    : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL validcos                         : signed(15 DOWNTO 0);  -- sfix16_En15
  SIGNAL cosine_tmp                       : signed(15 DOWNTO 0);  -- sfix16_En15

BEGIN
  u_Wave_inst : WaveformGen
    PORT MAP( clk => clk,
              reset => reset,
              enb => enb,
              phaseIdx => std_logic_vector(accQuantized),  -- ufix17_E15
              sine => outsine,  -- sfix16_En15
              cosine => outcos  -- sfix16_En15
              );

  outsel_reg_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      outsel_reg_reg <= (OTHERS => '0');
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        outsel_reg_reg(0) <= validIn;
        outsel_reg_reg(1 TO 4) <= outsel_reg_reg(0 TO 3);
      END IF;
    END IF;
  END PROCESS outsel_reg_process;

  outsel <= outsel_reg_reg(4);

  outzero <= to_signed(16#0000#, 16);

  -- Constant Zero
  const0 <= to_signed(0, 32);

  inc_unsigned <= unsigned(inc);

  pInc <= signed(inc_unsigned);

  
  validPInc <= const0 WHEN validIn = '0' ELSE
      pInc;

  -- Add phase increment
  addpInc <= accphase_reg + validPInc;

  -- Phase increment accumulator register
  AccPhaseRegister_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      accphase_reg <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        accphase_reg <= addpInc;
      END IF;
    END IF;
  END PROCESS AccPhaseRegister_process;


  pOffset <= to_signed(0, 32);

  -- Add phase offset
  accoffset <= accphase_reg + pOffset;

  -- Phase offset accumulator register
  AccOffsetRegister_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      accoffsete_reg <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        accoffsete_reg <= accoffset;
      END IF;
    END IF;
  END PROCESS AccOffsetRegister_process;


  -- Phase quantization
  accQuantized <= unsigned(accoffsete_reg(31 DOWNTO 15));

  outsine_signed <= signed(outsine);

  
  validsine <= outzero WHEN outsel = '0' ELSE
      outsine_signed;

  -- Output sine register
  OutSineRegister_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      sine_tmp <= to_signed(16#0000#, 16);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        sine_tmp <= validsine;
      END IF;
    END IF;
  END PROCESS OutSineRegister_process;


  sine <= std_logic_vector(sine_tmp);

  outcos_signed <= signed(outcos);

  
  validcos <= outzero WHEN outsel = '0' ELSE
      outcos_signed;

  -- Output cosine register
  OutCosineRegister_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      cosine_tmp <= to_signed(16#0000#, 16);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        cosine_tmp <= validcos;
      END IF;
    END IF;
  END PROCESS OutCosineRegister_process;


  cosine <= std_logic_vector(cosine_tmp);

  -- validOut register
  validOut_reg_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      validOut <= '0';
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        validOut <= outsel;
      END IF;
    END IF;
  END PROCESS validOut_reg_process;


END rtl;

