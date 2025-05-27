module DMux4Way(
	input logic in,
	input logic [1:0] sel,
	output logic a,
	output logic b,
	output logic c,
	output logic d
);
	logic dmux_ab_out;
	logic dmux_cd_out;
	DMux dmux_abcd(
		.in(in),
		.sel(sel[1]),
		.a(dmux_ab_out),
		.b(dmux_cd_out)
	);

	DMux dmux_ab(
		.in(dmux_ab_out),
		.sel(sel[0]),
		.a(a),
		.b(b)
	);

	DMux dmux_cd(
		.in(dmux_cd_out),
		.sel(sel[0]),
		.a(c),
		.b(d)
	);
endmodule
