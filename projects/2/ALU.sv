module ALU(
	input logic [msb:lsb] x,
	input logic [msb:lsb] y,
	input logic zx,
	input logic nx,
	input logic zy,
	input logic ny,
	input logic f,
	input logic no,
	output logic [msb:lsb] out,
	output logic zr,
	output logic ng
);
	localparam lsb = 0;
	localparam msb = 15;

	logic [msb:lsb] in [0:1];
	assign in[0] = x;
	assign in[1] = y;

	logic z [0:1];
	assign z[0] = zx;
	assign z[1] = zy;

	logic n [0:1];
	assign n[0] = nx;
	assign n[1] = ny;

	logic [msb:lsb] operands [0:1];

	for (genvar i = 0; i <= 1; ++i)
	begin : operands_loop
		logic [msb:lsb] mux_z_out;
		Mux16 mux_z(
			.a(in[i]),
			.b(0),
			.sel(z[i]),
			.out(mux_z_out)
		);

		logic [msb:lsb] not_mux_z_out;
		Not16 not_mux_z(
			.in(mux_z_out),
			.out(not_mux_z_out)
		);

		Mux16 mux_n(
			.a(mux_z_out),
			.b(not_mux_z_out),
			.sel(n[i]),
			.out(operands[i])
		);
	end

	logic [msb:lsb] x_and_y;
	And16 and_operands(
		.a(operands[0]),
		.b(operands[1]),
		.out(x_and_y)
	);

	logic [msb:lsb] x_plus_y;
	Add16 add_operands(
		.a(operands[0]),
		.b(operands[1]),
		.out(x_plus_y)
	);

	logic [msb:lsb] mux_f_out;
	Mux16 mux_f(
		.a(x_and_y),
		.b(x_plus_y),
		.sel(f),
		.out(mux_f_out)
	);

	logic [msb:lsb] not_mux_f_out;
	Not16 not_mux_f(
		.in(mux_f_out),
		.out(not_mux_f_out)
	);

	Mux16 mux_no(
		.a(mux_f_out),
		.b(not_mux_f_out),
		.sel(no),
		.out(out)
	);

	// Zero flag

	logic or1_out;
	Or8Way or1(
		.in(out[msb / 2 : lsb]),
		.out(or1_out)
	);
	
	logic or2_out;
	Or8Way or2(
		.in(out[msb : msb / 2 + 1]),
		.out(or2_out)
	);

	logic or3_out;
	Or or3(
		.a(or1_out),
		.b(or2_out),
		.out(or3_out)
	);

	Not not_or3(
		.in(or3_out),
		.out(zr)
	);

	// Negative flag

	assign ng = out[msb];
endmodule
