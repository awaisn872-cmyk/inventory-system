#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Product.h"
#include "InventorySection.h"
#include <string>
using namespace std;

class Warehouse {
private:
	string locationID;
	double totalSquareFootage;
	InventorySection sections[50];
	int sectionCount;
public:
	Warehouse(string , double );
	void addSection(const InventorySection& section);
	double getGlobalValue();
	void findShortages();
};

#endif
