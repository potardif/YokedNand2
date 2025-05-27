module DMux8Way(
	input logic in,
	input logic [2:0] sel,
	output logic a,
	output logic b,
	output logic c,
	output logic d,
	output logic e,
	output logic f,
	output logic g,
	output logic h
);
	logic dmux_abcd_out;
	logic dmux_efgh_out;
	DMux dmux_abcdefgh(
		.in(in),
		.sel(sel[2]),
		.a(dmux_abcd_out),
		.b(dmux_efgh_out)
	);

	DMux4Way dmux_abcd(
		.in(dmux_abcd_out),
		.sel(sel[1:0]),
		.a(a),
		.b(b),
		.c(c),
		.d(d)
	);

	DMux4Way dmux_efgh(
		.in(dmux_efgh_out),
		.sel(sel[1:0]),
		.a(e),
		.b(f),
		.c(g),
		.d(h)
	);
endmodule
