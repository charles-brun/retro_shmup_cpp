#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class AssetsManager
{
public:
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, std::string> textures_paths
	{
		{"cursor", "cursor.png"},
		{"player", "player.png"},
		{"shot", "shot.png"},
		{"rocket", "rocket.png"},
		{"rocket_damaged", "rocket_damaged.png"}
	};
	std::string font_path = "munro.ttf";
	sf::Font font;
	void Load();
	~AssetsManager();
};
