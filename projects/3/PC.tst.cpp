#include "VPC.h"


int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}




void output(const VPC* device) {
	printf("|%s| %6d |  %01b  |  %01b  |  %01b  | %6d |\n", fmt_time(5).c_str(), static_cast<int16_t>(device->in), device->reset, device->load, device->inc, static_cast<int16_t>(device->out));
}

int main() {
	auto device = new VPC;

	printf("|time |   in   |reset|load | inc |  out   |\n");



	device->in = 0;
	device->reset = 0;
	device->load = 0;
	device->inc = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->inc = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = -32123;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 12345;
	device->load = 1;
	device->inc = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 0;
	device->inc = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 0;
	device->load = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->reset = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 0;
	device->reset = 0;
	device->load = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->load = 0;
	device->inc = 1;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);

	device->in = 22222;
	device->reset = 1;
	device->inc = 0;
	device->clk = 0; ++time_; device->eval(); // tick
	output(device);

	device->clk = 1; ++time_; device->eval(); // tock
	output(device);


	delete device;
	return 0;
}
