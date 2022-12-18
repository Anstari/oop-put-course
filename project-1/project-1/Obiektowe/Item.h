#pragma once
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
	int i_id;
	double i_price;
	string i_name;
	string i_description;

public:
	Item(int id, double price, string name, string description);

	double getPrice() { return i_price; }
	
	string getName() { return i_name; }

	string getDescription() { return i_description; }

	int getId() { return i_id; }
	
	void showItemDescription();

};

