#pragma once

#include <string>

class Arg{
private:
public:
	std::string text;
	Arg(const std::string& s): text(s) {}
	bool operator ==(const Arg& other) const;
};
