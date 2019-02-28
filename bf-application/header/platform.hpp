#pragma once

namespace bf {
enum class category {
	mobile,
	desktop
};

enum class os {
	android,
	ios,
	windows,
	linux,
	osx
};

class platform {};

class android : public platform {
public:
	static const auto category = category::mobile;
	static const auto os = os::android;
};

class ios : public platform {
public:
	static const auto category = category::mobile;
	static const auto os = os::ios;
};

class windows : public platform {
public:
	static const auto category = category::desktop;
	static const auto os = os::windows;
};

class linux : public platform {
public:
	static const auto category = category::desktop;
	static const auto os = os::linux;
};

class osx : public platform {
public:
	static const auto category = category::desktop;
	static const auto os = os::osx;
};
}