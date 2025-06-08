#include "VCPU.h"

int time_ = 0;

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

void output(VCPU* device) {
	printf("|%s|%6d|%016b|  %01b  |%s|   %01b  | %5d |%5d|\n", fmt_time(5).c_str(), static_cast<int16_t>(device->inM), device->instruction, device->reset, fmt_outM(device).c_str(), device->writeM, static_cast<int16_t>(device->addressM), static_cast<int16_t>(device->pc));
}

int main() {
	auto device = new VCPU;

	printf("|time | inM  |  instruction   |reset| outM  |writeM|address| pc  |\n");




	device->instruction = 0b0011000000111001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110110000010000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0101101110100000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110000111110000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000001111101011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100001000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000001111101100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001110011000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000001111101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1111010011110000;
	device->inM = 11111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000000000001110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000001111100111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1111110111100000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000000000010101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110011111000010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000000000000010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110000010111000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1111110111001000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1111110010101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0000001111101000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110111010010000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110101010010000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110111111010000;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000001;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000010;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000011;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000100;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000101;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000110;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b1110001100000111;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->instruction = 0b0111111111111111;
	device->reset = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);
	device->clk = 1; ++time_; device->eval(); // tock
	output(device);


	delete device;
	return 0;
}
