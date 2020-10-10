#include "enemy.h"

#include <cmath>

#include "hero.h"

Enemy::Enemy(std::pair<int, int> xy) : Character(xy, 50, 10, 2, "Gob") {}

void Enemy::Attack(Hero& hero)
{
	const float epsilon = 1e-4f;
	float dist = Distance(hero);
	if (std::abs(dist - 1.0f) < epsilon) 
	{
		hero.SetHealthPoints(std::max(0, attack_ - hero.GetDefence()));
	}
}
