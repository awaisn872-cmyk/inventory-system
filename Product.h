#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
	string Productid;
	string name;
	double Price;
	int Quantity;
public:
	Product();
	Product(string, string, double, int);
	virtual void Display();
	string getProductID() const;
	double getPrice() const;
	string getName() const;
	void setPrice(double);
	int getQuantity() const;
	void setQuantity(int);
	void setName(string);
	virtual double calculateValue() const;
	virtual double calculateRisk() const = 0;
	virtual double ApplyDiscount(double);
	virtual ~Product();

	friend ostream& operator<<(ostream&, const Product&);

	bool operator==(const Product&) const;
	Product& operator=(const Product&);
};
#endif
