#include "VFullAdder.h"

void output(VFullAdder* device) {
	printf("| %01b | %01b | %01b | %01b |  %01b  |\n", device->a, device->b, device->c, device->sum, device->carry);
}

int main() {
	auto device = new VFullAdder;

	printf("| a | b | c |sum|carry|\n");



	device->a = 0;
	device->b = 0;
	device->c = 0;
	device->eval();
	output(device);

	device->c = 1;
	device->eval();
	output(device);

	device->b = 1;
	device->c = 0;
	device->eval();
	output(device);

	device->c = 1;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 0;
	device->c = 0;
	device->eval();
	output(device);

	device->c = 1;
	device->eval();
	output(device);

	device->b = 1;
	device->c = 0;
	device->eval();
	output(device);

	device->c = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
