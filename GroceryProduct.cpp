#include "GroceryProduct.h"
#include <iostream>
using namespace std;
GroceryProduct::GroceryProduct() : Product(), calories(0), isHalal(false) {}
GroceryProduct::GroceryProduct(string id, string n, double price, int quantity, int cal, bool hal) : Product(id, n, price, quantity), calories(cal), isHalal(hal) {}
void GroceryProduct::setCalories(int cal) {
	if (cal >= 0)
		calories = cal;
}
void GroceryProduct::setIsHalal(bool hal) {
	isHalal = hal;
}
int GroceryProduct::getCalories() const {
	return calories;
}
bool GroceryProduct::getIsHalal() const {
	return isHalal;
}
double GroceryProduct::calculateRisk() const {
	return isHalal ? 0.8 : 1.5;
}
void GroceryProduct::Display() {
	cout << "Grocery ID: " << getProductID()
		<< "  Name: " << getName()
		<< "  Price: $" << getPrice()
		<< "  Qty: " << getQuantity()
		<< "  Calories: " << calories << endl;
	if (isHalal) {
		cout << "  Halal: Yes" << endl;
	}
	else {
		cout << "  Halal: No" << endl;
	}
}