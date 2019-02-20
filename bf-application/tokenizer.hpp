#pragma once
#include "structures.hpp"

namespace bf {
class Tokenizer {
public:
	const char* DELIMITERS = " \t\n\r";

	Tokenizer(const string& i) : offset(0), input(i), delimiters(DELIMITERS) {
	}

	Tokenizer(const string& i, const string& d) : offset(0), input(i), delimiters(d) {
	}

	bool NextToken() {
		return NextToken(delimiters);
	}

	bool NextToken(const string& d) {
		size_t i = input.find_first_not_of(delimiters, offset);
		if (string::npos == i)
		{
			offset = input.length();
			return false;
		}

		size_t j = input.find_first_of(delimiters, i);
		if (string::npos == j)
		{
			token = input.substr(i);
			offset = input.length();
			return true;
		}

		token = input.substr(i, j - i);
		offset = j;
		return true;
	}

	const string& GetToken() const {
		return token;
	}

protected:
	size_t offset;
	string input;
	string token;
	string delimiters;
};
}