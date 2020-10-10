#pragma once

#include "world.h"
#include "tile.h"

class Command {
public:
	Command(World& world) : world_(world) {}
	void ProcessCommand();
	void ShowCommands();
	
private:
	World& world_;
};