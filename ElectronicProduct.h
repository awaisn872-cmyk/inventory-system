#ifndef ELECTRONICPRODUCT_H

#define ELECTRONICPRODUCT_H

#include "Product.h"
#include<string>
using namespace std;



class ElectronicProduct : public Product {
private:
	double voltage;
	float warranty;
	string brandName;

public:
	ElectronicProduct(string, string, double, int, float , double, string );
	ElectronicProduct(const ElectronicProduct& );
	ElectronicProduct& operator=(const ElectronicProduct&);
	virtual ~ElectronicProduct();
	double getVoltage() const;
	void setVoltage(double);
	float getWarranty() const;
	void setWarranty(float);
	const string getBrandName() const;
	void setBrandName(string);
	void testHardware();

}; 
#endif 
