module DMux(
	input logic in,
	input logic sel,
	output logic a,
	output logic b
);
	logic not_sel;
	Not not_(
		.in(sel),
		.out(not_sel)
	);

	And and1(
		.a(in),
		.b(not_sel),
		.out(a)
	);

	And and2(
		.a(in),
		.b(sel),
		.out(b)
	);
endmodule
