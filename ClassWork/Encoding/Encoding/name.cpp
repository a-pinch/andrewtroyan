#include "stdafx.h"
#include "name.h"

using std::wstring;

name::name(const wstring& input_info) {
	size_t left_border = 0, right_border = 0;

	right_border = input_info.find(L' ', left_border);
	surname = input_info.substr(left_border, right_border - left_border);
	left_border = right_border + 1;

	right_border = input_info.find(L' ', left_border);
	first_name = input_info.substr(left_border, right_border - left_border);
	left_border = right_border + 1;

	if (right_border < input_info.size()) {
		right_border = input_info.find(L' ', left_border);
		second_name = input_info.substr(left_border, right_border - left_border);
	}
}

name::operator std::wstring() {
	wstring to_return(surname);
	to_return += L" ";
	to_return += first_name;
	if (second_name.size()) {
		to_return += L" ";
		to_return += second_name;
	}
	return std::move(to_return);
}
