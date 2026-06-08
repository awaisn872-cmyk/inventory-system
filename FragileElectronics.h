#ifndef FRAGILEELECTRONICS_H
#define FRAGILEELECTRONICS_H


#include "ElectronicProduct.h"

class FragileElectronics : public ElectronicProduct {
private:
	int fragilityRating;
	string packagingType;
public:
	FragileElectronics(string, string, double, int, int, string, float, double, const char*);
	FragileElectronics(const FragileElectronics&);
	FragileElectronics& operator=(const FragileElectronics&);
	int getFragilityRating() const;
	void setFragilityRating(int);
	string getPackagingType() const;
	void setPackagingType(string);
	double calculateShippingRisk();
	double calculateRisk() const override;

	void Display() ;
	double ApplyDiscount(double) override;
};
#endif
