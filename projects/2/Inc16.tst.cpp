#include "VInc16.h"

void output(VInc16* device) {
	printf("| %016b | %016b |\n", device->in, device->out);
}

int main() {
	auto device = new VInc16;

	printf("|        in        |       out        |\n");



	device->in = 0b0000000000000000;
	device->eval();
	output(device);

	device->in = 0b1111111111111111;
	device->eval();
	output(device);

	device->in = 0b0000000000000101;
	device->eval();
	output(device);

	device->in = 0b1111111111111011;
	device->eval();
	output(device);


	delete device;
	return 0;
}
