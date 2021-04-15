#pragma once

static sf::View view;

sf::View getplayercoordinateforview(float x, float y)
{
	float tempX = x, tempY = y;
	if (x < 220)
	{ 
		tempX = 220;
	}
	if (x > 860)
	{
		tempX = 860;
	}
	if (y < 240)
	{
		tempY = 240;
	}
	if (y > 554)
	{
		tempY = 554;
	}
	view.setCenter(tempX + 100, tempY);
	return view;
}