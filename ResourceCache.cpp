#include "ResourceCache.h"

#include "Utility.h"

namespace base
{
	

	ResourceCache::ResourceCache(sf::String& contentDirectory)
	{
		gLogger.Write("Resource Cache: Created");
		
		ContentDirectory = contentDirectory.ToAnsiString();
		
		gLogger.Write("Resource Cache: Directory: " + ContentDirectory);

		
	}

	ResourceCache::~ResourceCache()
	{

	}

	const sf::Texture& ResourceCache::GetTexture(const std::string& filename)
	{
		//check if the requested texture exists
		for (std::map<std::string, sf::Texture>::const_iterator it = Textures.begin();
			it != Textures.end();
			++it)
		{
			if (filename == it->first)
			{
				return it->second;
			}
		}

		//since the texture doesnt exist, load it
		sf::Texture texture;
		if (texture.LoadFromFile(ContentDirectory + filename))
		{
			Textures[filename] = texture;

			gLogger.Write("Resource Cache: Texture Loaded: " + filename);

			return Textures[filename];
		}

		//we didnt find the file, fill the map with an empty texture
		gLogger.Write("ERROR: Resource Cache: TEXTURE NOT FOUND: " + filename);
		Textures[filename] = texture;
		return Textures[filename];
	}

	void ResourceCache::DeleteTexture(std::string& filename)
	{
		std::map<std::string, sf::Texture>::const_iterator it = Textures.find(filename);
		gLogger.Write("Resource Cache: Texture Deleted: " + filename);
		Textures.erase(filename);
		return;
	}

	const sf::Font& ResourceCache::GetFont(const std::string& filename)
	{
		//check if the requested font exists
		for (std::map<std::string, sf::Font>::const_iterator it = Fonts.begin();
			it != Fonts.end();
			++it)
		{
			if (filename == it->first)
			{
				return it->second;
			}
		}

		//since the font doesnt exist, load it
		sf::Font font;
		if (font.LoadFromFile(ContentDirectory + filename))
		{
			Fonts[filename] = font;

			gLogger.Write("Resource Cache: Font Loaded: " + filename);

			return Fonts[filename];
		}

		//we didnt find the file, fill the map with an empty font
		gLogger.Write("ERROR: Resource Cache: FONT NOT FOUND: " + filename);
		Fonts[filename] = font;
		return Fonts[filename];
	}

	void ResourceCache::DeleteFont(std::string& filename)
	{
		std::map<std::string, sf::Font>::const_iterator it = Fonts.find(filename);
		gLogger.Write("Resource Cache: Font Deleted: " + filename);
		Fonts.erase(filename);
		return;
	}
}