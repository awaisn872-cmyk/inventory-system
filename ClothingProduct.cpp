#include "ClothingProduct.h"

#include <iostream>
using namespace std;



ClothingProduct ::	ClothingProduct() : Size("0"), Fabric(""), Gender("") {}

ClothingProduct::ClothingProduct(string id, string n, double price, int quantity, string size, string fabric, string gender)
		: Product(id, n, price, quantity), Size(size), Fabric(fabric), Gender(gender) {}

ClothingProduct::ClothingProduct(const ClothingProduct& CP) : Product(CP) {
		Size = CP.Size;
		Fabric = CP.Fabric;
		Gender = CP.Gender;
	}
	string ClothingProduct::getsize() const {
		return Size;
	}
	void ClothingProduct::setsize(string s) {
		Size = s;
	}
	string ClothingProduct::getfabric() const {
		return Fabric;
	}
	void ClothingProduct::setfabric(string f) {
		Fabric = f;
	}
	string ClothingProduct::getgender() const {
		return Gender;
	}
	void ClothingProduct::setgender(string g) {
		if (g == "M" || g == "m" || g == "F" || g == "f")
			Gender = g;
	}
	void ClothingProduct::fitGuide() const {
		if (Fabric.empty()) {
			cout << "Not specified";
		}
		else {
			cout << Fabric;
		}
		if (Gender == "M" || Gender == "m") {
			cout << "Category: Men's Wear" << endl;
		}
		else if (Gender == "F" || Gender == "f") {
			cout << "Category: Women's Wear" << endl;
		}
		else {
			cout << "Category: Unisex / General" << endl;
		}
		cout << "Size: " << Size << " inches -> ";
		if (Size == "0") {
			cout << "Invalid Size!" << endl;
		}
		else if (Size == "S") {
			cout << "Fits: Small (S)" << endl;
		}
		else if (Size == "M") {
			cout << "Fits: Medium (M)" << endl;
		}
		else if (Size == "L") {
			cout << "Fits: Large (L)" << endl;
		}
		else {
			cout << "Fits: Extra Large (XL)" << endl;
		}
	}
	double ClothingProduct:: calculateRisk() const {
		return 0.5;
	}
