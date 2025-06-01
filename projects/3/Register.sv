module Register(
	input logic clk,
	input logic [msb:lsb] in,
	input logic load,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	for (genvar i = lsb; i <= msb; ++i)
	begin : bit_loop
		Bit bit_(
			.clk(clk),
			.in(in[i]),
			.load(load),
			.out(out[i])
		);
	end
endmodule
