#include "VXor.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VXor* device) {
	printf("| %01b | %01b | %01b |\n", device->a, device->b, device->out);
}

int main() {
	auto device = new VXor;

	printf("| a | b |out|\n");



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
