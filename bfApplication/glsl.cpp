#include "glsl.hpp"

//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

// todo : log, file io

namespace bf {
const char* GLSL::shader_header = nullptr;

GLSL::GLSL() {
}

GLSL::~GLSL() {
}

bool GLSL::SetSourceFromFiles(const string& vert_filename, const string& frag_filename, bool strict_) {
	std::ifstream vert(vert_filename.c_str());
	std::ifstream frag(frag_filename.c_str());

	if (vert.is_open() && frag.is_open()) {
		stringstream vert_stream;
		stringstream frag_stream;

		vert_stream << vert.rdbuf();
		frag_stream << frag.rdbuf();

		string vert_src(vert_stream.str());
		string frag_src(frag_stream.str());

		return SetSourceFromStrings(vert_src.c_str(), frag_src.c_str(), strict_);
	}

	return false;
}

bool GLSL::SetSourceFromStrings(const char* vert_src, const char* frag_src, bool strict_) {
	if (program) {
		glDeleteProgram(program);
		program = 0;
	}

	strict = strict_;

	program = CompileProgram(vert_src, frag_src);

	return program != 0;
}

bool GLSL::CheckCompileError(GLuint shader, int target)
{
	// check if shader compiled
	GLint compiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

	if (!compiled || strict)
	{
		if (!compiled) {
			std::cerr << "Error compiling shader" << std::endl;
		}
		GLint info_len = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_len);
		if (info_len) {
			char* buf = new char[info_len];
			if (buf) {
				glGetShaderInfoLog(shader, info_len, NULL, buf);
				std::cerr << "Shader log:" << std::endl;
				std::cerr << buf << std::endl;
				delete[] buf;
			}
		}
		if (!compiled) {
			glDeleteShader(shader);
			shader = 0;
			return false;
		}
	}
	return true;
}

GLuint GLSL::CompileProgram(const char* vsource, const char* fsource) {
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* sourceItems[2];
	int sourceCount = 0;
	if (shader_header)
		sourceItems[sourceCount++] = shader_header;
	sourceItems[sourceCount++] = vsource;

	glShaderSource(vertexShader, sourceCount, sourceItems, 0);

	sourceCount = 0;
	if (shader_header)
		sourceItems[sourceCount++] = shader_header;
	sourceItems[sourceCount++] = fsource;

	glShaderSource(fragmentShader, sourceCount, sourceItems, 0);

	glCompileShader(vertexShader);
	if (!CheckCompileError(vertexShader, GL_VERTEX_SHADER))
		return 0;

	glCompileShader(fragmentShader);
	if (!CheckCompileError(fragmentShader, GL_FRAGMENT_SHADER))
		return 0;

	GLuint program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// can be deleted since the program will keep a reference
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glLinkProgram(program);

	// check if program linked
	GLint success = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint bufLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
		if (bufLength) {
			char* buf = new char[bufLength];
			if (buf) {
				glGetProgramInfoLog(program, bufLength, NULL, buf);
				std::cerr << "Could not link program:" << std::endl;
				std::cerr << buf << std::endl;
				delete[] buf;
			}
		}
		glDeleteProgram(program);
		program = 0;
	}

	return program;
}

shared_ptr<GLSL> MakeGLSLFromFile(const string& vert_filename, const string& frag_filename) {
	auto glsl = make_shared<GLSL>();
	glsl->SetSourceFromFiles(vert_filename, frag_filename);
	return glsl;
}
}