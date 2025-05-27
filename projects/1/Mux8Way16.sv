module Mux8Way16(
	input logic [msb:lsb] a,
	input logic [msb:lsb] b,
	input logic [msb:lsb] c,
	input logic [msb:lsb] d,
	input logic [msb:lsb] e,
	input logic [msb:lsb] f,
	input logic [msb:lsb] g,
	input logic [msb:lsb] h,
	input logic [2:0] sel,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	logic [msb:lsb] mux_abcd_out;
	Mux4Way16 mux_abcd(
		.a(a),
		.b(b),
		.c(c),
		.d(d),
		.sel(sel[1:0]),
		.out(mux_abcd_out)
	);

	logic [msb:lsb] mux_efgh_out;
	Mux4Way16 mux_efgh(
		.a(e),
		.b(f),
		.c(g),
		.d(h),
		.sel(sel[1:0]),
		.out(mux_efgh_out)
	);

	Mux16 mux_abcdefgh(
		.a(mux_abcd_out),
		.b(mux_efgh_out),
		.sel(sel[2]),
		.out(out)
	);
endmodule
