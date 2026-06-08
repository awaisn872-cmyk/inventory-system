#include "Product.h"
#include <iostream>

using namespace std;

Product::Product() : Productid(""), name(""), Price(0.0), Quantity(0) {}

Product::Product(string id, string n, double price, int quantity) : Productid(id), name(n), Price(price), Quantity(quantity) {}
void Product::Display() {
	cout << "ProductID: " << Productid << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << Price << endl;
	cout << "Quantity: " << Quantity << endl;
}
string Product::getProductID() const {
	return Productid;
}
double Product::getPrice() const {
	return Price;
}
string Product::getName() const {
	return name;
}
void Product::setPrice(double p) {
	if (p >= 0) Price = p;
}
int Product::getQuantity() const {
	return Quantity;
}
void Product::setQuantity(int q) {
	if (q >= 0) Quantity = q;
}
void Product::setName(string n) {
	name = n;
}
double Product::calculateValue() const {
	return Price * Quantity;
}
double Product::ApplyDiscount(double discount) {
	if (discount >= 0.0 && discount <= 100.0) {
		Price -= (Price * discount / 100.0);
	}
	return Price;
}
Product :: ~Product() {}

ostream& operator<<(ostream& os, const Product& p) {
	os << "ID: " << p.Productid << "  Name: " << p.name << "  Price: $" << p.Price;
	return os;
}

bool Product :: operator==(const Product& other) const {
	return this->Productid == other.Productid;
}
Product& Product :: operator=(const Product& other) {
	if (this != &other) {
		Productid = other.Productid;
		name = other.name;
		Price = other.Price;
		Quantity = other.Quantity;
	}
	return *this;
}