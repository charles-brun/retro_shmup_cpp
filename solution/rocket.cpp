#include "rocket.h"
#include "utils.h"
#include <algorithm>

Rocket::Rocket()
{
	texture_name = "rocket";
	speed = 90.0f;
	scoreValue = 10;
	Move(sf::Vector2f(-1, 0));
}
