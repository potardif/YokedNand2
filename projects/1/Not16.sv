module Not16(
	input logic [msb:lsb] in,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	for (genvar i = lsb; i <= msb; ++i)
	begin : not_loop
		Not not_(
			.in(in[i]),
			.out(out[i])
		);
	end
endmodule
