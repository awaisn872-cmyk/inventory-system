#ifndef GROCERYPRODUCT_H
#define GROCERYPRODUCT_H
#include "Product.h"
#include <string>
class GroceryProduct : public Product {
private:
	int calories;
	bool isHalal;
public:
	GroceryProduct();
	GroceryProduct(string, string, double, int, int, bool);
	void setCalories(int);
	void setIsHalal(bool);
	int getCalories() const;
	bool getIsHalal() const;
	double calculateRisk() const override;
	void Display() override;
};
#endif 