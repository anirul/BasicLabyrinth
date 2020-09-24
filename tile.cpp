#include <map>
#include <cassert>
#include "tile.h"

// An anonymous namespace just here so you cannot access there from somewhere
// else.
namespace {

	// Map of the local space.
	std::string local_world = 
		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";

	// Local player stuff.
	Player local_player{};

	// Map that map space to enemies.
	std::map<std::pair<int, int>, Enemy> local_enemy;

	int xy_local(int x, int y)
	{
		// We want the local array to be bound to the borders.
		if (x < 0) x = 0;
		if (x > 23) x = 23;
		if (y < 0) y = 0;
		if (y > 7) y = 7;
		// Return the position within the local world of the cursor.
		// As the array is singular dimention we use the largest value to
		// split it.
		return x + y * 24;
	}

} // End of namespace.

TileType get_tile_at_position(int x, int y)
{
	// TODO Get the tile at the location x, y in the world.
	return TileType::BLOCK;
}

void set_enemy(Enemy enemy, int x, int y)
{
	// Set the location of the enemy.
	enemy.x = x;
	enemy.y = y;
	local_enemy[{x, y}] = enemy;
}

Enemy get_enemy(int x, int y)
{
	Enemy enemy;
	enemy.x = x;
	enemy.y = y;
	// TODO complete me!
	// Get the local position in the world (if it exist).
	// If an enemy is at the position.
	// Then check if there is an enemy at this position?
	// if not then create it and store it at the location.
	// return the enemy at the position.
	return enemy;
}

void set_player(Player player)
{
	// Erase the local player.
	local_world[xy_local(local_player.x, local_player.y)] = '.';
	local_player = player;
	// Reinclude the new player.
	local_world[xy_local(player.x, player.y)] = 'P';
}

Player get_player()
{
	return local_player;
}
