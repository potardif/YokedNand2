#include "VCPU.h"


int time_ = 0;

void tick(VCPU* device) {
	device->clk = 0;
	++time_;
	device->eval();
}

void tock(VCPU* device) {
	device->clk = 1;
	++time_;
	device->eval();
}

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}



std::string fmt_outM(const VCPU* device) {
	if (!device->writeM)
		return "*******";

	std::string right = std::to_string(static_cast<int16_t>(device->outM));

	std::string left;
	left.append(7 - right.length(), ' ');

	return left + right;
}


void output(const VCPU* device) {
	printf("|%s|%6d|%016b|  %01b  |%s|   %01b  | %5d |%5d|\n", fmt_time(5).c_str(), static_cast<int16_t>(device->inM), device->instruction, device->reset, fmt_outM(device).c_str(), device->writeM, static_cast<int16_t>(device->addressM), static_cast<int16_t>(device->pc));
}

int main() {
	auto device = new VCPU;

	printf("|time | inM  |  instruction   |reset| outM  |writeM|address| pc  |\n");




	device->instruction = 0b0011000000111001;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110110000010000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0101101110100000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110000111110000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000001111101011;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100001000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000001111101100;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001110011000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000001111101000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1111010011110000;
	device->inM = 11111;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000000000001110;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000100;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000001111100111;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1111110111100000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100101000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000000000010101;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110011111000010;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000000000000010;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110000010111000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1111110111001000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1111110010101000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0000001111101000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110111010010000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000001;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000010;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000011;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000100;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000101;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000110;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000111;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110101010010000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000001;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000010;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000011;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000100;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000101;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000110;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000111;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110111111010000;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000001;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000010;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000011;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000100;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000101;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000110;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b1110001100000111;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->reset = 1;
	tick(device);
	output(device);
	tock(device);
	output(device);

	device->instruction = 0b0111111111111111;
	device->reset = 0;
	tick(device);
	output(device);
	tock(device);
	output(device);


	delete device;
	return 0;
}
