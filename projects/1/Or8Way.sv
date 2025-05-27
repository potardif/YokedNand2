module Or8Way(
	input logic [7:0] in,
	output logic out
);
	logic or1_out;
	Or or1(
		.a(in[0]),
		.b(in[1]),
		.out(or1_out)
	);

	logic or2_out;
	Or or2(
		.a(in[2]),
		.b(in[3]),
		.out(or2_out)
	);

	logic or3_out;
	Or or3(
		.a(in[4]),
		.b(in[5]),
		.out(or3_out)
	);

	logic or4_out;
	Or or4(
		.a(in[6]),
		.b(in[7]),
		.out(or4_out)
	);

	logic or5_out;
	Or or5(
		.a(or1_out),
		.b(or2_out),
		.out(or5_out)
	);

	logic or6_out;
	Or or6(
		.a(or3_out),
		.b(or4_out),
		.out(or6_out)
	);

	Or or7(
		.a(or5_out),
		.b(or6_out),
		.out(out)
	);
endmodule
