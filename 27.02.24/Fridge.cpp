#include "Fridge.h"

Fridge::Fridge(int maxCountShelf, int maxProductOnTheShelf)
{
	this->maxCountShelf = maxCountShelf;
	this->maxProductOnTheShelf = maxProductOnTheShelf;
}

void Fridge::addProductInShelf(Product* product)
{
	Shelf* shelf = new Shelf(maxProductOnTheShelf);
	if (countShelfs < maxCountShelf) {
		for (auto el : shelfs) {
			if (countProducts < maxProductOnTheShelf) {

			}
		}
	}
	
}

Product* Fridge::getProductByIndexAndShelf(int indexProduct, int indexShelf)
{
	Product* buf = new Product("Re");
	return buf;
}

void Fridge::showAllProducts()
{
	
}
