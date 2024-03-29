#include "Shelf.h"

Shelf::Shelf(int maxCountProducts)
{
	this->maxCountProducts = maxCountProducts;
}

void Shelf::addProduct(Product* product)
{
	if (countProducts < maxCountProducts) {
		int count = 0;
		bool flag = true;
		for (auto el : products) {
			if (el == nullptr) {
				flag = false;
				products[count] = product;
				break;
			}
			count++;
		}
		if (flag) products.push_back(product);
		countProducts++;
	}
}

void Shelf::showAllProducts()
{
	for (auto el : products) {
		if (el != nullptr) {
			el->getInfo();
		}
		else {
			cout << "-----------" << endl;
		}
	}
}

Product* Shelf::getProductByIndex(int index)
{
	Product* buf = *(products.begin() + index);
	products[index] = nullptr;
	countProducts--;
	return buf;
}
