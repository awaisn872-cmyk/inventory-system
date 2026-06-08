#include "FileManager.h"
#include "GroceryProduct.h"
#include "FragileElectronics.h"
#include "PerishableGrocery.h"
#include "ClothingProduct.h"
#include "NonPerishable.h"
#include "Supplier.h"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

void setTextColor(int colorCode) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}


	void FileManager::saveProduct(Product* p) {
		ofstream file("products.txt", ios::app);
		if (!file) return;

		file << p->getProductID() << "|"
			<< p->getName() << "|"
			<< p->getPrice() << "|"
			<< p->getQuantity() << "|";

		if (auto ep = dynamic_cast<ElectronicProduct*>(p)) {
			file << "E|"
				<< ep->getVoltage() << "|"
				<< ep->getWarranty() << "|"
				<< ep->getBrandName();
		}
		else if (auto pg = dynamic_cast<PerishableGrocery*>(p))
		{
			file << "PG|"
				<< pg->getExpiryDate() << "|"
				<< pg->getStorageTemp() << "|"
				<< pg->getCurrentDate();
		}
		else if (auto np = dynamic_cast<NonPerishable*>(p))
		{
			file << "NG|"
				<< np->getShelfLifeYears() << "|"
				<< np->getPreservativeLevel();
		}
		else if (auto cp = dynamic_cast<ClothingProduct*>(p)) {
			file << "C|"
				<< cp->getsize() << "|"
				<< cp->getfabric() << "|"
				<< cp->getgender();
		}
		else {
			file << "B";
		}

		file << "\n";
		file.close();
	}

	void FileManager::loadProducts(InventorySection& tech, InventorySection& food, InventorySection& cloth) {
		ifstream file("products.txt");
		if (!file) return;

		string id, name, type, line;
		double price;
		int qty;



		while (getline(file, line)) {
			stringstream ss(line);

			getline(ss, id, '|');
			getline(ss, name, '|');

			string priceStr, qtyStr;
			getline(ss, priceStr, '|');
			getline(ss, qtyStr, '|');

			price = stod(priceStr);
			qty = stoi(qtyStr);

			getline(ss, type, '|');

			if (type == "E") {
				string voltageStr, warrantyStr, brand;

				getline(ss, voltageStr, '|');
				getline(ss, warrantyStr, '|');
				getline(ss, brand);

				Product* p = new FragileElectronics(
					id, name, price, qty,
					5, "Foam Box",
					stoi(warrantyStr),
					stod(voltageStr),
					brand.c_str()
				);

				tech.addStock(p);
			}
			else if (type == "PG")
			{
				string expiryDate;
				string storageTemp;
				string currentDate;

				getline(ss, expiryDate, '|');
				getline(ss, storageTemp, '|');
				getline(ss, currentDate);

				Product* p = new PerishableGrocery(
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

				food.addStock(p);
			}
			else if (type == "NG")
			{
				string shelfLifeYears;
				string preservativeLevel;

				getline(ss, shelfLifeYears, '|');
				getline(ss, preservativeLevel);

				Product* p = new NonPerishable(
					id,
					name,
					price,
					qty,
					100,
					true,
					"",
					"",
					"",
					stoi(shelfLifeYears),
					preservativeLevel
				);

				food.addStock(p);
			}
			else if (type == "C") {
				string sizeStr, fabricStr, genderStr;

				getline(ss, sizeStr, '|');
				getline(ss, fabricStr, '|');
				getline(ss, genderStr);

				Product* p = new ClothingProduct(id, name, price, qty, sizeStr, fabricStr, genderStr);

				cloth.addStock(p);
			}
		}

		file.close();

	}

	void FileManager::saveDiscountedProduct(Product* p, double originalPrice, double discountPercent) {
		ofstream file("discounts.txt", ios::app);
		if (!file) return;

		file << p->getProductID() << "|"
			<< p->getName() << "|"
			<< originalPrice << "|"
			<< p->getPrice() << "|"
			<< discountPercent << "\n";

		file.close();
	}

	void FileManager::displayDiscounts() {
		ifstream file2("discounts.txt");
		if (!file2) {
			setTextColor(4);
			cout << "No discounts found!\n";
			setTextColor(7);
			return;
		}

		string line;
		setTextColor(3);
		cout << "\n===== DISCOUNTED PRODUCTS =====\n";
		setTextColor(6);
		cout << "ID | Name | Original Price | Discounted Price | Discount %\n";
		cout << "-----------------------------------------------------------\n";
		setTextColor(7);

		while (getline(file2, line)) {
			stringstream ss(line);
			string id, name, originalStr, discountedStr, discountStr;

			getline(ss, id, '|');
			getline(ss, name, '|');
			getline(ss, originalStr, '|');
			getline(ss, discountedStr, '|');
			getline(ss, discountStr);

			cout << id << " | " << name << " | $" << originalStr
				<< " | $" << discountedStr << " | " << discountStr << "%\n";
		}

		file2.close();
	}
	void FileManager::showAllItemsFromFile(const string& filename) {
		ifstream file("products.txt");

		if (!file.is_open()) {
			cout << "\n Error: Could not open inventory file!\n";
			return;
		}
		string line;
		int count = 1;
		while (getline(file, line)) {
			if (!line.empty()) {
				cout << count << ". " << line << "\n";
				count++;
			}
		}

		if (count == 1) {
			cout << "--- No Products Available ---\n";
		}

		file.close(); 
	}
	// make save supplier function and load supplier function inwhich we will save the supplier details and product id which supplier supply in a file and load them when needed
	void FileManager::saveSupplier(const Supplier& supplier)
	{
		ofstream file("suppliers.txt", ios::app);

		if (!file)
			return;

		file << supplier.getSupplierID() << "|"
			<< supplier.getSupplierName() << "|"
			<< supplier.getContractTerms() << "|"
			<< supplier.getSuppliedProduct()
			<< "\n";

		file.close();
	}
	void FileManager::loadSuppliers(Supplier suppliers[], int& supplierCount)
	{
		ifstream file3("suppliers.txt");

		if (!file3)
			return;

		string line;

		while (getline(file3, line))
		{
			stringstream supplierStream(line);

			string idString;
			string supplierName;
			string contractTerms;
			string suppliedProduct;

			getline(supplierStream, idString, '|');
			getline(supplierStream, supplierName, '|');
			getline(supplierStream, contractTerms, '|');
			getline(supplierStream, suppliedProduct);

			Supplier supplier(
				stoi(idString),
				supplierName,
				contractTerms,
				suppliedProduct
			);

			suppliers[supplierCount++] = supplier;
		}

		file3.close();
	}
	void FileManager::showAllSuppliers()
	{
		ifstream file3("suppliers.txt");

		if (!file3)
		{
			cout << "No Supplier Record Found\n";
			return;
		}

		string line;

		cout << "\n===== SUPPLIERS =====\n";

		while (getline(file3, line))
		{
			cout << line << endl;
		}

		file3.close();
	}
    void FileManager::rewriteProducts(InventorySection& tech,
		InventorySection& food,
		InventorySection& cloth)
	{
		ofstream file("products.txt", ios::trunc);

		for (int i = 0; i < tech.getProductCount(); i++)
			saveProduct(tech.getProduct(i));

		for (int i = 0; i < food.getProductCount(); i++)
			saveProduct(food.getProduct(i));

		for (int i = 0; i < cloth.getProductCount(); i++)
			saveProduct(cloth.getProduct(i));
	}
	void FileManager::rewriteSuppliers(Supplier suppliers[], int supplierCount)
	{
		ofstream file("suppliers.txt", ios::trunc);

		for (int i = 0; i < supplierCount; i++)
		{
			file << suppliers[i].getSupplierID() << "|"
				<< suppliers[i].getSupplierName() << "|"
				<< suppliers[i].getContractTerms() << "|"
				<< suppliers[i].getSuppliedProduct()
				<< "\n";
		}

		file.close();
	}
	
	void FileManager::clearFile() {
		ofstream file("products.txt", ios::trunc);
		file.close();
		ofstream file2("discounts.txt", ios::trunc);
		file2.close();
		ofstream file3("suppliers.txt", ios::trunc);
		file3.close();

	}