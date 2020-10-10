#include <iostream>
#include "command.h"
#include "world.h"

int main(int ac, char** av)
{
	World world{};
	Command command{world};
	std::cout << "Welcome in the Maze!\n\n";
	command.ShowCommands();
	do
	{
		command.ShowState();
	}
	while (command.ProcessCommand());
	return 0;
}
