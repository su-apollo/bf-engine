#include "renderer-opengl.hpp"

#define GLEW_STATIC
#include <GL/glew.h>
#ifdef _WIN32
#include <GL/wglew.h>
#else
#include <GL/glxew.h>
#endif

#include <GLFW/linmath.h>
#include <chrono>

namespace bf {
static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};

static const char* vertex_shader_text =
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* fragment_shader_text =
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";

bool opengl::initialize()
{
	const auto err = glewInit();
	if (GLEW_OK != err)
		return false;

	glGenBuffers(1, &vertex_buffer_);

	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	vertex_buffer_ = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertex_buffer_, 1, &vertex_shader_text, nullptr);
	glCompileShader(vertex_buffer_);
	fragment_shader_ = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment_shader_, 1, &fragment_shader_text, nullptr);
	glCompileShader(fragment_shader_);

	program_ = glCreateProgram();

	glAttachShader(program_, vertex_shader_);
	glAttachShader(program_, fragment_shader_);
	glLinkProgram(program_);

	mvp_location_ = glGetUniformLocation(program_, "MVP");
	vpos_location_ = glGetAttribLocation(program_, "vPos");
	vcol_location_ = glGetAttribLocation(program_, "vCol");

	glEnableVertexAttribArray(vpos_location_);
	glVertexAttribPointer(vcol_location_, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, static_cast<void*>(nullptr));
	glEnableVertexAttribArray(vcol_location_);
	glVertexAttribPointer(vcol_location_, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, reinterpret_cast<void*>(sizeof(float) * 2));

	return true;
}

void opengl::reshape(const float width, const float height)
{
	width_ = width;
	height_ = height;
}

void opengl::test_draw()
{
	const auto ratio = width_ / static_cast<float>(height_);
    mat4x4 m, p, mvp;

    glViewport(0, 0, width_, height_);
    glClear(GL_COLOR_BUFFER_BIT);
    mat4x4_identity(m);

    const auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    mat4x4_rotate_Z(m, m, static_cast<float>(time));
    mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    mat4x4_mul(mvp, p, m);
    glUseProgram(program_);
    glUniformMatrix4fv(mvp_location_, 1, GL_FALSE, reinterpret_cast<const GLfloat*>(mvp));
    glDrawArrays(GL_TRIANGLES, 0, 3);
}	
}
