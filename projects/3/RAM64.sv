module RAM64(
	input logic clk,
	input logic [msb:lsb] in,
	input logic load,
	input logic [5:0] address,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;

	logic loads [0:7];
	DMux8Way dmux(
		.in(load),
		.sel(address[5:3]),
		.a(loads[0]),
		.b(loads[1]),
		.c(loads[2]),
		.d(loads[3]),
		.e(loads[4]),
		.f(loads[5]),
		.g(loads[6]),
		.h(loads[7])
	);

	logic [msb:lsb] register_outs [0:7];
	for (genvar i = 0; i <= 7; ++i)
	begin : ram8_loop
		RAM8 ram8(
			.clk(clk),
			.in(in),
			.load(loads[i]),
			.address(address[2:0]),
			.out(register_outs[i])
		);
	end

	Mux8Way16 mux(
		.a(register_outs[0]),
		.b(register_outs[1]),
		.c(register_outs[2]),
		.d(register_outs[3]),
		.e(register_outs[4]),
		.f(register_outs[5]),
		.g(register_outs[6]),
		.h(register_outs[7]),
		.sel(address[5:3]),
		.out(out)
	);
endmodule
