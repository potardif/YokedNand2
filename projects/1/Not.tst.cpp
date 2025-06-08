#include "VNot.h"





void output(const VNot* device) {
	printf("| %01b | %01b |\n", device->in, device->out);
}

int main() {
	auto device = new VNot;

	printf("|in |out|\n");



	device->in = 0;
	device->eval();
	output(device);

	device->in = 1;
	device->eval();
	output(device);


	delete device;
	return 0;
}
