#include <iostream>
#include <vector>

#define random(a,b) a + rand() % (b - a + 1)

using namespace std;

#include "Fish.h"
#include "Meet.h"
#include "Milk.h"
#include "Product.h"
#include "Shelf.h"
#include "Fridge.h"

string nameFish[] = { "Fish1", "Fish2", "Fish3" };
string nameMeet[] = { "Meet1", "Meet2", "Meet3" };
string nameMilk[] = { "Milk1", "Milk2", "Milk3" };

int main() {
	srand(time(NULL));
	/*Shelf shelf1(9);
	for (int i = 0; i < 3; i++) {
		shelf1.addProduct(new Fish(nameFish[random(0, 2)]));
	}
	for (int i = 0; i < 3; i++) {
		shelf1.addProduct(new Meet(nameMeet[random(0, 2)]));
	}
	for (int i = 0; i < 3; i++) {
		shelf1.addProduct(new Milk (nameMilk[random(0, 2)]));
	}

	shelf1.showAllProducts();
	cout << "\n########" << endl;
	shelf1.getProductByIndex(2)->getInfo();
	shelf1.getProductByIndex(3)->getInfo();
	cout << "########\n" << endl;
	shelf1.addProduct(new Fish("Big Fish"));
	shelf1.showAllProducts();*/

	Fridge fridge(3, 5);
	fridge.addProductInShelf(new Fish("1"));
	fridge.addProductInShelf(new Fish("2"));
	fridge.addProductInShelf(new Fish("3"));
	fridge.addProductInShelf(new Fish("4"));
	fridge.addProductInShelf(new Fish("5"));
	fridge.addProductInShelf(new Fish("6"));
	fridge.addProductInShelf(new Fish("7"));
	cout << "Get Product: ";
	fridge.getProductByIndexAndShelf(2, 0);
	cout << endl;
	fridge.showAllProducts();
}