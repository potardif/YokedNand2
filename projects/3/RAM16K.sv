module RAM16K(
	input logic clk,
	input logic [msb:lsb] in,
	input logic load,
	input logic [k-1:0] address,
	output logic [msb:lsb] out
);
	localparam lsb = 0;
	localparam msb = 15;
	localparam k = 14;

	logic [msb:lsb] mem [2**k];

	always_ff @(posedge clk)
	begin
		if (load)
			mem[address] <= in;
	end

	assign out = mem[address];

	// This chip is not implemented using four RAM4Ks because this approach was already not scaling
	// for RAM4K in Verilator.
endmodule
