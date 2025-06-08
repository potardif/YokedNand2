#include "VRegister.h"


int time_ = 0;

void tick(VRegister* device) {
	device->clk = 0;
	++time_;
	device->eval();
}

void tock(VRegister* device) {
	device->clk = 1;
	++time_;
	device->eval();
}

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}




void output(const VRegister* device) {
	printf("|%s| %6d |  %01b | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->load, static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VRegister;

	printf("|time |   in   |load|  out   |\n");



	device->in = 0;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0;
	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = -32123;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 11111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = -32123;
	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = -32123;
	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = -32123;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 12345;
	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0;
	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000000001;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000000010;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000000100;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000001000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000010000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000000100000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000001000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000010000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000000100000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000001000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000010000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0000100000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0001000000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0010000000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0100000000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1000000000000000;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111111110;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111111101;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111111011;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111110111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111101111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111111011111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111110111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111101111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111111011111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111110111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111101111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1111011111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1110111111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1101111111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b1011111111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->in = 0b0111111111111111;
	device->load = 0;
	tick(device);
	output(device);

	tock(device);
	output(device);

	device->load = 1;
	tick(device);
	output(device);

	tock(device);
	output(device);


	delete device;
	return 0;
}
