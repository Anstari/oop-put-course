#pragma once
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Store
{
private:

	vector<pair<Item*, int>> s_cart;

	vector<Item*> s_items;

	int getLongestNameFromCart();

public:
	Store(vector<Item*> items);

	vector<pair<Item*, int>> getCartItems() { return s_cart; }
	int getCartItemsCount();
	string addToCart(Item *newItem);
	string removeFromCart(Item *newItem);

	void clearCart();
	double getCartCost();
	void printCart();
	void printItems();

	vector<Item*> getItems() { return s_items; }
	size_t getNumberOfItems() { return s_items.size(); }
};

