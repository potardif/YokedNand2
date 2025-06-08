#include "VDMux8Way.h"

int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}

void output(const VDMux8Way* device) {
	printf("| %01b |  %03b  | %01b | %01b | %01b | %01b | %01b | %01b | %01b | %01b |\n", device->in, device->sel, device->a, device->b, device->c, device->d, device->e, device->f, device->g, device->h);
}

int main() {
	auto device = new VDMux8Way;

	printf("|in |  sel  | a | b | c | d | e | f | g | h |\n");



	device->in = 0;
	device->sel = 0b000;
	device->eval();
	output(device);

	device->sel = 0b001;
	device->eval();
	output(device);

	device->sel = 0b010;
	device->eval();
	output(device);

	device->sel = 0b011;
	device->eval();
	output(device);

	device->sel = 0b100;
	device->eval();
	output(device);

	device->sel = 0b101;
	device->eval();
	output(device);

	device->sel = 0b110;
	device->eval();
	output(device);

	device->sel = 0b111;
	device->eval();
	output(device);

	device->in = 1;
	device->sel = 0b000;
	device->eval();
	output(device);

	device->sel = 0b001;
	device->eval();
	output(device);

	device->sel = 0b010;
	device->eval();
	output(device);

	device->sel = 0b011;
	device->eval();
	output(device);

	device->sel = 0b100;
	device->eval();
	output(device);

	device->sel = 0b101;
	device->eval();
	output(device);

	device->sel = 0b110;
	device->eval();
	output(device);

	device->sel = 0b111;
	device->eval();
	output(device);


	delete device;
	return 0;
}
