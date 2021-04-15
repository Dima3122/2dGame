#include "player.h"
using namespace std;

player::player(float x, float y, float wight, float height)
{
	this->x = x;
	this->y = y;
	this->w = wight;
	this->h = height;
	inhand = false;
	poisoning = false;
	texture.loadFromFile("image/человечки.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
}

void player::update(float time, karta &m, std::vector<objects_tree*>& myVector, Camp_fire &fire)
{
	if (fire.get_game() == true)
	{
		iteractionMap(m, fire, myVector,time);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3)
			{
				currentFrame -= 3;
			}
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 0, 32, 32));
			x += -speed * time;
			div = 0;
			sprite.setPosition(x, y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3)
			{
				currentFrame -= 3;
			}
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 96, 32, 32));
			x += speed * time;
			div = 1;
			sprite.setPosition(x, y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3)
			{
				currentFrame -= 3;
			}
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 64, 32, 32));
			y += -speed * time;
			div = 2;
			sprite.setPosition(x, y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3)
			{
				currentFrame -= 3;
			}
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 32, 32, 32));
			y += speed * time;
			div = 3;
			sprite.setPosition(x, y);
		}
	}
}

void player::iteractionMap(karta &m, Camp_fire &fire, std::vector<objects_tree*>& myVector ,float time)
{
	int playerTileX = (int)(x / 32);
	int playerTileY = (int)(y / 32);
	if (m.Tilemap[playerTileY][playerTileX] == '0' || m.Tilemap[playerTileY+1][playerTileX+1] == '0')
	{
		if (div == 0)
		{
			x = 32;
		}
		if (div == 1)
		{
			x = 1180;
		}
		if (div == 2)
		{
			y = 32;
		}
		if (div == 3)
		{
			y = 730;
		}
	}
	//коллизия с деревьями
	if ((m.Tilemap[playerTileY][playerTileX] == 't' || m.Tilemap[playerTileY + 1][playerTileX + 1] == 't' || 
		m.Tilemap[playerTileY][playerTileX] == 'r' || m.Tilemap[playerTileY + 1][playerTileX + 1] == 'r') && 
		inhand == false)
	{		
		m.set_Tilemap(playerTileX, playerTileY, ' ');
		m.set_Tilemap(playerTileX, playerTileY + 1, ' ');
		m.set_Tilemap(playerTileX, playerTileY - 1, ' ');
		m.set_Tilemap(playerTileX + 1, playerTileY, ' ');
		m.set_Tilemap(playerTileX + 1, playerTileY + 1, ' ');
		inhand = true;
		myVector[0]->update(m);
	}
	//коллизия с костром
	if (m.Tilemap[playerTileY][playerTileX] == 'f' || m.Tilemap[playerTileY + 1][playerTileX + 1] == 'f')
	{
		if (div == 0)
		{
			x = playerTileX* 32+ 32;
		}
		if (div == 1)
		{
			x = playerTileX * 32;
		}
		if (div == 2)
		{
			y = playerTileY * 32 + 32;
		}
		if (div == 3)
		{
			y = playerTileY * 32;
		}
		if (inhand == true && poisoning == false)
		{
			inhand = false;
			fire.Health_plus();
		}
		else if (poisoning == true && inhand == true)
		{
			inhand = false;
			poisoning = false;
			fire.Health_plus();
			fire.Health_plus();
			fire.Health_plus();
			fire.Health_plus();
		}
	}
	if (m.Tilemap[playerTileY][playerTileX] == 'm')
	{
		speed = 0.03f;
		m.set_Tilemap(playerTileX, playerTileY, ' ');
		myVector[10]->update(m);
	}
	if (m.Tilemap[playerTileY][playerTileX] == 'g')
	{
		speed = 0.2f;
		m.set_Tilemap(playerTileX, playerTileY, ' ');
		myVector[22]->update(m);
	}
	if (m.Tilemap[playerTileY][playerTileX] == 'b' && inhand == false)
	{
		inhand = true;
		poisoning = true;
		m.set_Tilemap(playerTileX, playerTileY, ' ');
		myVector[23]->update(m);
	}
	if (m.Tilemap[playerTileY][playerTileX] == 'c')
	{
		speed = 0.1f;
		m.set_Tilemap(playerTileX, playerTileY, ' ');
		myVector[18]->update(m);
	}
}

void player::set_x(float x)
{
	this->x = x;
}

void player::set_y(float y)
{
	this->y = y;
}

void player::set_w(float w)
{
	this->w = w;
}

void player::set_h(float h)
{
	this->h = h;
}

void player::set_currentFrame(double currentFrame)
{
	this->currentFrame = currentFrame;
}

void player::set_texture(sf::Texture texture)
{
	this->texture = texture;
}

void player::set_sprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

float player::get_x()
{
	return x;
}

float player::get_y()
{
	return y;
}

float player::get_w()
{
	return w;
}

float player::get_h()
{
	return h;
}

sf::FloatRect player::getRect()
{
	return sf::FloatRect(x, y ,32, 32);
}

double player::get_currentFreme()
{
	return currentFrame;
}

sf::Texture player::get_texture()
{
	return texture;
}

sf::Sprite player::get_sprite()
{
	return sprite;
}
