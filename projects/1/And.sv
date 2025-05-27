module And(
	input logic a,
	input logic b,
	output logic out
);
	logic nand_out;
	Nand nand_(
		.a(a),
		.b(b),
		.out(nand_out)
	);

	Not not_(
		.in(nand_out),
		.out(out)
	);
endmodule
