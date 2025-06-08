#include "VMux.h"





void output(const VMux* device) {
	printf("| %01b | %01b | %01b | %01b |\n", device->a, device->b, device->sel, device->out);
}

int main() {
	auto device = new VMux;

	printf("| a | b |sel|out|\n");



	device->a = 0;
	device->b = 0;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 0;
	device->b = 1;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 0;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 1;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
