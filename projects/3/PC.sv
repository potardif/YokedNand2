module PC(
	input logic clk,
	input logic [15:0] in,
	input logic inc,
	input logic load,
	input logic reset,
	output logic [15:0] out
);
	logic [15:0] incremented;
	Inc16 inc16(
		.in(out),
		.out(incremented)
	);

	logic [15:0] mux_inc_out;
	Mux16 mux_inc(
		.a(out),
		.b(incremented),
		.sel(inc),
		.out(mux_inc_out)
	);

	logic [15:0] mux_load_out;
	Mux16 mux_load(
		.a(mux_inc_out),
		.b(in),
		.sel(load),
		.out(mux_load_out)
	);

	logic [15:0] mux_reset_out;
	Mux16 mux_reset(
		.a(mux_load_out),
		.b(0),
		.sel(reset),
		.out(mux_reset_out)
	);

	Register register(
		.clk(clk),
		.in(mux_reset_out),
		.load(1),
		.out(out)
	);
endmodule
