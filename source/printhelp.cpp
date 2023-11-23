#include "../include/printhelp.h"

void printhelp()
{
	const char tab1[] = "\t";
	const char tab2[] = "\t\t";
	//~ const char tab1[] = "    ";
	//~ const char tab2[] = "        ";
	TerminalFont  underscore(TerminalFont::style::underline,TerminalFont::foreground::white, TerminalFont::background::black_dark);
	TerminalFont  normal = TerminalFont();
	
	std::cerr << "Arguments:\n";
	std::cerr << tab1 << "-h\n";
	std::cerr << tab2 << "Displays this help.\n";
	
	std::cerr << tab1 << "-l\n";
	std::cerr << tab2 << "Loops output infinitely.\n";
	
	std::cerr << tab1 << "-i\n";
	std::cerr << tab2 << "Interactive mode. Waits for key press before printing segment.\n";
	
	std::cerr << tab1 << "-f " << underscore << "file" << normal << "\n";
	std::cerr << tab2 << "Uses " << underscore << "file" << normal << " content as source.\n";
	
	std::cerr << tab1 << "-d " << underscore << "delay" << normal << "\n" ;
	std::cerr << tab2 << "Changes delay in miliseconds between printing segments in non-interactive mode.\n";
	std::cerr << tab2 << "default " << DEFAULT_SLEEP_DURATION << "\n";
	
	std::cerr << tab1 << "-fc " << underscore << "color" << normal << "\n";
	std::cerr << tab2 << "Changes font color. options are:\n";
	std::cerr << tab2 << "black, red, green, yellow, blue, cyan, aqua, white,\n";
	std::cerr << tab2 << "black_dark, red_dark, green_dark, yellow_dark, blue_dark, cyan_dark, aqua_dark, white_dark\n";
	
	std::cerr << tab1 << "-fbc " << underscore << "color" << normal << "\n";
	std::cerr << tab2 << "Changes background color. Options are:\n";
	std::cerr << tab2 << "black, red, green, yellow, blue, cyan, aqua, white\n";
	
	std::cerr << tab1 << "-fs " << underscore << "style" << normal << "\n";
	std::cerr << tab2 << "Changes font style. Options are:\n";
	std::cerr << tab2 << "regular, bold, thin, cursive, underline, blink\n";
	//-------------------------------------------------------------------------------------------
	
}
