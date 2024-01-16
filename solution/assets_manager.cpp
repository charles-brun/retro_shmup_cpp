#include "assets_manager.h"

void AssetsManager::Load()
{
	for (const auto& paths : textures_paths)
	{
		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(paths.second))
		{
			continue;
		}
		textures[paths.first] = texture;
	}
}

AssetsManager::~AssetsManager()
{
	for (const auto& paths : textures)
	{
		delete textures[paths.first];
	}
}
