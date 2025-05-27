#include "VDMux4Way.h"

void output(VDMux4Way* device) {
	printf("| %01b |  %02b  | %01b | %01b | %01b | %01b |\n", device->in, device->sel, device->a, device->b, device->c, device->d);
}

int main() {
	auto device = new VDMux4Way;

	printf("|in | sel  | a | b | c | d |\n");



	device->in = 0;
	device->sel = 0b00;
	device->eval();
	output(device);

	device->sel = 0b01;
	device->eval();
	output(device);

	device->sel = 0b10;
	device->eval();
	output(device);

	device->sel = 0b11;
	device->eval();
	output(device);

	device->in = 1;
	device->sel = 0b00;
	device->eval();
	output(device);

	device->sel = 0b01;
	device->eval();
	output(device);

	device->sel = 0b10;
	device->eval();
	output(device);

	device->sel = 0b11;
	device->eval();
	output(device);


	delete device;
	return 0;
}
