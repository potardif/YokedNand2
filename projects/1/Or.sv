module Or(
	input logic a,
	input logic b,
	output logic out
);
	logic not_a_out;
	Not not_a(
		.in(a),
		.out(not_a_out)
	);

	logic not_b_out;
	Not not_b(
		.in(b),
		.out(not_b_out)
	);

	Nand nand_(
		.a(not_a_out),
		.b(not_b_out),
		.out(out)
	);
endmodule
