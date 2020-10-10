#include "hero.h"

#include <cmath>

Hero::Hero(std::pair<int, int> xy) : 
	Character(xy, 100, 20, 5, "The Hero"),
	experience_(0),
	health_regen_(5),
	max_health_points_(100) {}

void Hero::Regen()
{
	health_points_ += std::max(0, health_regen_);
	health_points_ = std::min(health_points_, max_health_points_);
}

void Hero::Attack(Enemy& enemy)
{
	const float epsilon = 1e-4f;
	float dist = Distance(enemy);
	if (std::abs(dist - 1.0f) < epsilon) 
	{
		enemy.SetHealthPoints(std::max(0, attack_ - enemy.GetDefence()));
		experience_ += 100;
	}
}

