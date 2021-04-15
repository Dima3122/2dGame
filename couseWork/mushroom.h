#pragma once
#include <SFML/Graphics.hpp>
#include "objects_tree.h"
#include "map.h"
#include "objects_tree.h"

class mushroom: public objects_tree
{
public:
	mushroom(karta& m);
	void update(karta& m) override;
};

