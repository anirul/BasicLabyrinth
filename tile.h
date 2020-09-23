#pragma once

#include <string>

enum class TileType : char
{
	BLOCK = '#',
	EMPTY = '.',
	ENEMY = 'E',
	PLAYER = 'P',
};

enum class CommandType
{
	QUIT,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	ATTACK,
	HELP,
};

TileType get_tile_at_position(int x, int y);

struct Enemy 
{
	int health_points;
	int attack;
	int defence;
	std::string name;
};

Enemy get_enemy(int x, int y);

struct Player 
{
	int x;
	int y;
	int health_points;
	int attack;
	int defence;
	std::string name;
	int experience;
};

void set_player(Player player);
Player get_player();
