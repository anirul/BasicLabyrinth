#include "world.h"

#include <cassert>

World::World(const std::string& map, int length) : hero_({0, 0})
{
	int j = 0;
	for (int i = 0; i < length; ++i)
	{
		if (map[j] == 'E')
		{
			Enemy enemy({ i, j / length });
			enemies_.push_back(enemy);
			map_[i][j / length] = '.';
		}
		else if (map[j] == 'P')
		{
			hero_.SetPosition({ i, j / length });
			map_[i][j / length] = '.';
		}
		else 
		{
			assert(map[j] == '.' || map[j] == '#');
			map_[i][j / length] = map[j];
		}
		++j;
	}
}

void World::Regen()
{
	hero_.Regen();
}

void World::EraseDead()
{
	auto pos = std::remove_if(
		enemies_.begin(),
		enemies_.end(),
		[](const Enemy& enemy)
		{
			return enemy.IsDead();
		});
	enemies_ = { enemies_.begin(), pos };
}

std::pair<int, int> World::North(const Character& character)
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.second -= 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::South(const Character& character)
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.second += 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::East(const Character& character)
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.first += 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

std::pair<int, int> World::West(const Character& character)
{
	// Create a new position for the character.
	std::pair<int, int> new_xy = character.GetPosition();
	new_xy.first -= 1;
	return CheckPosition(character.GetPosition(), new_xy);
}

void World::Attack()
{
	for (auto& item : enemies_)
	{
		float dist = item.Distance(hero_);
		if (std::abs(dist - 1.0f) < 1e-4) 
		{
			hero_.Attack(item);
		}
	}
}

std::pair<int, int> World::CheckPosition(
	std::pair<int, int> begin, 
	std::pair<int, int> end)
{
	// Check if the player is there.
	if (end == hero_.GetPosition())
		return begin;
	// Check if there is an enemy in there.
	for (const auto& item : enemies_)
	{
		if (end == item.GetPosition())
			return begin;
	}
	// Check if there is a wall in there.
	if (map_[end.first][end.second] == '#')
		return begin;
	return end;
}
