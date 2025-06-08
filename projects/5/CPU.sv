module CPU(
	input logic clk,
	input logic [15:0] inM,
	input logic [15:0] instruction,
	input logic reset,
	output logic [15:0] outM,
	output logic writeM,
	output logic [14:0] addressM,
	output logic [14:0] pc
);
	// Note that I use elementary operators (~, &, |) instead of their corresponding gates. You can
	// argue it's not in the spirit of the book, but I think it would only clutter the code to
	// instantiate every single gate.

	logic [15:0] A_in;
	Mux16 mux_A(
		.a({1'b0, instruction[14:0]}), // If it's an A-instr, take the constant in the instr.
		.b(outM), // If it's a C-instr, take the output of the ALU.
		.sel(instruction[15]),
		.out(A_in)
	);

	logic [15:0] A_out;
	Register A(
		.clk(clk),
		.in(A_in),
		.load(~instruction[15] | instruction[5]), // If A-instr or C-instr with dest A.
		.out(A_out)
	);

	logic [15:0] D_out;
	Register D(
		.clk(clk),
		.in(outM), // The output of the ALU.
		.load(instruction[15] & instruction[4]), // If C-instr with dest D.
		.out(D_out)
	);

	logic [15:0] mux_a_out; // Choose A or M as the second operand of the ALU.
	Mux16 mux_a(
		.a(A_out), // A
		.b(inM), // M
		.sel(instruction[12]), // a
		.out(mux_a_out)
	);

	logic zr;
	logic ng;
	ALU ALU(
		.x(D_out),
		.y(mux_a_out),
		.zx(instruction[11]),
		.nx(instruction[10]),
		.zy(instruction[9]),
		.ny(instruction[8]),
		.f(instruction[7]),
		.no(instruction[6]),
		.out(outM),
		.zr(zr),
		.ng(ng)
	);

	PC PC(
		.clk(clk),
		.in(A_out), // A
		.inc(1),
		.load(
			// If C-instr with a jump.
			instruction[15] & (
				instruction[2] & ng
				| instruction[1] & zr
				| instruction[0] & ~ng & ~zr
			)
		),
		.reset(reset),
		/* verilator lint_off WIDTHEXPAND */
		.out(pc)
		/* verilator lint_on WIDTHEXPAND */
	);

	assign writeM = instruction[15] & instruction[3]; // If C-instr with dest RAM[A].
	assign addressM = A_out[14:0];
endmodule
