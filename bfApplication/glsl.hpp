#pragma once
#include "allocator.hpp"

#include <GL/glew.h>

namespace bf {
class GLSL {
public:
	GLSL();
	~GLSL();

	bool SetSourceFromFiles(const string& vert_filename, const string& frag_filename, bool strict = false);
	bool SetSourceFromStrings(const char* vert_src, const char* frag_src, bool strict = false);

private:
	bool CheckCompileError(GLuint object, int target);
	GLuint CompileProgram(const char* vsource, const char* fsource);

	bool strict;
	GLuint program;
	static const char* shader_header;
};

extern shared_ptr<GLSL> MakeGLSLFromFile(const string& vert_filename, const string& frag_filename);
}