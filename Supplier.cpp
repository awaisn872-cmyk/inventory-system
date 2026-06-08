#include "Supplier.h"
//#include "setTextColor.h"
#include <iostream>
using namespace std;
Supplier::Supplier(){}
Supplier::Supplier(int id, string name, string terms, string product) : supplierID(id), supplierName(name), contractTerms(terms), suppliedproduct(product), productCount(0) {}
void Supplier::addProduct(Product* p) {
	if (productCount < 100) {
		suppliedProducts[productCount++] = p;
	}
}
void Supplier::orderRestock(Product* p, int quantity) {
	//setTextColor(3);
	cout << "\nRestock Order Placed\n";
	//setTextColor(6);
	cout << "Supplier: " << supplierName << endl;
	cout << "Product: " << p->getName() << endl;
	cout << "Quantity: " << quantity << endl;
	//setTextColor(7);
}
void Supplier::generateInvoice() {
	//setTextColor(3);
	cout << "\n===== INVOICE =====\n";
	//setTextColor(6);
	cout << "Supplier: " << supplierName << endl;
	cout << "Contract Terms: " << contractTerms << endl;
	cout << "\nProducts:\n";
	//setTextColor(7);
	for (int i = 0; i < productCount; i++) {
		cout << suppliedProducts[i]->getName() << endl;
	}
}
void Supplier::Display() {
	//setTextColor(6);
	cout << "Supplier ID: " << supplierID << endl;
	cout << "Supplier Name: " << supplierName << endl;
	cout << "Contract Terms: " << contractTerms << endl;
	//setTextColor(7);

}
int Supplier::getSupplierID() const { return supplierID; }
string Supplier::getSupplierName() const { return supplierName; }
string Supplier::getContractTerms() const { return contractTerms; }
int Supplier::getProductCount() const { return productCount; }
Product* Supplier::getSuppliedProduct(int index) const {
	if (index >= 0 && index < productCount) {
		return suppliedProducts[index];
	}
	return nullptr;
}
string Supplier::getSuppliedProduct() const { return suppliedproduct; }
void Supplier::setSupplierID(int id) { supplierID = id; }
void Supplier::setSupplierName(string name) { supplierName = name; }
void Supplier::setContractTerms(string terms) { contractTerms = terms; }
void Supplier::setSuppliedProduct(string product) { suppliedproduct = product; }
