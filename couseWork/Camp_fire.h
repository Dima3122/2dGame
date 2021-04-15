#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "objects_tree.h"
#include "map.h"

class Camp_fire
{
private:	
	double currentFrame = 0;
	double Health;
	bool game;
	float x, y, w, h;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Camp_fire(float x, float y, float h, float w, karta& m);
	void update(float time);
	void Health_plus();

	void set_currentFrame(double currentFrame);
	void set_health(double health);
	void set_game(bool game);
	void set_x(float x);
	void set_y(float y);
	void set_w(float w);
	void set_h(float h);
	void set_texture(sf::Texture texture);
	void set_sprite(sf::Sprite sprite);

	double get_currentFrame();
	double get_health();
	bool get_game();
	float get_x();
	float get_y();
	float get_w();
	float get_h();
	sf::Texture get_texture();
	sf::Sprite  get_sprite();
};

