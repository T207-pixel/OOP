#pragma once
#include "List.h"
void menu() {
	std::cout << "1) Add to the end\n";
	std::cout << "3) Insert element in certain place\n";
	std::cout << "4) Delete certain element\n";
	std::cout << "5) Copy list in another list\n";//checking copy constructor
	std::cout << "6) Enter object(overload)\n";
	std::cout << "7) Add element to the end(overload)\n";
	std::cout << "8) Add element to the beginning(overload)\n";
}

int main()
{
	int option = -1;
	std::cout << "Enter number of the first element: ";
	int a = 0;
	std::cin >> a;
	List obj(a);
	while (option != 0) {
		menu();
		std::cout << "Enter option: ";
		std::cin >> option;
		if (option == 1) {
			List obj;
			std::cin >> obj;
			std::cout << "Enter number: ";
			int number = 0;
			std::cin >> number;
			obj.adding(number);
			obj.print();
		}
		else if (option == 3) {
			std::cout << "Enter after which element you would like to insert element: ";
			int position = 0;
			std::cin >> position;
			std::cout << "Enter number which you would like to enter: ";
			int number = 0;
			std::cin >> number;
			obj.insert(position, number);
		}
		else if (option == 4) {
			std::cout << "Enter number of node for deleting: ";
			int del_node = -1;
			std::cin >> del_node;
			obj.deleteByKey(del_node);
		}
		else if (option == 5) {
			List objC(obj);
			objC.print();
		}
		else if (option == 6) {
			List objEnter;
			std::cin >> objEnter;
			std::cout << objEnter;
		}
		else if (option == 7) {
			List obj1;
			std::cin >> obj1;
			int number = 0;
			std::cout << "Enter element which you wold like add to the end: ";
			std::cin >> number;
			obj1 += number;
			std::cout << obj1;
		}
		else if (option == 8) {
			List obj;
			std::cin >> obj;
			int number = 0;
			std::cout << "Enter element which you wold like add to the beginning: ";
			std::cin >> number;
			obj -= number;
			std::cout << obj;
		}
	}
	return 0;
}

