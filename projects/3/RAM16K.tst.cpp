#include "VRAM16K.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VRAM16K* device) {
	printf("|%s| %6d |  %01b |  %5d  | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->load, static_cast<int16_t>(device->address), static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VRAM16K;

	printf("|time |   in   |load| address |  out   |\n");



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

	device->in = 4321;
	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 4321;
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

	device->in = 12345;
	device->address = 12345;
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

	device->address = 4321;
	device->eval();
	output(device);

	device->in = 16383;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 16383;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->address = 12345;
	device->eval();
	output(device);

	device->address = 16383;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101000;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101000;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101001;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101010;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101010;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101011;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101011;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101100;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101100;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101110;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101110;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101111;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10101010101111;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b10101010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10101010101001;
	device->eval();
	output(device);
	device->address = 0b10101010101010;
	device->eval();
	output(device);
	device->address = 0b10101010101011;
	device->eval();
	output(device);
	device->address = 0b10101010101100;
	device->eval();
	output(device);
	device->address = 0b10101010101101;
	device->eval();
	output(device);
	device->address = 0b10101010101110;
	device->eval();
	output(device);
	device->address = 0b10101010101111;
	device->eval();
	output(device);


	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b01010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b01110101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10110101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b11010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b11110101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b00010101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b00010101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b00110101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b01010101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b01010101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b01110101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b01110101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10010101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10010101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b10110101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b10110101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b11010101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b11010101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b11110101010101;
	device->in = 0b1010101010101010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0b11110101010101;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->address = 0b00010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 0b00110101010101;
	device->eval();
	output(device);
	device->address = 0b01010101010101;
	device->eval();
	output(device);
	device->address = 0b01110101010101;
	device->eval();
	output(device);
	device->address = 0b10010101010101;
	device->eval();
	output(device);
	device->address = 0b10110101010101;
	device->eval();
	output(device);
	device->address = 0b11010101010101;
	device->eval();
	output(device);
	device->address = 0b11110101010101;
	device->eval();
	output(device);


	delete device;
	return 0;
}
