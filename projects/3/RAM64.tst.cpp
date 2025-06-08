#include "VRAM64.h"


int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}




void output(const VRAM64* device) {
	printf("|%s| %6d |  %01b |  %3d  | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->load, static_cast<int16_t>(device->address), static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VRAM64;

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

	device->in = 1313;
	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 13;
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

	device->in = 4747;
	device->address = 47;
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

	device->address = 13;
	device->eval();
	output(device);

	device->in = 6363;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 63;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->address = 47;
	device->eval();
	output(device);

	device->address = 63;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101000;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101000;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101001;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101011;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101011;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101100;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101100;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101110;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101110;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101111;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101111;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101001;
	device->eval();
	output(device);
	device->address = 0b101010;
	device->eval();
	output(device);
	device->address = 0b101011;
	device->eval();
	output(device);
	device->address = 0b101100;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b101110;
	device->eval();
	output(device);
	device->address = 0b101111;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b011101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b100101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b110101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b111101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b000101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b000101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b001101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b011101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b011101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b100101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b100101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b101101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b101101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b110101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b110101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b111101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b111101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b001101;
	device->eval();
	output(device);
	device->address = 0b010101;
	device->eval();
	output(device);
	device->address = 0b011101;
	device->eval();
	output(device);
	device->address = 0b100101;
	device->eval();
	output(device);
	device->address = 0b101101;
	device->eval();
	output(device);
	device->address = 0b110101;
	device->eval();
	output(device);
	device->address = 0b111101;
	device->eval();
	output(device);


	delete device;
	return 0;
}
