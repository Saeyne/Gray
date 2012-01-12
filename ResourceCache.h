#ifndef RESOURCECACHE_H
#define RESOURCECACHE_H

#include <SFML\Graphics.hpp>
#include <map>

namespace base
{
	class ResourceCache
	{
	private:
		sf::String ContentDirectory;
		std::map<std::string, sf::Font> Fonts;
		std::map<std::string, sf::Texture> Textures;
	public:
		ResourceCache(sf::String& contentDirectory);
		~ResourceCache();
		const sf::Texture& GetTexture(const std::string& filename);		//loads/retrives textures
		void DeleteTexture(std::string& filename);						//unloads a texture
		const sf::Font& GetFont(const std::string& filename);
		void DeleteFont(std::string& filename);
	};
}

#endif