#include <iostream>
#include "Product.h"
#include "Account.h"

void printMenu() {
	std::cout << "1) Add product\n";
	std::cout << "2) Delete product\n";

}

int main() {
	int option = 1;
	while (option > 0) {
		Account acc;
		printMenu();
		std::cout << "Enter option: ";
		std::cin >> option;
		if (option == 1) {
			std::cout << "Enter productId (universal number): ";
			int id;
			std::cin >> id;
			std::cout << "Enter name of product: ";
			std::string productName;
			std::cin >> productName;
			bool correctness = 1;
			Product* addingRoduct = new Product(id, productName, correctness);
			acc.addProduct(addingRoduct);
			acc.printAccount();

		}
	}

	return 0;
}