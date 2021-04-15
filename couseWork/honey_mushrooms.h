#pragma once
#include "objects_tree.h"
#include "map.h"
class honey_mushrooms: public objects_tree
{
public:
	honey_mushrooms(karta &m);
	void update(karta& m) override;
};

