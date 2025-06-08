#include "VMux16.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VMux16* device) {
	printf("| %016b | %016b | %01b | %016b |\n", device->a, device->b, device->sel, device->out);
}

int main() {
	auto device = new VMux16;

	printf("|        a         |        b         |sel|       out        |\n");



	device->a = 0;
	device->b = 0;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 0b0000000000000000;
	device->b = 0b0001001000110100;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 0b1001100001110110;
	device->b = 0b0000000000000000;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 0b1010101010101010;
	device->b = 0b0101010101010101;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
