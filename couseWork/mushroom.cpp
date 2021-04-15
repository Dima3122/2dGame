#include "mushroom.h"

mushroom::mushroom(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	this->h = 32;
	this->w = 32;
	sprite.setPosition(x, y);
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'm');
}

void mushroom::update(karta& m)
{
	x = rand() % 1000;
	y = rand() % 700;
	x = x + 50;
	y = y + 50;
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'm');
}
