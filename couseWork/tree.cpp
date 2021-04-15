#include "tree.h"

tree::tree(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	this->h = 64;
	this->w = 64;
	texture.loadFromFile("image/tree.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
	sprite.setPosition(x, y);
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'r');
	m.set_Tilemap(playerTileX, playerTileY + 1, 't');
}

void tree::update(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'r');
	m.set_Tilemap(playerTileX, playerTileY + 1, 't');
}