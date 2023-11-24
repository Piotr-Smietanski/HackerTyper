#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <climits>      //UINT_MAX
#include <unistd.h>     //usleep
#include <termios.h>    //for disabling input echo
#include <signal.h>

#include "../include/terminalfont.h"
#include "../include/printhelp.h"
#include "../include/macros.h"
#include "../include/arg.h"

//defaults
bool         mode_loopoutput   = false;
bool         mode_interactive  = false;
unsigned int slpdur            = DEFAULT_SLEEP_DURATION;
std::string  inputfilename     = "";
TerminalFont termfontcolor;

char getch_ne() {
//get input without waiting for "enter" key and dont print pressed key character
	char buf = 0;
	struct termios old = {0};
	
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
		
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0)
		perror ("read()");
		
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");
		
	return (buf);
}

void set_term_raw_ne() {
	struct termios old = {0};
	tcgetattr(0, &old);
	
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	
	tcsetattr(0, TCSADRAIN, &old);
}

void unset_term_raw_ne() {
	struct termios old = {0};
	tcgetattr(0, &old);	
	
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	
	tcsetattr(0, TCSADRAIN, &old);
}

bool setarg(const char** arg, int iout, bool islast)
//returns true if analyzed arg was composed of 2 parts
//throws runtime_error if argument was invalid
{
	//welcome to if else hell. should have used "getopt_long"...
	if (Arg(arg[iout]) == Arg("-d"))
	{
		unsigned int i = 0;
		if (!islast)
		{
			std::stringstream ss(arg[iout+1]);
			if (ss >> i && i < UINT_MAX)
			{
				slpdur = i;
			}
			return true;
		}
		else
		{
			throw std::runtime_error("-d expects one more argument behind!");
		}
	}
	else if (Arg(arg[iout]) == Arg("-f"))
	{
		if (!islast)
		{
			inputfilename = std::string(arg[iout+1]);
			return true;
		}
		else
		{
			throw std::runtime_error("-f expects one more argument behind!");
		}
	}
	else if (Arg(arg[iout]) == Arg("-h"))
	{
		printhelp();
		exit(0);
	}
	else if (Arg(arg[iout]) == Arg("-l"))
	{
		mode_loopoutput = true;
		return false;
	}
	else if (Arg(arg[iout]) == Arg("-i"))
	{
		mode_interactive = true;
		return false;
	}
	//font style
	else if (Arg(arg[iout]) == Arg("-fs"))
	{
		if (!islast)
		{
			Arg color(arg[iout+1]);
			
			FONT_PROPERTY_SET_ARG(style, regular);
			FONT_PROPERTY_SET_ARG(style, bold);
			FONT_PROPERTY_SET_ARG(style, thin);
			FONT_PROPERTY_SET_ARG(style, cursive);
			FONT_PROPERTY_SET_ARG(style, underline);
			FONT_PROPERTY_SET_ARG(style, blink);
			
			FONT_PROPERTY_INVALID_ARG(color.text, style);
		}
		else
		{
			throw std::runtime_error("-fc expects one more argument behind!");
		}
	}
	//font color
	else if (Arg(arg[iout]) == Arg("-fc"))
	{
		if (!islast)
		{
			Arg color(arg[iout+1]);
			
			FONT_PROPERTY_SET_ARG(foreground, black);
			FONT_PROPERTY_SET_ARG(foreground, red);
			FONT_PROPERTY_SET_ARG(foreground, green);
			FONT_PROPERTY_SET_ARG(foreground, yellow);
			FONT_PROPERTY_SET_ARG(foreground, blue);
			FONT_PROPERTY_SET_ARG(foreground, cyan);
			FONT_PROPERTY_SET_ARG(foreground, aqua);
			FONT_PROPERTY_SET_ARG(foreground, white);
			
			FONT_PROPERTY_SET_ARG(foreground, black_dark);
			FONT_PROPERTY_SET_ARG(foreground, red_dark);
			FONT_PROPERTY_SET_ARG(foreground, green_dark);
			FONT_PROPERTY_SET_ARG(foreground, yellow_dark);
			FONT_PROPERTY_SET_ARG(foreground, blue_dark);
			FONT_PROPERTY_SET_ARG(foreground, cyan_dark);
			FONT_PROPERTY_SET_ARG(foreground, aqua_dark);
			FONT_PROPERTY_SET_ARG(foreground, white_dark);
			
			FONT_PROPERTY_INVALID_ARG(color.text, foreground);
			//~ return true; //can not have single return - it skips invalid argument throw
		}
		else
		{
			throw std::runtime_error("-fc expects one more argument behind!");
		}
	}
	//font background color
	else if (Arg(arg[iout]) == Arg("-fbc"))
	{
		if (!islast)
		{
			Arg color(arg[iout+1]);
			
			FONT_PROPERTY_SET_ARG(background, black);
			FONT_PROPERTY_SET_ARG(background, red);
			FONT_PROPERTY_SET_ARG(background, green);
			FONT_PROPERTY_SET_ARG(background, yellow);
			FONT_PROPERTY_SET_ARG(background, blue);
			FONT_PROPERTY_SET_ARG(background, cyan);
			FONT_PROPERTY_SET_ARG(background, aqua);
			FONT_PROPERTY_SET_ARG(background, white);
			
			FONT_PROPERTY_SET_ARG(background, black_dark);
			FONT_PROPERTY_SET_ARG(background, red_dark);
			FONT_PROPERTY_SET_ARG(background, green_dark);
			FONT_PROPERTY_SET_ARG(background, yellow_dark);
			FONT_PROPERTY_SET_ARG(background, blue_dark);
			FONT_PROPERTY_SET_ARG(background, cyan_dark);
			FONT_PROPERTY_SET_ARG(background, aqua_dark);
			FONT_PROPERTY_SET_ARG(background, white_dark);
			
			FONT_PROPERTY_INVALID_ARG(color.text, background);
		}
		else
		{
			throw std::runtime_error("-fbc expects one more argument behind!");
		}
	}
	
	throw std::runtime_error("Inavlid arguments!");
	return false;
}

int handle_args(const int argc, const char** argv)
{
	int aa = 0;                                                         // analyzed args
	
	if (argc<2)
	//no arguments were supplied, nothing to do here
	{
		return -1;
	}
	
	for (int i = 1; i < argc; i++)
	//dont analyze first arg - it is own name it was called with
	{
		std::string ar = argv[i];
		bool islast = false;
		if (i == argc-1)
		{
			islast = true;
		}
		
		if (setarg(argv, i, islast))
		//analyzed argument consumed 2 arguments at once - move forward
		{
			i++;
			aa++;
		}
		aa++;
	}
	
	return aa;
}

void signal_handler(int s)
{
	std::cout << TerminalFont();
	std::cout << "\033[2J\033[1;1H";                                    //clear screen
	
	//fix terminal before exiting
	struct termios old = {0};
	tcgetattr(0, &old);
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, &old);
                
	exit(1);
}

int main(int argc, const char** argv)
try
{
	signal(SIGINT, signal_handler);                                     //handle ^C etc
	if (handle_args(argc, argv) < 0)
	{
		printhelp();
		exit(1);
	}
	
	std::ifstream infile(inputfilename.c_str());
	if (infile)
	{
		std::cout << termfontcolor;                                     //set output font color
		std::cout << "\033[2J\033[1;1H";                                //clear screen
		
		printagain:
		char c = 0;
		char prevc = c;
		
		while (infile.get(c))
		{
			std::cout.flush();
			std::cout << c;
			
			if (isspace(c))
			{
				if (isspace(prevc))                                     //skip over consecutive white characters - require input only for first white character in cluster
				{
					prevc = c;
					continue;
				}
				if (mode_interactive)
				{
					getch_ne();
				}
				else
				{
					set_term_raw_ne();
					usleep(slpdur);
					unset_term_raw_ne();
				}
			}
			prevc = c;
		}
		
		if (mode_loopoutput)
		{
			infile.clear();
			infile.seekg(0);
			goto printagain;
		}
		infile.close();
	}
	else
	{
		throw std::runtime_error(std::string("failed to open input file: \"")+inputfilename.c_str()+'"');
	}
	
	return 0;
}
catch(std::exception& e)
{
	std::cerr << ERROR_PREFIX << e.what() << "\n";
	return 1;
}
catch(...)
{
	std::cerr << ERROR_PREFIX << "Unknown exception!" << "\n";
	return 1;
}
