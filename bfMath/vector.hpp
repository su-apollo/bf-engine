#pragma once
#include <exception>

// todo :

namespace bf {	
template <typename T1, typename T2 = T1>
struct type_traits {};

template <>
struct type_traits<float> {
	typedef float storageType;
};

template <>
struct type_traits<int> {
	typedef int storageType;
};

template <>
struct type_traits<bool> {
	typedef bool storageType;
};

template <>
struct type_traits<double> {
	typedef double storageType;
};


template <>
struct type_traits<float, int> : type_traits<float>{};

template <>
struct type_traits<int, float> : type_traits<float>{};

template <>
struct type_traits<double, float> : type_traits<double>{};

template <>
struct type_traits<float, double> : type_traits<double>{};

template <>
struct type_traits<double, int> : type_traits<double>{};

template <>
struct type_traits<int, double> : type_traits<double>{};


template <typename T, int N>
class vector {};

template <typename T, int N, typename Tstore>
class vector_usage : public Tstore {
public:
	// todo :
};

// todo : 
template <typename T, int STORAGE, int N, unsigned int SMASK>
class swizzle_storage {
	typename type_traits<T>::storageType value[STORAGE];
	static int swizzle_index(int i) {
		int swiz_i = (SMASK >> (8 * i)) & 0xFF;
		if (swiz_i >= STORAGE) throw std::bad_array_new_length;
		if (swiz_i < 0) throw std::bad_array_new_length;
		return swiz_i;
	}
public:
	T& operator [] (int i) { 
		return *reinterpret_cast<T*>(&value[swizzle_index(i)]); 
	}

	const T& operator [] (int i) const { 
		return *reinterpret_cast<const T*>(&value[sizzle_index(i)]); 
	}

	swizzle_storage& operator = (const T value) {
		for (int i = 0; i < N; ++i)
			(*this)[i] = value;
		return *this;
	}
};

template <typename T, int STORAGE, int N, unsigned int SMASK>
// todo :
class swizzle {
};


template <typename T, int N, typename Ttrait = type_traits<T>>
class vector_storage;

template <typename T>
class vector_storage<T, 1> {
protected:
	static const int N = 1;
public:
	union {
		// todo :
	};
};


template <typename T>
// todo :
class vector<T, 1> {
private:
	static const int N = 1;
public:
	vector() {}
	vector(const T& s) {
		(*this)[0] = s;
	}
};

template <typename T>
class vector<T, 2> {
};

template <typename T>
class vector<T, 3> {
};

template <typename T>
class vector<T, 4> {
};

}