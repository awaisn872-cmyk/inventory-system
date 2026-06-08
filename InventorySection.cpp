#include "InventorySection.h"
#include <iostream>


InventorySection :: InventorySection(int aisle = 0, int cap = 100) {
		aisleNumber = aisle;
		capacity = cap;
		productCount = 0;
	}

InventorySection ::	~InventorySection() {
}


	void InventorySection:: addStock(Product* p) {
		if (productCount < capacity) {
			products[productCount++] = p;
		}
		else {
			cout << "Section Full!" << endl;
		}
	}

	void InventorySection:: sortByID() {
		for (int i = 0; i < productCount - 1; i++) {
			for (int j = i + 1; j < productCount; j++) {
				if (products[i]->getProductID() > products[j]->getProductID()) {
					Product* temp = products[i];
					products[i] = products[j];
					products[j] = temp;
				}
			}
		}
	}

	Product* InventorySection :: operator[](int index) {
		if (index >= 0 && index < productCount)
			return products[index];

		return nullptr;
	}
	Product* InventorySection:: searchProduct(string id)
	{
		for (int index = 0; index < productCount; index++)
		{
			if (products[index]->getProductID() == id)
			{
				return products[index];
			}
		}

		return nullptr;
	}

	void InventorySection:: clearSection() {
		for (int i = 0; i < productCount; i++) {
			delete products[i];
			products[i] = nullptr;
		}
		productCount = 0;
	}

	int InventorySection::getProductCount() const {
		return productCount;
	}
	

	Product* InventorySection::getProduct(int index) const {
		if (index >= 0 && index < productCount)
			return products[index];

		return nullptr;
	}
	void InventorySection::removeProduct(string id)
	{
		for (int i = 0; i < productCount; i++)
		{
			if (products[i]->getProductID() == id)
			{
				delete products[i];

				for (int j = i; j < productCount - 1; j++)
					products[j] = products[j + 1];

				productCount--;
				return;
			}
		}
	}