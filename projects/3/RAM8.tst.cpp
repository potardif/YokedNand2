#include "VRAM8.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VRAM8* device) {
	printf("|%s| %6d |  %01b |   %1d   | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->load, static_cast<int16_t>(device->address), static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VRAM8;

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

	device->in = 11111;
	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 1;
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

	device->in = 3333;
	device->address = 3;
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

	device->address = 1;
	device->eval();
	output(device);

	device->in = 7777;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->address = 7;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->address = 3;
	device->eval();
	output(device);

	device->address = 7;
	device->eval();
	output(device);

	device->load = 0;
	device->address = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->in = 0b0101010101010101;
	device->address = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 2;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 3;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 4;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 5;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 6;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 7;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 0;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 1;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 1;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 2;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 2;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 3;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 3;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 4;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 4;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 5;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 5;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 6;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 6;
	device->in = 0b0101010101010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);
	device->address = 7;
	device->in = 0b1010101010101010;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);

	device->load = 1;
	device->address = 7;
	device->in = 0b0101010101010101;
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
	device->address = 1;
	device->eval();
	output(device);
	device->address = 2;
	device->eval();
	output(device);
	device->address = 3;
	device->eval();
	output(device);
	device->address = 4;
	device->eval();
	output(device);
	device->address = 5;
	device->eval();
	output(device);
	device->address = 6;
	device->eval();
	output(device);
	device->address = 7;
	device->eval();
	output(device);



	delete device;
	return 0;
}
