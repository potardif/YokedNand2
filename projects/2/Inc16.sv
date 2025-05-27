module Inc16(
	input logic [msb:lsb] in,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	logic carries [lsb:msb];
	assign carries[lsb] = 1;

	for (genvar i = lsb; i <= msb; ++i)
	begin : adder_loop
		HalfAdder ha(
			.a(in[i]),
			.b(carries[i]),
			.sum(out[i]),
			.carry(carries[i + 1])
		);
	end
endmodule
