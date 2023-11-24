#include "../include/terminalfont.h"

TerminalFont::TerminalFont(const style s, const foreground f, const background b)
{
	set_style(s);
	set_foreground(f);
	set_background(b);
}

const TerminalFont::style TerminalFont::set_style(const style s)
{
	stl = s;
	return stl;
}

const TerminalFont::foreground TerminalFont::set_foreground(const foreground f)
{
	fg = f;
	return fg;
}

const TerminalFont::background TerminalFont::set_background(const background b)
{
	bg = b;
	return bg;
}

std::string TerminalFont::get_format(void) const
{
	std::stringstream ss;
	ss << initiator;
	ss << static_cast<int>(stl);
	ss << separator;
	ss << static_cast<int>(fg);
	ss << separator;
	ss << static_cast<int>(bg);
	ss << terminator;
	return ss.str();
}
std::ostream& operator << (std::ostream& os, const TerminalFont& tf)
{
	return os << tf.get_format();
}
