#include "PerishableGrocery.h"
#include <iostream>
using namespace std;
PerishableGrocery::PerishableGrocery() : GroceryProduct(), expiryDate(""), storageTemp(""), currentDate("") {}
PerishableGrocery::PerishableGrocery(string id, string n, double price, int quantity, int cal, bool hal, string e, string s, string c) : GroceryProduct(id, n, price, quantity, cal, hal), expiryDate(e), storageTemp(s), currentDate(c) {}
void PerishableGrocery::setExpiryDate(string e) {
	expiryDate = e;
}
void PerishableGrocery::setStorageTemp(string temp) {
	storageTemp = temp;
}
void PerishableGrocery::setCurrentDate(string cDate) {
	currentDate = cDate;
}
string PerishableGrocery::getExpiryDate() const {
	return expiryDate;
}
string PerishableGrocery::getStorageTemp() const {
	return storageTemp;
}
string PerishableGrocery::getCurrentDate() const {
	return currentDate;
}
void PerishableGrocery::checkExpiry() const {
	if (expiryDate == currentDate) {
		cout << "PRODUCT IS EXPIRED." << endl;
	}
	else {
		cout << "PRODUCT IS SAFE." << endl;
	}
}
double PerishableGrocery::calculateRisk() const {
	return 2.5;
}
void PerishableGrocery::Display() {
	cout << "Perishable Grocery ID: " << getProductID()
		<< "  Name: " << getName()
		<< "  Price: $" << getPrice()
		<< "  Qty: " << getQuantity()
		<< "  Expiry: " << expiryDate
		<< "  Storage Temp: " << storageTemp
		<< "  Current Date: " << currentDate
		<< endl;
}
