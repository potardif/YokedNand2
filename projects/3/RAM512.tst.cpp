#include "VRAM512.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(VRAM512* device) {
	printf("|%s| %6d |  %01b |  %3d  | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->load, static_cast<int16_t>(device->address), static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VRAM512;

	printf("|time |   in   |load|address|  out   |\n");



	device->in = 0;
	device->load = 0;
	device->address = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 13099;
	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 130;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 4729;
	device->address = 472;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->address = 130;
	device->eval();
	output(device);

	device->in = 5119;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 511;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->address = 472;
	device->eval();
	output(device);

	device->address = 511;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101000;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101000;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101001;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101011;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101011;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101100;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101100;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101110;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101110;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101111;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101111;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101001;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b010101011;
	device->eval();
	output(device);
	device->address = 0b010101100;
	device->eval();
	output(device);
	device->address = 0b010101101;
	device->eval();
	output(device);
	device->address = 0b010101110;
	device->eval();
	output(device);
	device->address = 0b010101111;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b011101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b100101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b110101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b111101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b000101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b000101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b001101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b011101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b011101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b100101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b100101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b110101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b110101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b111101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b111101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101010;
	device->eval();
	output(device);
	device->address = 0b010101010;
	device->eval();
	output(device);
	device->address = 0b011101010;
	device->eval();
	output(device);
	device->address = 0b100101010;
	device->eval();
	output(device);
	device->address = 0b101101010;
	device->eval();
	output(device);
	device->address = 0b110101010;
	device->eval();
	output(device);
	device->address = 0b111101010;
	device->eval();
	output(device);



	delete device;
	return 0;
}
