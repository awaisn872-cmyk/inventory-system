#ifndef INVENTORYSECTION_H
#define INVENTORYSECTION_H

#include "Product.h"

class InventorySection {
private:
	int aisleNumber;
	int capacity;
	Product* products[100];
	int productCount;

public:
	InventorySection() {}
	InventorySection(int, int);
    ~InventorySection();

	void addStock(Product* );

	void sortByID();

	Product* operator[](int);
	Product* searchProduct(string );
    
	void clearSection();

	int getProductCount() const;
	Product* getProduct(int) const;
	void removeProduct(string );
};


#endif