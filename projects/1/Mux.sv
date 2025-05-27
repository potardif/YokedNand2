module Mux(
	input logic a,
	input logic b,
	input logic sel,
	output logic out
);
	logic not_sel;
	Not not_(
		.in(sel),
		.out(not_sel)
	);

	logic a_and_not_sel;
	And and1(
		.a(a),
		.b(not_sel),
		.out(a_and_not_sel)
	);

	logic b_and_sel;
	And and2(
		.a(b),
		.b(sel),
		.out(b_and_sel)
	);

	Or or_(
		.a(a_and_not_sel),
		.b(b_and_sel),
		.out(out)
	);
endmodule
