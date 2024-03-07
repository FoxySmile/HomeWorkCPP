#pragma once
#include <iostream>
#include "Product.h"
#include <vector>
using namespace std;

class Shelf
{
protected:
	vector<Product*> products;
	int maxCountProducts;
	int countProducts = 0;
public:
	Shelf(int maxCountProducts);
	void addProduct(Product* product);
	void showAllProducts();
	Product* getProductByIndex(int index);
};

