#pragma once

#include <string>
#include <utility>
#include <vector>

#include "character.h"
#include "enemy.h"
#include "hero.h"

// This is the place where the rules are written.
class World {
public:
	World(
		const std::string& map =
			"########################" // 24 * 8
			"#.....E......E.....#..P#" // P is at (22, 1)
			"#######..#####..####...#"
			"#........#.............#"
			"#.E......#...E...E.....#"
			"#..##################..#"
			"#.........E............#"
			"########################", 
		int length = 8);
	void Regen();
	void EraseDead();
	std::pair<int, int> North(const Character& character);
	std::pair<int, int> South(const Character& character);
	std::pair<int, int> East(const Character& character);
	std::pair<int, int> West(const Character& character);
	void Attack();

private:
	std::pair<int, int> CheckPosition(
		std::pair<int, int> begin, 
		std::pair<int, int> end);

private:
	Hero hero_;
	std::vector<Enemy> enemies_;
	std::vector<std::vector<char>> map_;
};