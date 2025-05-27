module Mux16(
	input logic [msb:lsb] a,
	input logic [msb:lsb] b,
	input logic sel,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	for (genvar i = lsb; i <= msb; ++i)
	begin : mux_loop
		Mux mux(
			.a(a[i]),
			.b(b[i]),
			.sel(sel),
			.out(out[i])
		);
	end
endmodule
