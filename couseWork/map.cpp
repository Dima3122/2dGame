#include "map.h"

karta::karta()
{
	img.loadFromFile("image/all2.png");
	img1_sprite.setTexture(img);
}

int karta::get_Height_map()
{
    return Height_map;
}

int karta::get_Widht_map()
{
    return Widht_map;
}

void karta::set_Tilemap(int H, int W, char p)
{
	Tilemap[W][H] = p;
}

char karta::get_Tilemap(int H, int W)
{
	return Tilemap[W][H];
}

void karta::map_drow(sf::RenderWindow &window)
{
	for (int i = 0; i < Height_map; i++)
	{
		for (int j = 0; j < Widht_map; j++)
		{
			if (Tilemap[i][j] == '0')
			{
				img1_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			}
			if (Tilemap[i][j] == ' ')
			{
				img1_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
			}
			if (Tilemap[i][j] == 'd')
			{
				img1_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
			}
			if (Tilemap[i][j] == 'r')
			{
				img1_sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
			}
			if (Tilemap[i][j] == 't')
			{
				img1_sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
			}
			if (Tilemap[i][j] == 'm')
			{
				img1_sprite.setTextureRect(sf::IntRect(64, 32, 32, 32));
			}
			if (Tilemap[i][j] == 'g')
			{
				img1_sprite.setTextureRect(sf::IntRect(128, 32, 32, 32));
			}
			if (Tilemap[i][j] == 'b')
			{
				img1_sprite.setTextureRect(sf::IntRect(64, 64, 32, 32));
			}
			if (Tilemap[i][j] == 'c')
			{
				img1_sprite.setTextureRect(sf::IntRect(96, 32, 32, 32));
			}
			img1_sprite.setPosition(j * 32, i * 32);
			window.draw(img1_sprite);
		}
	}
}