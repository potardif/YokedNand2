module FullAdder(
	input logic a,
	input logic b,
	input logic c,
	output logic sum,
	output logic carry
);
	logic sum1;
	logic carry1;
	HalfAdder ha1(
		.a(a),
		.b(b),
		.sum(sum1),
		.carry(carry1)
	);

	logic carry2;
	HalfAdder ha2(
		.a(sum1),
		.b(c),
		.sum(sum),
		.carry(carry2)
	);

	Or or_(
		.a(carry1),
		.b(carry2),
		.out(carry)
	);
endmodule
