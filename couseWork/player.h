#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "map.h"
#include "Camp_fire.h"
#include "tree.h"
#include "Camp_fire.h"
#include "mushroom.h"
#include "honey_mushrooms.h"
#include "log.h"
#include "common_mushroom.h"

class player
{
private:
	float x, y, w, div = 0 , speed = 0.1f, h;
	double currentFrame = 0;
	bool inhand;
	bool poisoning;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	player(float x, float y ,float wight, float height);
	void update(float time, karta &m, std::vector<objects_tree*> &myVector , Camp_fire &fire);
	void iteractionMap(karta &m, Camp_fire &fire, std::vector<objects_tree*>& myVector, float time);

	void set_x(float x);
	void set_y(float y);
	void set_w(float w);
	void set_h(float h);
	void set_currentFrame(double currentFrame);
	void set_texture(sf::Texture texture);
	void set_sprite(sf::Sprite sprite);

	float get_x();
	float get_y();
	float get_w();
	float get_h();
	sf::FloatRect getRect();
	double get_currentFreme();
	sf::Texture get_texture();
	sf::Sprite  get_sprite();
};