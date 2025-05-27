module HalfAdder(
	input logic a,
	input logic b,
	output logic sum,
	output logic carry
);
	Xor xor_(
		.a(a),
		.b(b),
		.out(sum)
	);

	And and_(
		.a(a),
		.b(b),
		.out(carry)
	);
endmodule
