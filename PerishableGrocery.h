#ifndef PERISHABLEGROCERY_H
#define PERISHABLEGROCERY_H
#include "GroceryProduct.h"
#include <string>
using namespace std;
class PerishableGrocery : public GroceryProduct {
private:
	string expiryDate;
	string storageTemp;
	string currentDate;
public:
	PerishableGrocery();
	PerishableGrocery(string, string, double, int, int, bool, string, string, string);
	void setExpiryDate(string);
	void setStorageTemp(string);
	void setCurrentDate(string);
	string getExpiryDate() const;
	string getStorageTemp() const;
	string getCurrentDate() const;
	void checkExpiry() const;
	double calculateRisk() const;
	void Display() override;
};
#endif
