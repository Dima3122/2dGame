#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class karta
{
protected:
	sf::Texture img;
	sf::Sprite img1_sprite;
	static const int Height_map = 25;
	static const int Widht_map = 40;
public:
	char Tilemap[Height_map][Widht_map] = {
	"000000000000000000000000000000000000000",
	"0  d           d     d  d   d   d   d 0",
	"0                                     0",
	"0  d      d       d     d       d   d 0",
	"0                                     0",
	"0         d    d     d  d   d       d 0",
	"0                                     0",
	"0                 d     d       d   d 0",
	"0                                     0",
	"0      d            d                 0",
	"0                             d       0",
	"0         d                           0",
	"0                   d                 0",
	"0     d                               0",
	"0                                     0",
	"0             d                       0",
	"0  d                    d             0",
	"0                                     0",
	"0      d                   d          0",
	"0                 d                   0",
	"0                             d       0",
	"0      d                              0",
	"0                                     0",
	"0                                     0",
	"000000000000000000000000000000000000000",
	};
	karta();
	int get_Height_map();
	int get_Widht_map();

	void set_Tilemap(int H, int W, char p);
	
	char get_Tilemap(int H, int W);
	void map_drow(sf::RenderWindow &window);
};