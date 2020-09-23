#include <map>
#include <cassert>
#include "tile.h"

// An anonymous namespace just here so you cannot access there from somewhere
// else.
namespace {

// Map of the local space.
std::string local_world = 
	"########################" // 24 * 8
	"#.....E......E.....#..P#"
	"#######..#####..####...#"
	"#........#.............#"
	"#.E......#...E...E.....#"
	"#..##################..#"
	"#.........E............#"
	"########################";

// Local player stuff.
Player local_player{ 1, 22, 200, 20, 5, "Anonymous", 0 };

// Map that map space to enemies.
std::map<std::pair<int, int>, Enemy> local_enemy;

int xy_local(int x, int y)
{
	assert(x >= 0 && x < 24);
	assert(y >= 0 && y < 8);
	return x + y * 24;
}

} // End of namespace.

TileType get_tile_at_position(int x, int y)
{
	// Get the tile at the location x, y.
	return TileType::BLOCK;
}

Enemy get_enemy(int x, int y)
{
	Enemy enemy;
	// Get the local position (if it exist).
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
