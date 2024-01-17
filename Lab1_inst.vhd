library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity lab1_inst is port(
	clk 		: in  std_logic := '0';
	reset_n 	: in  std_logic := '0';
	SW  		: in  std_logic_vector(9 downto 0);
	LEDR 		: out std_logic_vector(9 downto 0);
	BP  		: in  std_logic_vector(1 downto 0));
end entity;

architecture arch_lab1 of lab1_inst is
	component lab1v1 is 
		port(
			clk_clk                          : in  std_logic                    := 'X'; 				 -- clk
			pio_0_external_connection_export : in  std_logic_vector(9 downto 0) := (others => 'X'); -- export
			pio_1_external_connection_export : out std_logic_vector(9 downto 0);       				 -- export
			pio_2_external_connection_export : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			reset_reset_n                    : in  std_logic                    := 'X' 				 -- reset_n
		);
	end component lab1v1;

	begin
	
	u0 : component lab1v1
		port map (
			clk_clk                          => clk,		-- clk.clk
			pio_0_external_connection_export => SW,		-- pio_0_external_connection.export
			pio_1_external_connection_export => LEDR,		-- pio_1_external_connection.export
			pio_2_external_connection_export => BP,		-- pio_2_external_connection.export
			reset_reset_n                    => reset_n  -- reset.reset_n
		);
end architecture;