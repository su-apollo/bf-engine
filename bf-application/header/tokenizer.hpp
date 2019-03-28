#pragma once
#include <utility>
#include "structures.hpp"

namespace bf {
class tokenizer {
public:
	const char* delimiters = " \t\n\r";

	explicit tokenizer(string i) : offset_(0), input_(std::move(i)), delimiters_(delimiters) {
	}

	tokenizer(string i, string d) : offset_(0), input_(std::move(i)), delimiters_(std::move(d)) {
	}

	bool next_token() {
		return next_token(delimiters_);
	}

	bool next_token(const string& d) {
		const auto i = input_.find_first_not_of(delimiters_, offset_);
		if (string::npos == i)
		{
			offset_ = input_.length();
			return false;
		}

		const auto j = input_.find_first_of(delimiters_, i);
		if (string::npos == j)
		{
			token_ = input_.substr(i);
			offset_ = input_.length();
			return true;
		}

		token_ = input_.substr(i, j - i);
		offset_ = j;
		return true;
	}

	const string& get_token() const {
		return token_;
	}

protected:
	size_t offset_;
	string input_;
	string token_;
	string delimiters_;
};
}