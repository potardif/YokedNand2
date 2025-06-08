#include "VOr.h"





void output(const VOr* device) {
	printf("| %01b | %01b | %01b |\n", device->a, device->b, device->out);
}

int main() {
	auto device = new VOr;

	printf("| a | b |out|\n");



	device->a = 0;
	device->b = 0;
	device->eval();
	output(device);

	device->a = 0;
	device->b = 1;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 0;
	device->eval();
	output(device);

	device->a = 1;
	device->b = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
