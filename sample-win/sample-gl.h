#pragma once
#include <app-gl.h>
#include <glsl.h>

class SampleGL : public bf::AppGL {
public:
	SampleGL();
	~SampleGL();

	virtual void ConfigurationCallback() {}

	void InitRendering();
	void InitUI();
	void Draw();
	void DrawUI();

private:
	bf::shared_ptr<bf::GLSL> shader;
};
