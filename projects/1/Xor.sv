module Xor(
	input logic a,
	input logic b,
	output logic out
);
	logic a_or_b;
	Or or_(
		.a(a),
		.b(b),
		.out(a_or_b)
	);

	logic a_nand_b;
	Nand nand_(
		.a(a),
		.b(b),
		.out(a_nand_b)
	);

	And and_(
		.a(a_or_b),
		.b(a_nand_b),
		.out(out)
	);
endmodule
