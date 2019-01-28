#pragma once

namespace bf {
struct GfxConfig {
	GfxConfig(int r = 8, int g = 8,
	int b = 8, int a = 8,
	int d = 24, int s = 0, int msaa = 0)
	: red_bits(r), green_bits(g), blue_bits(b), alpha_bits(a)
	, depth_bits(d), stencil_bits(s), msaa_samples(msaa) {}

	int red_bits;
	int green_bits;
	int blue_bits;
	int alpha_bits;
	int depth_bits;
	int stencil_bits;
	int msaa_samples;
};
}