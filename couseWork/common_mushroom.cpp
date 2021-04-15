#include "common_mushroom.h"

common_mushroom::common_mushroom(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	this->h = 32;
	this->w = 32;
	sprite.setPosition(x, y);
	texture.loadFromFile("image/all2.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'c');
}

void common_mushroom::update(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'c');
}