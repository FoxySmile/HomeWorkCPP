#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "Shelf.h"
class Fridge
{
private:
	vector<Shelf*> shelfs;
	Shelf* shelf;
	int maxProductOnTheShelf;
	int maxCountShelf;
	int countShelfs = 0;
	int countProducts = 0;
	bool flag = true;
public:
	Fridge(int maxCountShelf, int maxProductOnTheShelf);
	void addProductInShelf(Product* product);
	void getProductByIndexAndShelf(int indexProduct, int indexShelf);
	void showAllProducts();
};

