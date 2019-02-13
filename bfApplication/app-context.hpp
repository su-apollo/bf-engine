#pragma once
#include "platform.hpp"

namespace bf {	

class AppContextBase {
public:
	virtual ~AppContextBase() = 0;

	virtual bool BindContext() = 0;
	virtual bool UnbindContext() = 0;

	virtual int Width() = 0;
	virtual int Height() = 0;

	virtual bool Swap() = 0;

public:
	virtual void ContextInitRendering() {};
	virtual void PlatformReshape(const size_t w, const size_t h) {};

	virtual void BeginFrame() {};
	virtual void BeginScene() {};
	virtual void EndScene() {};
	virtual void EndFrame() { Swap(); };
};

template <class P>
class BasicAppContext : public AppContextBase {
	static_assert(std::is_convertible<P, Platform>::value, "Application platform type error.");
public:
};
}
