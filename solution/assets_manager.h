#pragma once
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class AssetsManager
{
public:
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, std::string> textures_paths{
		{"player", "player.png"},
		{"shot", "shot.png"}
	};
	void Load();
	~AssetsManager();
};
