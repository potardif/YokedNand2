#include "VNot16.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VNot16* device) {
	printf("| %016b | %016b |\n", device->in, device->out);
}

int main() {
	auto device = new VNot16;

	printf("|        in        |       out        |\n");



	device->in = 0b0000000000000000;
	device->eval();
	output(device);

	device->in = 0b1111111111111111;
	device->eval();
	output(device);

	device->in = 0b1010101010101010;
	device->eval();
	output(device);

	device->in = 0b0011110011000011;
	device->eval();
	output(device);

	device->in = 0b0001001000110100;
	device->eval();
	output(device);


	delete device;
	return 0;
}
