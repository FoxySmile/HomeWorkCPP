#include "Fridge.h"

Fridge::Fridge(int maxCountShelf, int maxProductOnTheShelf)
{
	this->maxCountShelf = maxCountShelf;
	this->maxProductOnTheShelf = maxProductOnTheShelf;
	shelf = new Shelf(maxProductOnTheShelf);
}

void Fridge::addProductInShelf(Product* product)
{
	if (countShelfs < maxCountShelf) {
		for (auto el : shelfs) {
			if (countProducts == maxProductOnTheShelf) {
				shelf = nullptr;
				shelf = new Shelf(maxProductOnTheShelf);
				countProducts = 0;
				countShelfs++;
				continue;
			}
			el->addProduct(product);
			countProducts++;
			return;
		}
		shelf->addProduct(product);
		countProducts++;
		shelfs.push_back(shelf);
	}
};

Product* Fridge::getProductByIndexAndShelf(int indexProduct, int indexShelf)
{
	Product* buf = new Product("Re");
	return buf;
}

void Fridge::showAllProducts()
{
	int index = 0;
	for (auto el : shelfs) {
		cout << "polka" << index++ << endl;
		el->showAllProducts();
		cout << "############" << endl;
	}
}
