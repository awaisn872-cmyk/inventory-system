#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H
#include "GroceryProduct.h"
#include <string>
using namespace std;
class NonPerishable : public GroceryProduct {
private:
	int shelfLifeYears;
	string preservativeLevel;
public:
	NonPerishable();
	NonPerishable(string, string, double, int, int, bool, string, string, string, int, string);
	void setShelfLifeYears(int);
	void setPreservativeLevel(string);
	int getShelfLifeYears() const;
	string getPreservativeLevel() const;
	void getStorageInstructions() const;
	double calculateRisk() const;
	void Display() override;
};
#endif
