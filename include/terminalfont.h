#pragma once

#include <string>
#include <sstream>

/*
 * TerminalFont is a class intended to ease setting
 * terminal output colors
 */

class TerminalFont
{
public:
	enum struct style{
		regular,
		bold,
		thin,
		cursive,
		underline,
		blink
		};
		
	enum struct foreground{
		//~ white = 29,
		black_dark = 30,
		red_dark,
		green_dark,
		yellow_dark,
		blue_dark,
		cyan_dark,
		aqua_dark,
		white_dark,
		
		black = 90,
		red,
		green,
		yellow,
		blue,
		cyan,
		aqua,
		white
		
		};
		
	enum struct background{
		//~ black = 40,
		//~ red,
		//~ green,
		//~ yellow,
		//~ blue,
		//~ cyan,
		//~ aqua,
		//~ white
		
		black_dark = 40,
		red_dark,
		green_dark,
		yellow_dark,
		blue_dark,
		cyan_dark,
		aqua_dark,
		white_dark,
		
		black = 100,
		red,
		green,
		yellow,
		blue,
		cyan,
		aqua,
		white
		};
private:
	style      stl;
	foreground fg;
	background bg;
	
	const std::string initiator  = "\e[";
	const std::string terminator = "m";
	const std::string separator  = ";";
	
public:
	TerminalFont() { set_style(style::regular); set_foreground(foreground::white); set_background(background::black_dark); };
	TerminalFont(const style s, const foreground f, const background b);
	
	// set
	const style      set_style      (const style s);
	const foreground set_foreground (const foreground f);
	const background set_background (const background b);
	
	// get
	style       get_style      (void) const;
	foreground  get_foreground (void) const;
	background  get_background (void) const;
	std::string get_format     (void) const;
};

std::ostream& operator << (std::ostream& os, const TerminalFont& tf);
