#pragma once
#include <SFML/Graphics.hpp>
#include "objects_tree.h"
#include "map.h"
#include <vector>

class tree: public objects_tree
{
public:
	tree(karta& m);
	void update(karta& m) override;
};

