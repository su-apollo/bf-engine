#include "sample-gl.hpp"


/*
SampleGL::SampleGL() {
}

SampleGL::~SampleGL() {
}

void SampleGL::InitRendering() {
	//SetTitle("GL Rendering");

	//shader = bf::MakeGLSLFromFile("", "");
}

void SampleGL::InitUI() {
}

void SampleGL::Draw() {
}

void SampleGL::DrawUI() {
}
*/

bf::BasicApp* bf::MakeApp() {
	return new SampleGL();
}