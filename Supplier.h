#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "Product.h"
#include <string>
using namespace std;
class Supplier {
private:
	int supplierID;
	string supplierName;
	string contractTerms;
	Product* suppliedProducts[100];
	int productCount;
	string suppliedproduct;
public:
	Supplier();
	Supplier(int, string, string, string);
	void addProduct(Product*);
	void orderRestock(Product*, int);
	void generateInvoice();
	void Display();
	int getSupplierID() const;
	string getSupplierName() const;
	string getContractTerms() const;
	int getProductCount() const;
	Product* getSuppliedProduct(int) const;
	string getSuppliedProduct() const;
	void setSupplierID(int);
	void setSupplierName(string);
	void setContractTerms(string);
	void setSuppliedProduct(string);
	

	
};
#endif
