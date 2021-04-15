#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "map.h"

class objects_tree
{
protected:
	float x, y, w, h;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	virtual void update(karta& m) = 0;
	void set_x(float x)
	{ 
		this->x = x;
	}
	void set_y(float y)
	{
		this->y = y;
	}
	void set_w(float w)
	{
		this->w = w;
	}
	void set_h(float h)
	{
		this->h = h;
	}
	void set_texture(sf::Texture texture)
	{
		this->texture = texture;
	}
	void set_sprite(sf::Sprite sprite)
	{
		this->sprite = sprite;
	}

	float get_x()
	{
		return x;
	}
	float get_y()
	{
		return y;
	}
	float get_w()
	{
		return w;
	}
	float get_h()
	{
		return h;
	}
	sf::Texture get_texture()
	{
		return texture;
	}
	sf::Sprite  get_sprite()
	{
		return sprite;
	}
};

