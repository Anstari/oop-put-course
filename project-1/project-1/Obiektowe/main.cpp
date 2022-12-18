#include <cstdlib>
#include <iostream>

#include "RPGGame.h"
#include "SimulationGame.h"
#include "Store.h"

using namespace std;


string showItemMenu(Store &store, Item *item){
	int choice = -1;
	system("cls");
	while (true) {
		item->showItemDescription();
		cout << "1. Add to cart\n";
		cout << "2. Remove from cart\n";
		cout << "3. Go back to store\n";
		cout << "\nYour choice: ";
		cin >> choice;
		if (choice <= 0 || choice > 3) {
			system("cls");
			cerr << "\nIncorrect choice\n";
			getchar(); getchar();
			continue;
		}

		switch(choice){
		case 1:
			return store.addToCart(item); break;
		case 2:
			return store.removeFromCart(item); break;
		}
		break;
		
	}
	system("cls");
	return string{};
}

void cartMenu(Store &store){
	system("cls");
	int choice = -1;
	while (true) {
		store.printCart();
		cout << "\n1. Go back to store\n";
		if(store.getCartItemsCount() != 0)
			cout << "2. Checkout\n";
		cin >> choice;
		if (choice <= 0 || choice > (store.getCartItemsCount() != 0) + 1) {
			system("cls");
			cerr << "\nIncorrect choice\n";
			getchar(); getchar();
			continue;
		}

		switch(choice){
		case 1:
			return;
		case 2:
			cout << "Thank you for your purchase. Game keys will be sent to you via email. :)\n";
			store.clearCart();
			return;
		}
	}
}

void storeMenu(){
	Item *item1 = new RPGGame(1, 49.99, "Witcher 3",
		"The Witcher 3: Wild Hunt is an action role-playing game with a third-person perspective.");
	Item *item2 = new RPGGame(2, 29.99, "Skyrim",
		"The Elder Scrolls V: Skyrim is an action role-playing game, playable from either a first or third-person perspective.");
	Item *item3 = new SimulationGame(3, 4.99, "Robot Vacuum Simulator X",
		"Robot Vacuum Simulator X: The most realistic robotic vacuum cleaning simulator ever made.");
	
	vector<Item*> items{ item1, item2, item3 };
	Store store(items);
	
	int choice = -1;

	while(choice!=0){
		system("cls");
		cout << "Available options:\n\n";
		store.printItems();
		cout << "4. Show cart\n";
		cout << "0. Exit\n";
		cout << "\nYour cart: " << store.getCartItemsCount() << " items, " << store.getCartCost() << "$\n";
		cout << "\nChoose option: ";
		cin >> choice;
		if(choice < 0 || choice > store.getNumberOfItems() + 1){
			cout << "\nIncorrect item\n";
			fflush(stdin);
			getchar(); getchar();
			continue;
		}
		switch (choice) {
		case 4:
			cartMenu(store); break;
		case 0:
			cout << "Thank you for choosing our application";
			break;
		default:
			cout << showItemMenu(store, store.getItems()[choice - 1]);
		}
		getchar(); getchar();
		system("cls");
	}
}

int main(){
	storeMenu();
}