#include "VAdd16.h"

void output(VAdd16* device) {
	printf("| %016b | %016b | %016b |\n", device->a, device->b, device->out);
}

int main() {
	auto device = new VAdd16;

	printf("|        a         |        b         |       out        |\n");



	device->a = 0b0000000000000000;
	device->b = 0b0000000000000000;
	device->eval();
	output(device);

	device->a = 0b0000000000000000;
	device->b = 0b1111111111111111;
	device->eval();
	output(device);

	device->a = 0b1111111111111111;
	device->b = 0b1111111111111111;
	device->eval();
	output(device);

	device->a = 0b1010101010101010;
	device->b = 0b0101010101010101;
	device->eval();
	output(device);

	device->a = 0b0011110011000011;
	device->b = 0b0000111111110000;
	device->eval();
	output(device);

	device->a = 0b0001001000110100;
	device->b = 0b1001100001110110;
	device->eval();
	output(device);


	delete device;
	return 0;
}
