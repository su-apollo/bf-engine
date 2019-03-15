#pragma once
#include <app.hpp>
#include <iostream>
#include <GL/glew.h>

class sample_gl final : public bf::application {
public:
	sample_gl() = default;
	~sample_gl() = default;

	void on_init_rendering() {
		for (const auto& command : command_line_) {
			std::cout << command << std::endl;
		}
	};

	void on_draw() {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 1.0, 1.0);

		glBegin(GL_QUADS);
		glColor3f (0.0, 0.0, 0.0);

		glVertex3f (0.1, 0.1, 0.0);
		glVertex3f (0.9, 0.1, 0.0);
		glVertex3f (0.9, 0.9, 0.0);
		glVertex3f (0.1, 0.9, 0.0);

		glEnd();

		glFlush();
	};

private:

};