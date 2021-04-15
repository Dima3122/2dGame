#include "Camp_fire.h"

Camp_fire::Camp_fire(float x, float y, float h, float w, karta& m)
{
	Health = 100;
	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
	game = true;
	texture.loadFromFile("image/fire.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.setPosition(x, y);
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	m.set_Tilemap(playerTileX, playerTileY, 'f');
	m.set_Tilemap(playerTileX + 1, playerTileY, 'f');
	m.set_Tilemap(playerTileX + 1, playerTileY + 1, 'f');
	m.set_Tilemap(playerTileX, playerTileY + 1, 'f');
}

void Camp_fire::update(float time)
{
	currentFrame += 0.005 * time;
	if (currentFrame > 3)
	{
		currentFrame -= 3;
	}
	sprite.setTextureRect(sf::IntRect(64 * int(currentFrame), 0, 64, 64));
	Health = Health - 0.0015 * time;
	if (Health < 0)
	{
		game = false;
	}
}

void Camp_fire::Health_plus()
{
	Health += 7;
}

void Camp_fire::set_currentFrame(double currentFrame)
{
	this->currentFrame = currentFrame;
}

void Camp_fire::set_health(double health)
{
	this->Health = health;
}

void Camp_fire::set_game(bool game)
{
	this->game = game;
}

double Camp_fire::get_currentFrame()
{
	return currentFrame;
}

double Camp_fire::get_health()
{
	return Health;
}

bool Camp_fire::get_game()
{
	return game;
}

void Camp_fire::set_x(float x)
{
	this->x = x;
}
void Camp_fire::set_y(float y)
{
	this->y = y;
}
void Camp_fire::set_w(float w)
{
	this->w = w;
}
void Camp_fire::set_h(float h)
{
	this->h = h;
}
void Camp_fire::set_texture(sf::Texture texture)
{
	this->texture = texture;
}
void Camp_fire::set_sprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

float Camp_fire::get_x()
{
	return x;
}
float Camp_fire::get_y()
{
	return y;
}
float Camp_fire::get_w()
{
	return w;
}
float Camp_fire::get_h()
{
	return h;
}
sf::Texture Camp_fire::get_texture()
{
	return texture;
}
sf::Sprite Camp_fire::get_sprite()
{
	return sprite;
}