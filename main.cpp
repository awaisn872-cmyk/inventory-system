
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <windows.h>
#include "Product.h"
#include "ElectronicProduct.h"
#include "FragileElectronics.h"
#include "GroceryProduct.h"
#include "PerishableGrocery.h"
#include "NonPerishable.h"
//#include "setTextColor.h"
#include "Warehouse.h"
#include "Supplier.h"
#include "FileManager.h"
#include "InventorySection.h"
#include "ClothingProduct.h"
#include "TransactionLog.h"

using namespace std;


template <typename S>
S safeInput(const string& msg) {
	S value;
	while (true) {
		cout << msg;
		cin >> value;
		if (!cin.fail() && value >= 0.0)
			return value;
		cin.clear();
		cin.ignore(1000, '\n');
		setTextColor(4);
		cout << "Invalid input. Try again.\n";
		setTextColor(7);
	}
}
bool checkdublication(InventorySection& section, string id) {
	for (int i = 0; i < section.getProductCount(); i++) {
		Product* p = section.getProduct(i);
		if (p != nullptr) {
			
			if (p->getProductID() == id) {
				return true; 
			}
		}
	}
	return false; 
}


string safeInputString(const string& msg) {
	string value;
	while (true) {
		cout << msg;
		cin >> value;
		if (!value.empty())
			return value;
		cin.clear();
		cin.ignore(1000, '\n');
		setTextColor(4);
		cout << "Input cannot be empty. Try again.\n";
		setTextColor(7);
	}
}
int main() {
	InventorySection techAisle(101, 50);
	InventorySection foodAisle(202, 50);
	InventorySection clothingAisle(303, 50);
	Supplier suppliers[100];
	int supplierCount = 0;

	int choice = -1;

	FileManager::loadProducts(techAisle, foodAisle, clothingAisle);
	FileManager::loadSuppliers(suppliers,supplierCount);
	FileManager::clearFile();

	for (int i = 0; i < techAisle.getProductCount(); i++)
		FileManager::saveProduct(techAisle.getProduct(i));
	for (int i = 0; i < foodAisle.getProductCount(); i++)
		FileManager::saveProduct(foodAisle.getProduct(i));
	for (int i = 0; i < clothingAisle.getProductCount(); i++)
		FileManager::saveProduct(clothingAisle.getProduct(i));

	do {
		setTextColor(1);
		cout << "\n========= INVENTORY MANAGEMENT SYSTEM =========\n";
		setTextColor(5);
		cout << "1. Add Electronic Product\n";
		cout << "2. Add Grocery Product\n";
		cout << "3. Add Clothing Product\n";
		cout << "4. Show Warehouse Value\n";
		cout << "5. Show Low Stock Report\n";
		cout << "6. Sort by ID\n";
		cout << "7. Applying Discounts\n";
		cout << "8. Display Discounts\n";
		cout << "9. Show All Products\n";
		cout << "10. Supplier Management\n";
		cout << "11. Calculate Product Risk\n";
		cout << "12. Update Product\n";
		cout << "13. Delete Product\n";
		cout << "14. Data Reset From File\n";
		cout << "0. Save and Exit\n";

		setTextColor(6);

		choice = safeInput<int>("Enter choice: ");
		setTextColor(7);

		if (choice == 1) {

			string id = safeInputString("Enter Product ID: ");
			if (checkdublication(foodAisle, id) == true ||
				checkdublication(techAisle, id) == true ||
				(checkdublication(clothingAisle, id) == true)) {
				setTextColor(4);
				cout << "Product ID already exists!\n";
				setTextColor(7);
				continue;
			}
			string name = safeInputString("Enter Name: ");
			string brand = safeInputString("Enter Brand: ");

			double price = safeInput<double>("Enter Price: ");
			int qty = safeInput<int>("Enter Quantity: ");
			double voltage = safeInput<double>("Enter Voltage: ");
			float warranty = safeInput<float>("Enter Warranty (years): ");

			Product* product = new FragileElectronics(id, name, price, qty, 5, "Foam Box", warranty, voltage, brand.c_str());

			techAisle.addStock(product);
			setTextColor(2);
			cout << "Electronic Product Added Successfully\n";
			setTextColor(7);
			FileManager::saveProduct(product);
		}

		else if (choice == 2) {
			string id = safeInputString("Enter Product ID: ");

			if (checkdublication(foodAisle, id) ||
				checkdublication(techAisle, id) ||
				checkdublication(clothingAisle, id))
			{
				setTextColor(4);
				cout << "Product ID already exists!\n";
				setTextColor(7);
				continue;
			}

			cout << "\n1. Perishable Grocery\n";
			cout << "2. Non-Perishable Grocery\n";
			cout << "0. Back to main menu\n";

			int groceryType;
			cout <<"Enter Choice: ";
			do {
				cin >> groceryType;
				if (groceryType == 1)
				{
					string name = safeInputString("Enter Name: ");
					double price = safeInput<double>("Enter Price: ");
					int qty = safeInput<int>("Enter Quantity: ");
					string expiryDate;
					string storageTemp;
					string currentDate;

					cout << "Enter Expiry Date: ";
					cin >> expiryDate;

					cout << "Enter Storage Temperature: ";
					cin >> storageTemp;

					cout << "Enter Current Date: ";
					cin >> currentDate;

					Product* product = new PerishableGrocery(
						id,
						name,
						price,
						qty,
						100,
						true,
						expiryDate,
						storageTemp,
						currentDate
					);

					foodAisle.addStock(product);
					FileManager::saveProduct(product);
				}
				else if (groceryType == 2)
				{
					string name = safeInputString("Enter Name: ");
					double price = safeInput<double>("Enter Price: ");
					int qty = safeInput<int>("Enter Quantity: ");
					int shelfLifeYears =
						safeInput<int>("Enter Shelf Life Years: ");

					string preservativeLevel;

					cout << "Enter Preservative Level: ";
					cin >> preservativeLevel;

					Product* product = new NonPerishable(
						id,
						name,
						price,
						qty,
						100,
						true,
						"",
						"",
						"",
						shelfLifeYears,
						preservativeLevel
					);

					foodAisle.addStock(product);
					FileManager::saveProduct(product);
				}
				else if (groceryType == 0) {
					cout << "Return to main menu.......\n\n\n";
				}
				else {
					cout << "\nInvalid Input.\n";
				}
			} while (groceryType != 0);
		}
		else if (choice == 3) {

			string id = safeInputString("Enter Product ID: ");

			if (checkdublication(foodAisle, id) == true ||
				checkdublication(techAisle, id) == true ||
				(checkdublication(clothingAisle, id) == true)) {
				setTextColor(4);
				cout << "Product ID already exists!\n";
				setTextColor(7);
				continue;
			}

			string name = safeInputString("Enter Name: ");
			string fabric = safeInputString("Enter Fabric: ");

			
			string size;
			do {
				cout << "Enter Size (S/M/L/XL): ";
				cin >> size;

				if (size != "S" && size != "s" &&
					size != "M" && size != "m" &&
					size != "L" && size != "l" &&
					size != "XL" && size != "xl") {

					setTextColor(4);
					cout << "Enter only (S/M/L/XL)\n";
					setTextColor(7);
				}

			} while (size != "S" && size != "s" &&
				size != "M" && size != "m" &&
				size != "L" && size != "l" &&
				size != "XL" && size != "xl");

			string gender;
			do {
				cout << "Enter Gender (M/F): ";
				cin >> gender;

				if (gender != "M" && gender != "m" &&
					gender != "F" && gender != "f") {

					setTextColor(4);
					cout << "Enter only M or F\n";
					setTextColor(7);
				}

			} while (gender != "M" && gender != "m" &&
				gender != "F" && gender != "f");

			double price = safeInput<double>("Enter Price: ");
			int quantity = safeInput<int>("Enter Quantity: ");

			Product* product = new ClothingProduct(
				id,
				name,
				price,
				quantity,
				size,
				fabric,
				gender
			);

			clothingAisle.addStock(product);

			setTextColor(2);
			cout << "Clothing Product Added Successfully\n";
			setTextColor(7);
			FileManager::saveProduct(product);
		}

		else if (choice == 4) {

			Warehouse warehouse("Lahore-Main", 5000);
			warehouse.addSection(techAisle);
			warehouse.addSection(foodAisle);
			warehouse.addSection(clothingAisle);

			cout << "\nTotal Warehouse Value: "
				<< warehouse.getGlobalValue() << endl;
		}

		else if (choice == 5) {

			Warehouse warehouse("Lahore-Main", 5000);
			warehouse.addSection(techAisle);
			warehouse.addSection(foodAisle);
			warehouse.addSection(clothingAisle);

			warehouse.findShortages();
		}

		else if (choice == 6) {
			techAisle.sortByID();
			setTextColor(2);
			cout << "Tech Aisle Sorted by Product ID\n";
			setTextColor(7);
		}

		else if (choice == 7) {
			string id = safeInputString("Enter Product ID to apply discount: ");
			Product* p = techAisle.searchProduct(id);

			if (!p) p = foodAisle.searchProduct(id);
			if (!p) p = clothingAisle.searchProduct(id);
			if (p) {
				double originalPrice = p->getPrice();
				double discount = safeInput<double>("Enter discount %: ");
				double newPrice = p->ApplyDiscount(discount);

				setTextColor(2);
				cout << "\n Discount Applied!\n";
				cout << "Original Price: $" << originalPrice << endl;
				cout << "New Price: $" << newPrice << endl;
				setTextColor(7);

				FileManager::saveDiscountedProduct(p, originalPrice, discount);

				setTextColor(2);
				cout << "Saved to discounts.txt\n";
				setTextColor(7);
			}
			else {
				setTextColor(4);
				cout << "Product not found\n";
				setTextColor(7);
			}
		}

		else if (choice == 8) {
			FileManager::displayDiscounts();
		}

		else if (choice == 9) {
			FileManager::showAllItemsFromFile("products.txt");
		}

		else if (choice == 10)
		{
			int supplierChoice;
			cout << "\n===== SUPPLIER MANAGEMENT =====\n";
			cout << "1. Add Supplier\n";
			cout << "2. Show Suppliers\n";
			cout << "3. Place Restock Order\n";
			cout << "4. Update Supplier\n";
			cout << "5. Delete Supplier\n";
			cout << "0. Back to Main Menu\n";
			do {

				supplierChoice = safeInput<int>("Enter Choice: ");

				if (supplierChoice == 1)
				{
					int id = safeInput<int>("Enter Supplier ID: ");

					string name =
						safeInputString("Enter Supplier Name: ");

					string contract =
						safeInputString("Enter Contract Terms: ");

					string suppliedProduct =
						safeInputString("Enter Product ID Supplied: ");

					Supplier supplier(
						id,
						name,
						contract,
						suppliedProduct
					);

					suppliers[supplierCount++] = supplier;

					FileManager::saveSupplier(supplier);

					cout << "Supplier Added Successfully\n";
				}

				else if (supplierChoice == 2)
				{
					FileManager::showAllSuppliers();
				}
				else if (supplierChoice == 3)
				{
					string productId = safeInputString("Enter Product ID: ");

					Product* p = techAisle.searchProduct(productId);
					if (!p) p = foodAisle.searchProduct(productId);
					if (!p) p = clothingAisle.searchProduct(productId);

					if (!p)
					{
						cout << "Product not found\n";
						continue;
					}

					int supplierId = safeInput<int>("Enter Supplier ID: ");
					int quantity = safeInput<int>("Enter Quantity: ");

					Supplier* selectedSupplier = nullptr;

					for (int i = 0; i < supplierCount; i++)
					{
						if (suppliers[i].getSupplierID() == supplierId)
						{
							selectedSupplier = &suppliers[i];
							break;
						}
					}

					if (selectedSupplier)
					{
						selectedSupplier->orderRestock(p, quantity);
					}
					else
					{
						cout << "Supplier not found\n";
					}
				}
				else if (supplierChoice == 4)
				{
					int id = safeInput<int>("Enter Supplier ID to Update: ");

					bool found = false;

					for (int i = 0; i < supplierCount; i++)
					{
						if (suppliers[i].getSupplierID() == id)
						{
							string newName = safeInputString("Enter New Name: ");
							string newContract = safeInputString("Enter New Contract: ");
							string newProduct = safeInputString("Enter New Product ID: ");

							suppliers[i].setSupplierName(newName);
							suppliers[i].setContractTerms(newContract);
							suppliers[i].setSuppliedProduct(newProduct);

							cout << "Supplier Updated Successfully\n";
							FileManager::rewriteSuppliers(suppliers, supplierCount);
							found = true;
							break;
						}
					}

					if (!found)
						cout << "Supplier not found\n";
				}
				else if (supplierChoice == 5)
				{
					int id = safeInput<int>("Enter Supplier ID to Delete: ");

					bool found = false;

					for (int i = 0; i < supplierCount; i++)
					{
						if (suppliers[i].getSupplierID() == id)
						{
							for (int j = i; j < supplierCount - 1; j++)
							{
								suppliers[j] = suppliers[j + 1];
							}

							supplierCount--;

							cout << "Supplier Deleted Successfully\n";
							FileManager::rewriteSuppliers(suppliers, supplierCount);
							found = true;
							break;
						}
					}

					if (!found)
						cout << "Supplier not found\n";
				}
				else if (choice == 0) {
					cout << "Returning to Main Menu...\n";
				}
				else {
					setTextColor(4);
					cout << "Invalid Choice\n";
					setTextColor(7);
				}
			} while (supplierChoice != 0);
		} 
		else if (choice == 11)
		{
			string productId =
				safeInputString("Enter Product ID: ");

			Product* selectedProduct =
				techAisle.searchProduct(productId);

			if (!selectedProduct)
				selectedProduct = foodAisle.searchProduct(productId);

			if (!selectedProduct)
				selectedProduct = clothingAisle.searchProduct(productId);

			if (selectedProduct)
			{
				cout << "\nProduct: "
					<< selectedProduct->getName()
					<< endl;

				cout << "Risk Value: "
					<< selectedProduct->calculateRisk()
					<< endl;
			}
			else
			{
				setTextColor(4);
				cout << "Product not found\n";
				setTextColor(7);
			}
		}
		else if (choice == 12)
		{
			string id = safeInputString("Enter Product ID to Update: ");

			Product* p = techAisle.searchProduct(id);
			InventorySection* section = &techAisle;

			if (!p) { p = foodAisle.searchProduct(id); section = &foodAisle; }
			if (!p) { p = clothingAisle.searchProduct(id); section = &clothingAisle; }

			if (!p)
			{
				cout << "Product not found\n";
				continue;
			}

			string newName = safeInputString("Enter New Name: ");
			double newPrice = safeInput<double>("Enter New Price: ");
			int newQty = safeInput<int>("Enter New Quantity: ");

			p->setName(newName);
			p->setPrice(newPrice);
			p->setQuantity(newQty);

			cout << "Product Updated Successfully\n";
			FileManager::rewriteProducts(techAisle, foodAisle, clothingAisle);
        }
		else if (choice == 13)
		{
			string id = safeInputString("Enter Product ID to Delete: ");

			techAisle.removeProduct(id);
			foodAisle.removeProduct(id);
			clothingAisle.removeProduct(id);

			cout << "Product Deleted Successfully (if existed)\n";
			FileManager::rewriteProducts(techAisle, foodAisle, clothingAisle);
        }
		else if (choice == 14) {
			FileManager::clearFile();
			setTextColor(2);
			cout << "Data Reset Successfully\n";
			setTextColor(7);
			techAisle.clearSection();
			foodAisle.clearSection();
			clothingAisle.clearSection();
		}

		else if (choice == 0) {
			techAisle.clearSection();
			foodAisle.clearSection();
			clothingAisle.clearSection();
			setTextColor(2);
			cout << "Exiting System...\n";
			setTextColor(7);
		}

		else {
			setTextColor(4);
			cout << "Invalid Choice\n";
			setTextColor(7);
		}

	} while (choice != 0);

	techAisle.clearSection();
	foodAisle.clearSection();
	clothingAisle.clearSection();

	////////////////////////////////// memory cleanup for products in aisles
	for (int i = 0; i < techAisle.getProductCount(); i++)
		delete techAisle.getProduct(i);

	for (int i = 0; i < foodAisle.getProductCount(); i++)
		delete foodAisle.getProduct(i);

	for (int i = 0; i < clothingAisle.getProductCount(); i++)
		delete clothingAisle.getProduct(i);
	return 0;
}
