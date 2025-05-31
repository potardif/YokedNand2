#include "VDMux.h"

int time_ = 0;

std::string fmt_time() {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(6 - s.length(), ' ');
	return s;
}

void output(VDMux* device) {
	printf("| %01b | %01b | %01b | %01b |\n", device->in, device->sel, device->a, device->b);
}

int main() {
	auto device = new VDMux;

	printf("|in |sel| a | b |\n");



	device->in = 0;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->in = 1;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
