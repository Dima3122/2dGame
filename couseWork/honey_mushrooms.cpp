#include "honey_mushrooms.h"

honey_mushrooms::honey_mushrooms(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	this->h = 32;
	this->w = 32;
	texture.loadFromFile("image/all2.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'g');
}

void honey_mushrooms::update(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'g');
}