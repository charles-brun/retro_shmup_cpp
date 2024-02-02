#pragma once
#include <SFML/Graphics.hpp>

class Utils
{
public:
	static float globalScale;
	static float fontSizeS;
	static float fontSizeM;
	static float fontSizeL;

	static float getMarginTop();
	static float getMarginBot();
	static sf::Vector2f getWindowSize();
	enum FontSize {
		S,
		M,
		L
	};
	static float getFontSize(FontSize fontSize);
};

