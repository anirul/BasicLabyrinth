#include "command.h"

#include <iostream>
#include <vector>

void Command::ProcessCommand()
{
	world_.Regen();
	world_.EraseDead();
}

void Command::ShowCommands()
{
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit   -> quit the game.\n";
	std::cout << "\t[n]orth  -> move north.\n";
	std::cout << "\t[s]outh  -> move south.\n";
	std::cout << "\t[w]est   -> move west.\n";
	std::cout << "\t[e]ast   -> move east.\n";
	std::cout << "\t[a]ttack -> attack enemies.\n\n";
}
