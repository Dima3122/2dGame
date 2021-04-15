#include <sstream>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "view.h"
#include "map.h"
#include "Camp_fire.h"
#include "objects_tree.h"
#include "tree.h"
#include "mushroom.h"
#include "honey_mushrooms.h"
#include "log.h"
#include "common_mushroom.h"

std::vector<objects_tree*> myVector;

void init(karta& m)
{
	for (size_t i = 0; i < 10; i++)
	{
		myVector.push_back(new tree(m));
	}
	for (size_t i = 0; i < 7; i++)
	{
		myVector.push_back(new mushroom(m));
	}
	for (size_t i = 0; i < 3; i++)
	{
		myVector.push_back(new common_mushroom(m));
	}
	for (size_t i = 0; i < 3; i++)
	{
		myVector.push_back(new honey_mushrooms(m));
	}
	myVector.push_back(new Log(m));
}

int main()
{
	setlocale(LC_ALL, "ru");
	sf::Font font;
	font.loadFromFile("shrift.ttf");
	sf::Text text("", font, 20);
	sf::Text text2("", font, 40);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::Black);
	text2.setStyle(sf::Text::Bold);
	sf::RenderWindow window(sf::VideoMode(640, 480), "CourseWork");
	view.reset(sf::FloatRect(0, 0, 640, 480));
	sf::Clock clock;
	player player(32, 32, 32, 32);
	karta m;
	Camp_fire fire(200, 300, 64,64, m);
	init(m);
	sf::Clock gameTimeClock;
	int gameTime;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		if (fire.get_game() == true) 
		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
		}
		if (fire.get_game() == false)
		{
			text2.setString("GAME OVER!");
			text2.setPosition(view.getCenter().x - 100, view.getCenter().y-100);
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		player.update(time, m, myVector,fire);
		getplayercoordinateforview(player.get_x(), player.get_y());
		window.setView(view);
		window.clear();
		m.map_drow(window);
		std::ostringstream playerScoreString, gameTimeString;
		playerScoreString << fire.get_health();
		gameTimeString << gameTime;
		text.setString("Health " + playerScoreString.str() +"\nTime: " + gameTimeString.str());
		text.setPosition(view.getCenter().x + 170, view.getCenter().y- 230);
		fire.update(time);
		window.draw(text2);
		window.draw(text);
		window.draw(fire.get_sprite());
		window.draw(player.get_sprite());
		window.display();
	}
	return 0;
}