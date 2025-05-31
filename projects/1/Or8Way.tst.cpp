#include "VOr8Way.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(VOr8Way* device) {
	printf("|  %08b  | %01b |\n", device->in, device->out);
}

int main() {
	auto device = new VOr8Way;

	printf("|     in     |out|\n");



	device->in = 0b00000000;
	device->eval();
	output(device);

	device->in = 0b11111111;
	device->eval();
	output(device);

	device->in = 0b00010000;
	device->eval();
	output(device);

	device->in = 0b00000001;
	device->eval();
	output(device);

	device->in = 0b00100110;
	device->eval();
	output(device);


	delete device;
	return 0;
}
