#include "functionsInBlood.h"

void print_menu()
{
	cout << "0) Break\n";
	cout << "1) Get element by index in first array\n"; //[]
	cout << "2) Add second array to the end of first array\n"; //+=
	cout << "3) Summarize 1st and 2nd arrays\n";//+
	cout << "4) Highlight subsequence in firs array\n";//()
	cout << "5) Copy constructor check\n";
	cout << "6) Displacement equality check\n";
}

int main()
{
	int option = 0;
	do {
		print_menu();
		cout << "Enter option: ";
		cin >> option;
		switch (option)
		{
		case 1: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			cout << "You entered: ";
			cout << obj1;
			int index = 0;
			cout << "Entre index: ";
			cin >> index;
			cout << "Index = ";
			cout << obj1[index];
			cout << endl;
			break;
		}
		case 2: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			cout << "You entered: ";
			cout << obj1;
			Vector obj2;
			cout << "Enter second array\n";
			cin >> obj2;
			cout << "You entered: ";
			cout << obj2;
			obj1 += obj2; 
			cout << obj1;
		//	obj2.~Vector();
		//	delete &obj2;
			break;
		}
		case 3: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			cout << "You entered: ";
			cout << obj1;
			Vector obj2;
			cout << "Enter second array\n";
			cin >> obj2;
			cout << "You entered: ";
			cout << obj2;
			Vector obj_tmp;
			obj_tmp = obj1 + obj2;
			cout << obj_tmp;
			break;
		}
		case 4: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			cout << "You entered: ";
			cout << obj1;
			int index = 0;
			int quantity = 0;
			cout << "Enter index from whitch you would like to highlight: ";
			cin >> index;
			cout << "Enter quantity of elements to highlight: ";
			cin >> quantity;
			cout << obj1(index, quantity);
			break;
		}
		case 5: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			cout << "You entered: ";
			cout << obj1;
			Vector obj8(obj1);
			cout << obj8;
			break;
		}
		case 6: {
			Vector obj1;
			cout << "Enter first array\n";//>>
			cin >> obj1;
			Vector obj2;
			obj2 = move(obj1);
			cout << obj2;
			break;
		}
		}
	} while (option);
	return 0;
}

