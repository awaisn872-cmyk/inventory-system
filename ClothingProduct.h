#ifndef CLOTHINGPRODUCT_H
#define CLOTHINGPRODUCT_H

#include "Product.h"

class ClothingProduct : public Product {
private:
	string Size;
	string Fabric;
	string Gender;
public:
	ClothingProduct();
    ClothingProduct(string, string, double, int, string, string , string);
	ClothingProduct(const ClothingProduct&);
	string getsize() const;
	void setsize(string );
	string getfabric() const;
	void setfabric(string);
		string getgender() const;
		void setgender(string );
		void fitGuide() const;
		double calculateRisk() const override;
}; 
#endif
