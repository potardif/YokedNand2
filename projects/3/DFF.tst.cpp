#include "VDFF.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VDFF* device) {
	printf("|%s| %01b | %01b |\n", fmt_time(6).c_str(), device->in, device->out);
}

int main() {
	auto device = new VDFF;

	printf("| time |in |out|\n");


	device->eval();
	output(device);

	device->in = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 0;
	device->eval();
	output(device);

	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);


	delete device;
	return 0;
}
