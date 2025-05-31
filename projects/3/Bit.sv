module Bit(
	input logic clk,
	input logic in,
	input logic load,
	output logic out
);
	logic mux_out;
	Mux mux(
		.a(out),
		.b(in),
		.sel(load),
		.out(mux_out)
	);

	DFF dff(
		.clk(clk),
		.in(mux_out),
		.out(out)
	);
endmodule
