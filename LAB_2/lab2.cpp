//5) The Booth lemniscate equations in the polar coordinate system as a string (7)
// enter m & n
//sm testing
// add 5) The Booth lemniscate equations in the polar coordinate system as a string\n
#include "functions.h"
int main()
{
	Lemniscata obj;
	char* line = nullptr;
//	while (1)
//	{
		cout << "Lemniscata: " << endl;
//		line = obj.formula();
//		cout << line <<endl;
		int option = 0;
		double fi = 0;
		double area = 0;
		double dist = 0;
		double koef1 = 0;
		double koef2 = 0;
		double m;
		double n;
		cout << "Enter angle" << endl;
		cin >> fi;
		cout << "Enter m and n" << endl;
		cin >> m;
		obj.set_m(m);
		cin >> n;
		obj.set_c(n);
		while (1)
		{
			cout << "Choose option:\n1) Print all types of curve\n2) Area of curve\n3) Coefficients of the equation of the curve in polar coordinates" << endl;
			cout << "4) Distance to center in polar coordinate system as a function of angle\n5)Stop" << endl;
			cin >> option;
			if (option == 1)
			{
				obj.print_type(fi);
				cout << endl;
			}
			else if (option == 2)
			{
				area = obj.area();
				cout << "Area = " << area << endl;
				cout << endl;
			}
			else if (option == 3)
			{
			//	obj.koef();
			//	cout << endl;
				koef1 = obj.koef1();
				cout << "a^2 = " << koef1 << endl;
				koef2 = obj.koef2();
				cout << "b^2 = " << koef2 << endl;
			}
			else if (option == 4)
			{
				dist = obj.dist(fi);
				cout << "Dist = " << dist << endl;
				cout << endl;
			}
			else if (option == 5)
			{
				break;
			}
		}
//	}
}