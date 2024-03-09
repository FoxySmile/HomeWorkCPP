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
		if (flag) {
			shelf->addProduct(product);
			shelfs.push_back(shelf);
			countProducts++;
			flag = false;
			return;
		}
		
		if (countProducts == maxProductOnTheShelf) {
			if (countShelfs == maxCountShelf - 1 && countProducts == maxProductOnTheShelf) {
				return;
			}
			shelf = new Shelf(maxProductOnTheShelf);
			shelf->addProduct(product);
			shelfs.push_back(shelf);
			countProducts = 0;
			countProducts++;
			countShelfs++;
			return;
		}
		else {
			shelf->addProduct(product);
			countProducts++;
			return;
		}
	}
};

void Fridge::getProductByIndexAndShelf(int indexProduct, int indexShelf)
{
	Shelf* buf = *(shelfs.begin() + indexShelf);
	buf->getProductByIndex(indexShelf)->getInfo();
}

void Fridge::showAllProducts()
{
	int index = 0;
	for (auto el : shelfs) {
		cout << "polka " << 1+index++ << endl;
		el->showAllProducts();
		cout << "############" << endl;
	}
}
