#include "rocket.h"
#include "utils.h"
#include <algorithm>

Rocket::Rocket()
{
	texture_name = "rocket";
	speed = 60.0f;
	Move(sf::Vector2f(-1, 0));
}
