#include "NonPerishable.h"
#include <iostream>
using namespace std;
NonPerishable::NonPerishable() : GroceryProduct(), shelfLifeYears(0), preservativeLevel("") {}
NonPerishable::NonPerishable(
	string id,
	string n,
	double price,
	int quantity,
	int cal,
	bool hal,
	string e,
	string temp,
	string cDate,
	int sY,
	string pL
)
	: GroceryProduct(id, n, price, quantity, cal, hal),
	shelfLifeYears(sY),
	preservativeLevel(pL){}
	
void NonPerishable::setShelfLifeYears(int sY) {
	if (sY >= 0)
		shelfLifeYears = sY;
}
void NonPerishable::setPreservativeLevel(string pL) {
	preservativeLevel = pL;
}
int NonPerishable::getShelfLifeYears() const {
	return shelfLifeYears;
}
string NonPerishable::getPreservativeLevel() const {
	return preservativeLevel;
}
void NonPerishable::getStorageInstructions() const {
	cout << "STORE IN A COOL AND DRY PLACE " << endl;
	cout << "AVOID DIRECT SUNLIGHT " << endl;
	cout << "CHECK PRESERVATIVE LEVEL: " << preservativeLevel << endl;
	cout << "CHECK SHELF LIFE: " << shelfLifeYears << " YEARS" << endl;
}
double NonPerishable::calculateRisk() const {
	return 0.2;
}
void NonPerishable::Display() {
	cout << "Non-Perishable Grocery ID: " << getProductID()
		<< "  Name: " << getName()
		<< "  Price: $" << getPrice()
		<< "  Qty: " << getQuantity()
		<< "  Shelf Life: " << shelfLifeYears << " years" << endl;
}