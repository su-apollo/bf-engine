#pragma once
#include <app.hpp>
#include <iostream>

class SampleGL : public bf::App {
public:
	SampleGL() = default;
	~SampleGL() = default;

	void OnInitRendering() {
		for (auto command : command_line) {
			std::cout << command << std::endl;
		}
	};

	void OnDraw() {
	};

private:
};