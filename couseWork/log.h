#pragma once
#include "objects_tree.h"
#include "map.h"

class Log: public objects_tree
{
public:
	Log(karta& m);
	void update(karta& m) override;
};

