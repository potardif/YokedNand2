#include "VALU.h"

void output(VALU* device) {
	printf("| %016b | %016b | %01b | %01b | %01b | %01b | %01b | %01b | %016b |\n", device->x, device->y, device->zx, device->nx, device->zy, device->ny, device->f, device->no, device->out);
}

int main() {
	auto device = new VALU;

	printf("|        x         |        y         |zx |nx |zy |ny | f |no |       out        |\n");




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

	device->x = 0b101101110100000;
	device->y = 0b001111011010010;

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
