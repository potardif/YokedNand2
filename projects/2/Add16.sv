module Add16(
	input logic [msb:lsb] a,
	input logic [msb:lsb] b,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	logic carries [lsb + 1:msb];

	HalfAdder ha(
		.a(a[lsb]),
		.b(b[lsb]),
		.sum(out[lsb]),
		.carry(carries[lsb + 1])
	);

	for (genvar i = lsb + 1; i <= msb; ++i)
	begin : adder_loop
		FullAdder fa(
			.a(a[i]),
			.b(b[i]),
			.c(carries[i]),
			.sum(out[i]),
			.carry(carries[i + 1])
		);
	end
endmodule
