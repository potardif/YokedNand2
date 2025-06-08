#include "VNot.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VNot* device) {
	printf("| %01b | %01b |\n", device->in, device->out);
}

int main() {
	auto device = new VNot;

	printf("|in |out|\n");



	device->in = 0;
	device->eval();
	output(device);

	device->in = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
