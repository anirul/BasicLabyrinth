#pragma once

#include "character.h"
#include "enemy.h"

class Hero : public Character {
public:
	// Create a hero.
	Hero(std::pair<int, int> xy);
	void Regen();
	void Attack(Enemy& enemy);

private:
	int experience_;
	int health_regen_;
	int max_health_points_;
};