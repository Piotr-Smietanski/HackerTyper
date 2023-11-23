#include "../include/arg.h"


bool Arg::operator ==(const Arg& other) const
{
	if (text.size() != other.text.size())
	{
		return false;
	}
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] != other.text[i])
		{
			return false;
		}
	}
	return true;
}
