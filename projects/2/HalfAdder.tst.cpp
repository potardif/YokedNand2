#include "VHalfAdder.h"

int time_ = 0;

std::string fmt_time() {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(6 - s.length(), ' ');
	return s;
}

void output(VHalfAdder* device) {
	printf("| %01b | %01b | %01b | %01b |\n", device->a, device->b, device->sum, device->carry);
}

int main() {
	auto device = new VHalfAdder;

	printf("| a | b |sum|car|\n");



	device->a = 0;
	device->b = 0;
	device->eval();
	output(device);

	device->a = 0;
	device->b = 1;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 0;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
