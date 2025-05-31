#include "VALU.h"

int time_ = 0;

std::string fmt_time() {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(6 - s.length(), ' ');
	return s;
}

void output(VALU* device) {
	printf("| %016b | %016b | %01b | %01b | %01b | %01b | %01b | %01b | %016b | %01b | %01b |\n", device->x, device->y, device->zx, device->nx, device->zy, device->ny, device->f, device->no, device->out, device->zr, device->ng);
}

int main() {
	auto device = new VALU;

	printf("|        x         |        y         |zx |nx |zy |ny | f |no |       out        |zr |ng |\n");



	device->x = 0b0000000000000000;
	device->y = 0b1111111111111111;

	device->zx = 1;
	device->nx = 0;
	device->zy = 1;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 1;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 0;
	device->ny = 1;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);

	device->x = 0b000000000010001;
	device->y = 0b000000000000011;

	device->zx = 1;
	device->nx = 0;
	device->zy = 1;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 1;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 1;
	device->ny = 1;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 1;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 0;
	device->ny = 0;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 1;
	device->f = 1;
	device->no = 1;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 0;
	device->zy = 0;
	device->ny = 0;
	device->f = 0;
	device->no = 0;
	device->eval();
	output(device);

	device->zx = 0;
	device->nx = 1;
	device->zy = 0;
	device->ny = 1;
	device->f = 0;
	device->no = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
