#include "Store.h"
#include <algorithm>
#include <iomanip>
#include <iostream>


Store::Store(vector<Item*> items) : s_items(items){
	
}

int Store::getCartItemsCount(){
	int itemsCount = 0;
	for (auto &item : s_cart)
		itemsCount += item.second;
	return itemsCount;
}

string  Store::addToCart(Item* newItem) {
	vector<pair<Item *, int>>::iterator it;
	// Increase count of newItem if that item is already added to a cart
	// otherwise push back newItem with item count 1
	if ((it = find_if(s_cart.begin(), s_cart.end(), [&newItem](const pair<Item*, int> &element){
		return element.first->getId() == newItem->getId();
	})) != s_cart.end()){
		(*it).second += 1;
	}else{
		s_cart.emplace_back(make_pair(newItem, 1));
	}
	return string{ "\nItem added to cart\n" };
}

string  Store::removeFromCart(Item* newItem){
	vector<pair<Item *, int>>::iterator it;
	
	if ((it = find_if(s_cart.begin(), s_cart.end(), [&newItem](const pair<Item*, int> &element) {
		return element.first->getId() == newItem->getId();
	})) != s_cart.end()){
		if ((*it).second > 1)
			(*it).second -= 1;
		else 
			s_cart.erase(it);
		return string{ "\nItem removed from cart\n" };
	}
	return string{ "\nItem not found in the cart\n" };
}

void Store::clearCart(){
	s_cart.clear();
}

double Store::getCartCost(){
	double sum = 0.0;
	for(auto &item: s_cart)
		sum += (item.first->getPrice() * item.second);
	return sum;
}

void Store::printCart(){
	// Sort items by name
	sort(s_cart.begin(), s_cart.end(),[](pair<Item*, int> a, pair<Item*, int> b){
		return a.first->getName() < b.first->getName();
	});
	
	int maxLength = getLongestNameFromCart();
	int index = 0;
	cout << "Your cart\n\n";
	cout <<"  Name  " << setw(maxLength) << " Count\t" << " Price\n";
	for(auto& item: s_cart){
		cout  << item.first->getName() << " " << setw(maxLength - item.first->getName().length() + 3) << item.second << "\t" <<
			item.first->getPrice() * item.second << "$";
		if (item.second > 1)
			cout << setw(10) << " " << item.first->getPrice() << "$ per item";
		cout << '\n';
	}
}

void Store::printItems(){
	int index = 0;
	for (auto it = s_items.begin(); it != s_items.end(); ++it)
		cout << ++index << ". " <<  (*it)->getName() << " " << (*it)->getPrice() << "$\n";
}

int Store::getLongestNameFromCart(){
	int maxLength = 0;
	for(auto &p: s_cart){
		if (p.first->getName().length() > maxLength)
			maxLength = p.first->getName().length();
	}
	return maxLength;
}
