#include "utils.h"

float Utils::globalScale = 6.0f;

float Utils::fontSizeS = 7.0f;
float Utils::fontSizeM = 14.0f;
float Utils::fontSizeL = 21.0f;

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

float Utils::getFontSize(FontSize fontSize)
{
	switch (fontSize) 
	{
	case S:
		return fontSizeS * globalScale;
	case M:
		return fontSizeM * globalScale;
	case L:
		return fontSizeL * globalScale;
	default:
		return 0;
	}
}