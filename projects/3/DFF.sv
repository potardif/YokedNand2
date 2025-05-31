module DFF(
	input logic clk,
	input logic in,
	output logic out
);
	always_ff @(posedge clk)
		out <= in;
endmodule
