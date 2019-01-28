#pragma once
#include <app-gl.hpp>
#include <glsl.hpp>

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
