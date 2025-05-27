module Not(
	input logic in,
	output logic out
);
	Nand nand_(
		.a(in),
		.b(in),
		.out(out)
	);
endmodule
