#pragma once
#include "Item.h"

using namespace std;

class SimulationGame :
	public Item
{
public:
	SimulationGame(int id, double price, string name, string description);
};

