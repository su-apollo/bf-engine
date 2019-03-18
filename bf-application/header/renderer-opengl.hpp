#pragma once
#include "app-context.hpp"

namespace bf {
class opengl : public graphic_library  {
public:
	opengl() = default;
	bool initialize() override;
	void reshape(const float width, const float height) override;
	void test_draw() override;

private:
	float width_;
	float height_;

	unsigned int vertex_buffer_;
	unsigned int vertex_shader_;
	unsigned int fragment_shader_;
	unsigned int program_;

	int mvp_location_;
	int vpos_location_;
	int vcol_location_;
};	
}