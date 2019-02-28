#pragma once
#include <cstdlib>
#include <memory>

namespace bf {
	// todo : jemalloc
	template <class T, class... Args>
	T* bfnew(Args&&... args) {
		//void* alloc = aligned_alloc(16, sizeof(T));
		auto alloc = malloc(sizeof(T));
		new (alloc)T(std::forward<Args>(args)...);
		return reinterpret_cast<T*>(alloc);
	}

	// todo : jemalloc
	template <class T>
	void bfdelete(T* object) {
		object->~T();
		free(object);
	}

	template <class T>
	class allocator : public std::allocator<T> {
	public:
		allocator() {}

		allocator(const allocator&) {}

		template <class U>
		allocator(const allocator<U>&) {}

		template <class U>
		allocator<T>& operator= (const allocator<U>&) { return (*this); }

		template <class U>
		struct rebind { typedef allocator<U> other; };

		// todo : jemalloc
		T* allocate(size_t n) {
			//return static_cast<T*>(aligned_alloc(16, (int)n*sizeof(T)));
			return static_cast<T*>(malloc(static_cast<int>(n)*sizeof(T)));
		}

		// todo : jemalloc
		void deallocate(T* ptr, size_t n) {
			free(ptr);
		}
	};
}