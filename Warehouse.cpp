#include "Warehouse.h"
#include "InventorySection.h"
#include <iostream>
using namespace std;
Warehouse::Warehouse(string loc, double area) : locationID(loc), totalSquareFootage(area), sectionCount(0) {}
void Warehouse::addSection(const InventorySection& section) {
	if (sectionCount < 50) {
		sections[sectionCount++] = section;
	}
}
double Warehouse::getGlobalValue() {
	double total = 0;
	for (int i = 0; i < sectionCount; i++) {
		for (int j = 0; j < sections[i].getProductCount(); j++) {
			if (sections[i].getProduct(j) != nullptr) {
				total += sections[i].getProduct(j)->calculateValue();
			}
		}
	}
	return total;
}
void Warehouse::findShortages() {
	cout << "\n===== LOW STOCK PRODUCTS =====\n";
	bool found = false;
	for (int i = 0; i < sectionCount; i++) {
		for (int j = 0; j < sections[i].getProductCount(); j++) {
			Product* p = sections[i].getProduct(j);
			if (p != nullptr && p->getQuantity() < 10) {
				found = true;
				cout << "ID: " << p->getProductID() << endl;
				cout << "Name: " << p->getName() << endl;
				cout << "Quantity: " << p->getQuantity() << endl << endl;
			}
		}
	}
	if (!found) {
		cout << "No shortages found." << endl;
	}
}