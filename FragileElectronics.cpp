#include "FragileElectronics.h"

#include <iostream>
using namespace std;


FragileElectronics ::	FragileElectronics(string id = "", string n = "", double pr = 0.0, int qty = 0, int f = 0, string p = "", float w = 0.0, double v = 0.0, const char* brand = "")
		: ElectronicProduct(id, n, pr, qty, w, v, brand), fragilityRating(f), packagingType(p) {}
FragileElectronics::FragileElectronics(const FragileElectronics& other) : ElectronicProduct(other) {
		fragilityRating = other.fragilityRating;
		packagingType = other.packagingType;

	}
	FragileElectronics& FragileElectronics :: operator=(const FragileElectronics& other) {
		if (this != &other) {
			ElectronicProduct::operator=(other);
			fragilityRating = other.fragilityRating;
			packagingType = other.packagingType;
		}
		return *this;
	}
	int FragileElectronics::getFragilityRating() const { return fragilityRating; }
	void FragileElectronics:: setFragilityRating(int f) {
		if (f >= 1 && f <= 10)
			fragilityRating = f;
	}
	string  FragileElectronics:: getPackagingType() const { return packagingType; }
	void FragileElectronics::setPackagingType(string p) { packagingType = p; }
	double FragileElectronics::calculateShippingRisk() {
		return fragilityRating * 0.1;
	}
	double FragileElectronics::calculateRisk() const {
		return fragilityRating * 1.5;
	}

	void FragileElectronics::Display()  {
		cout << "Fragile Tech ID: " << getProductID()
			<< "  Brand: " << getBrandName()
			<< "  Price: $" << getPrice()
			<< "  Qty: " << getQuantity()
			<< "  Risk Score: " << calculateRisk() << endl;
	}
	double FragileElectronics::	ApplyDiscount(double discount)  {
		double finalDiscount = 5.0;
		double newPrice = getPrice() - (getPrice() * finalDiscount / 100.0);
		setPrice(newPrice);
		return getPrice();
	}