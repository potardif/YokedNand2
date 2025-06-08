#include "VMux8Way16.h"



void output(const VMux8Way16* device) {
	printf("| %016b | %016b | %016b | %016b | %016b | %016b | %016b | %016b |  %03b  | %016b |\n", device->a, device->b, device->c, device->d, device->e, device->f, device->g, device->h, device->sel, device->out);
}

int main() {
	auto device = new VMux8Way16;

	printf("|        a         |        b         |        c         |        d         |        e         |        f         |        g         |        h         |  sel  |       out        |\n");



	device->a = 0;
	device->b = 0;
	device->c = 0;
	device->d = 0;
	device->e = 0;
	device->f = 0;
	device->g = 0;
	device->h = 0;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->sel = 2;
	device->eval();
	output(device);

	device->sel = 3;
	device->eval();
	output(device);

	device->sel = 4;
	device->eval();
	output(device);

	device->sel = 5;
	device->eval();
	output(device);

	device->sel = 6;
	device->eval();
	output(device);

	device->sel = 7;
	device->eval();
	output(device);

	device->a = 0b0001001000110100;
	device->b = 0b0010001101000101;
	device->c = 0b0011010001010110;
	device->d = 0b0100010101100111;
	device->e = 0b0101011001111000;
	device->f = 0b0110011110001001;
	device->g = 0b0111100010011010;
	device->h = 0b1000100110101011;
	device->sel = 0;
	device->eval();
	output(device);

	device->sel = 1;
	device->eval();
	output(device);

	device->sel = 2;
	device->eval();
	output(device);

	device->sel = 3;
	device->eval();
	output(device);

	device->sel = 4;
	device->eval();
	output(device);

	device->sel = 5;
	device->eval();
	output(device);

	device->sel = 6;
	device->eval();
	output(device);

	device->sel = 7;
	device->eval();
	output(device);


	delete device;
	return 0;
}
