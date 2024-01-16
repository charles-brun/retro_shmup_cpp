#include "utils.h"

float Utils::globalScale = 6.0f;

sf::Vector2f Utils::getWindowSize()
{
	return sf::Vector2f(globalScale*160, globalScale*120);
}
