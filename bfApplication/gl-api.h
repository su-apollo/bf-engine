#pragma once

namespace bf {
struct GLAPI {
	enum Enum {
		GLES,
		GL
	};
};

struct GLAPIVersion {
	GLAPIVersion(GLAPI::Enum _api, int _majVersion, int _minVersion = 0)
	: api(_api)
	, majVersion(_majVersion)
	, minVersion(_minVersion) {}

	bool operator<(const GLAPIVersion &rhs) const {
		if (api < rhs.api) return true;
		if (api > rhs.api) return false;

		if (majVersion < rhs.majVersion) return true;
		if (majVersion > rhs.majVersion) return false;

		if (minVersion < rhs.minVersion) return true;
		return false;
	}

	bool operator<=(const GLAPIVersion &rhs) const {
		if (api < rhs.api) return true;
		if (api > rhs.api) return false;

		if (majVersion < rhs.majVersion) return true;
		if (majVersion > rhs.majVersion) return false;

		if (minVersion <= rhs.minVersion) return true;
		return false;
	}

	bool operator>(const GLAPIVersion &rhs) const {
		if (api > rhs.api) return true;
		if (api < rhs.api) return false;

		if (majVersion > rhs.majVersion) return true;
		if (majVersion < rhs.majVersion) return false;

		if (minVersion > rhs.minVersion) return true;
		return false;
	}

	bool operator>=(const GLAPIVersion &rhs) const {
		if (api > rhs.api) return true;
		if (api < rhs.api) return false;

		if (majVersion > rhs.majVersion) return true;
		if (majVersion < rhs.majVersion) return false;

		if (minVersion >= rhs.minVersion) return true;
		return false;
	}

	bool operator==(const GLAPIVersion &rhs) const {
		return (api == rhs.api) && (majVersion == rhs.majVersion) &&
			(minVersion == rhs.minVersion);
	}

	bool operator!=(const GLAPIVersion &rhs) const {
		return (api != rhs.api) || (majVersion != rhs.majVersion) ||
			(minVersion != rhs.minVersion);
	}

	GLAPI::Enum api; ///< The high-level API
	int majVersion; ///< The major version (X.0)
	int minVersion; ///< The minor version (0.Y)
};

struct GLAPIVersionES2 : public GLAPIVersion {
	GLAPIVersionES2() : GLAPIVersion(GLAPI::GLES, 2) {}
};

struct GLAPIVersionES3 : public GLAPIVersion {
	GLAPIVersionES3() : GLAPIVersion(GLAPI::GLES, 3) {}
};

struct GLAPIVersionES3_1 : public GLAPIVersion {
	GLAPIVersionES3_1() : GLAPIVersion(GLAPI::GLES, 3, 1) {}
};

struct GLAPIVersionGL4 : public GLAPIVersion {
	GLAPIVersionGL4() : GLAPIVersion(GLAPI::GL, 4) {}
};

struct GLAPIVersionGL4_3 : public GLAPIVersion {
	GLAPIVersionGL4_3() : GLAPIVersion(GLAPI::GL, 4, 3) {}
};

struct GLAPIVersionGL4_4 : public GLAPIVersion {
	GLAPIVersionGL4_4() : GLAPIVersion(GLAPI::GL, 4, 4) {}
};
}