#pragma once

#define ERROR_PREFIX "ERROR: "
#define DEFAULT_SLEEP_DURATION 50000
#define FONT_PROPERTY_SET_ARG(PROPERTY, VALUE)  if (color == Arg(#VALUE)) { termfontcolor.set_##PROPERTY(TerminalFont::PROPERTY::VALUE); return true; }
#define FONT_PROPERTY_INVALID_ARG(VAR, X) throw std::runtime_error(VAR+" is not a valid "+#X+" argument!");
