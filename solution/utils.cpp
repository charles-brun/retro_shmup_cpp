#include "utils.h"

float Utils::globalScale = 4.0f;

float Utils::getMarginTop()
{
	return 10 * globalScale;
}

float Utils::getMarginBot()
{
	return getWindowSize().y - (10 * globalScale);
}

sf::Vector2f Utils::getWindowSize()
{
	return sf::Vector2f(globalScale*160, globalScale*120);
}