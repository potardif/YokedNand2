#include "VMux16.h"

void output(VMux16* device) {
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
