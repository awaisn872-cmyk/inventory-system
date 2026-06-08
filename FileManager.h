#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Product.h"
#include "ElectronicProduct.h"
#include "ClothingProduct.h"
#include "InventorySection.h"
#include "GroceryProduct.h"
#include "Supplier.h"
#include <fstream>

void setTextColor(int);

class FileManager {
public:
	static void saveProduct(Product* );

	static void loadProducts(InventorySection&, InventorySection& , InventorySection& );

	static void saveDiscountedProduct(Product* , double , double );

	static void displayDiscounts();
	 static void showAllItemsFromFile(const string&);
	 static void saveSupplier(const Supplier&);
	 static void loadSuppliers(Supplier suppliers[], int& supplierCount);
	 static void showAllSuppliers();
	 static void rewriteProducts(InventorySection& ,InventorySection& , InventorySection&);
	 static void rewriteSuppliers(Supplier suppliers[], int supplierCount);
	static void clearFile();
};
#endif
