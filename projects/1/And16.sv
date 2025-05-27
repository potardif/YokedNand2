module And16(
	input logic [msb:lsb] a,
	input logic [msb:lsb] b,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	for (genvar i = lsb; i <= msb; ++i)
	begin : and_loop
		And and_(
			.a(a[i]),
			.b(b[i]),
			.out(out[i])
		);
	end
endmodule
