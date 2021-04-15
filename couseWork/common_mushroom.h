#pragma once
#include "objects_tree.h"
#include "map.h"
class common_mushroom: public objects_tree
{
public:
	common_mushroom(karta& m);
	void update(karta& m) override;
};

