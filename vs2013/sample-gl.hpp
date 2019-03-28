#pragma once
#include <app.hpp>
#include <iostream>

class sample_gl final : public bf::application {
public:
	sample_gl() = default;
	~sample_gl() = default;

	void on_init_rendering() {
		for (const auto& command : command_line_) {
			std::cout << command << std::endl;
		}
	};
};