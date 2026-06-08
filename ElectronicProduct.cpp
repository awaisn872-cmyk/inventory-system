#include "ElectronicProduct.h"
#include <iostream>
using namespace std;

ElectronicProduct::ElectronicProduct(string id = "", string n = "", double pr = 0.0, int qty = 0, float w = 0.0, double v = 0.0, string brand = "")
		: Product(id, n, pr, qty), voltage(v), warranty(w), brandName(brand) {}
ElectronicProduct::ElectronicProduct(const ElectronicProduct& other) : Product(other), voltage(other.voltage), warranty(other.warranty), brandName(other.brandName) {}
	ElectronicProduct& ElectronicProduct :: operator=(const ElectronicProduct& other) {
		if (this != &other) {
			Product::operator=(other);
			voltage = other.voltage;
			warranty = other.warranty;
			brandName = other.brandName;
		}
		return *this;
	}
	ElectronicProduct:: ~ElectronicProduct() {}
	double ElectronicProduct::getVoltage() const {
		return voltage;
	}
	void ElectronicProduct::setVoltage(double v) {
		if (v >= 0) voltage = v;
	}
	float ElectronicProduct::getWarranty() const {
		return warranty;
	}
	void ElectronicProduct::setWarranty(float w) {
		if (w >= 0) warranty = w;
	}
	const string ElectronicProduct::getBrandName() const {
		return brandName;
	}
	void ElectronicProduct::setBrandName(string brand) {
		brandName = brand;

	}
	void ElectronicProduct:: testHardware() {
		cout << "Testing hardware for " << brandName << " with voltage " << voltage << "V and warranty " << warranty << " years." << endl;
	}

