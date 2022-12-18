#pragma once
#include "Item.h"

using namespace std;

class RPGGame :
	public Item
{
public:
	RPGGame(int id, double price, string name, string description);
};

