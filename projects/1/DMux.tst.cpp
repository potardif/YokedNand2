#include "VDMux.h"





void output(const VDMux* device) {
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
