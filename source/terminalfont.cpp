#include "../include/terminalfont.h"

TerminalFont::TerminalFont(const style s, const foreground f, const background b)
{
	set_style(s);
	set_foreground(f);
	set_background(b);
}

const TerminalFont::style TerminalFont::set_style(const style s)
{
	//~ switch (s)
	//~ {
		//~ case style::regular:
		//~ case style::bold:
		//~ case style::thin:
		//~ case style::cursive:
		//~ case style::underline:
		//~ case style::blink:
			stl = s;
			//~ break;
		//~ default:
			//~ throw std::runtime_error("Invalid style!");
	//~ }
	
	return stl;
}

const TerminalFont::foreground TerminalFont::set_foreground(const foreground f)
{
	//~ switch (f)
	//~ {
		//~ case foreground::black:
		//~ case foreground::red:
		//~ case foreground::green:
		//~ case foreground::yellow:
		//~ case foreground::blue:
		//~ case foreground::cyan:
		//~ case foreground::aqua:
		//~ case foreground::white:
		
		//~ case foreground::black_dark:
		//~ case foreground::red_dark:
		//~ case foreground::green_dark:
		//~ case foreground::yellow_dark:
		//~ case foreground::blue_dark:
		//~ case foreground::cyan_dark:
		//~ case foreground::aqua_dark:
		//~ case foreground::white_dark:
		
			fg = f;
			//~ break;
		//~ default:
			//~ throw std::runtime_error("Invalid foreground!");
	//~ }
	
	return fg;
}

const TerminalFont::background TerminalFont::set_background(const background b)
{
	//~ switch (b)
	//~ {
		//~ case background::black:
		//~ case background::red:
		//~ case background::green:
		//~ case background::yellow:
		//~ case background::blue:
		//~ case background::cyan:
		//~ case background::aqua:
		//~ case background::white:
		
		//~ case background::black_dark:
		//~ case background::red_dark:
		//~ case background::green_dark:
		//~ case background::yellow_dark:
		//~ case background::blue_dark:
		//~ case background::cyan_dark:
		//~ case background::aqua_dark:
		//~ case background::white_dark:
		
			bg = b;
			//~ break;
		//~ default:
			//~ throw std::runtime_error("Invalid background!");
	//~ }
	
	return bg;
}

std::string TerminalFont::get_format(void) const
{
	//~ std::string s = initiator +stl +separator +fg +separator +bg +terminator;
	//~ return s;
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
