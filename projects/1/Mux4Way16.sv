module Mux4Way16(
	input logic [msb:lsb] a,
	input logic [msb:lsb] b,
	input logic [msb:lsb] c,
	input logic [msb:lsb] d,
	input logic [1:0] sel,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	logic [msb:lsb] mux_ab_out;
	Mux16 mux_ab(
		.a(a),
		.b(b),
		.sel(sel[0]),
		.out(mux_ab_out)
	);

	logic [msb:lsb] mux_cd_out;
	Mux16 mux_cd(
		.a(c),
		.b(d),
		.sel(sel[0]),
		.out(mux_cd_out)
	);

	Mux16 mux_abcd(
		.a(mux_ab_out),
		.b(mux_cd_out),
		.sel(sel[1]),
		.out(out)
	);
endmodule
