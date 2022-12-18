#include "Item.h"
#include <iostream>

Item::Item(int id, double price, string name, string description)
	: i_id(id), i_price(price), i_name(name), i_description(description){
}

void Item::showItemDescription(){
	cout << i_description << "\n\n";
}

