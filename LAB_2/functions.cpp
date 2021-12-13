#include "functions.h"
#include <iostream>

Lemniscata::Lemniscata()
{
	m = 1;
	c = 1;
}

void Lemniscata::set_m(double l_m)
{
	m = l_m;
}

void Lemniscata::set_c(double c_m)
{
	c = c_m;
}

double Lemniscata::get_m()
{
	return m;
}

double Lemniscata::get_c()
{
	return c;
}

// (4)Вернуть площадь кривой
double Lemniscata::area()
{
	double res = 0;
	if (c > 2 * pow(m, 2))
	{
		cout << "Elliptical" << endl;
		res = ((double)PI / 2) * ((2 * pow(m, 2) + c) + (c - 2 * pow(m, 2)));
		return res;
	}
	else if (c < 2 * pow(m, 2))
	{
		cout << "Hyperbolic" << endl;
		double a2 = 2 * pow(m, 2) + c;
		double b2 = 2 * pow(m, 2) - c;
		double a1 = sqrt(2 * pow(m, 2) + c);
		double b1 = sqrt(2 * pow(m, 2) - c);
		res = ((double)(a2 - b2) / 2) * atan(((double)a1 / b1) + ((double)(a1 * b1) / 2));
		return res;
	}

}

// (3) Вернуть тип кривой
void Lemniscata::print_type(double fi)
{
	if (c > 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = c - 2 * pow(m, 2);
		cout << "Elliptical" << endl;
		cout << "Cartesian coordinates" << endl;
		cout << "(x^2 + y^2)^2 = " << a << "*x^2 + " << b << "*y^2" << endl;
		cout << "Polar coordinates" << endl;
		double p = (a * cos(fi) * cos(fi)) + (b * sin(fi) * sin(fi));
		cout << p << " = " << a << "*cos^2(" << fi << ")" << " + " << b << "*sin^2(" << fi << endl;
	}
	else if (c < 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = 2 * pow(m, 2) - c;
		cout << "Hyperbolic" << endl;
		cout << "Cartesian coordinates" << endl;
		cout << "(x^2 + y^2)^2 = " << a << "*x^2 - " << b << "*y^2" << endl;
		cout << "Polar coordinates" << endl;
		double p = (a * cos(fi) * cos(fi)) - (b * sin(fi) * sin(fi));
		cout << p << " = " << a << "*cos^2(" << fi << ")" << " - " << b << "*sin^2(" << fi <<")"<< endl;
	}
//	else if (c == 2 * pow(m, 2))
//	{
//		cout << "x^2 + y^2 + 2" << m << "x" << " = 0" << endl;
//	}
}

// (5) Вернуть коэффициенты уравнения кривой в полярных координатах
/*
void Lemniscata::koef()
{
	if (c > 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = c - 2 * pow(m, 2);
		cout << "a^2 = " << a << endl;
		cout << "b^2 = " << b << endl;
	}
	if (c < 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = 2 * pow(m, 2) - c;
		cout << "a^2 = " << a << endl;
		cout << "b^2 = " << b << endl;
	}
}
*/
double Lemniscata::koef1()
{
	if (c > 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		return a;
	}
	if (c < 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		return a;
	}
}

double Lemniscata::koef2()
{
	if (c > 2 * pow(m, 2))
	{
		double b = c - 2 * pow(m, 2);
		return b;
	}
	if (c < 2 * pow(m, 2))
	{
		double b = 2 * pow(m, 2) - c;
		return b;
	}
}
// (6) Вернуть расстояние до центра в полярной системе координат в зависимости от угла
double Lemniscata::dist(double fi)
{
	if (c > 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = c - 2 * pow(m, 2);
		double p = (a * cos(fi) * cos(fi)) + (b * sin(fi) * sin(fi));
		return p;
		//cout << "Dist = " << p << endl;
	}
	else if (c < 2 * pow(m, 2))
	{
		double a = 2 * pow(m, 2) + c;
		double b = 2 * pow(m, 2) - c;
		double p = (a * cos(fi) * cos(fi)) - (b * sin(fi) * sin(fi));
		return p;
		//cout << "Dist = " << p << endl;
	}
}
/*
	char* Lemniscata::formula()
	{
		const char* s1 = "y^2 = x^3/(2  - x)";
		int l = strlen(s1) + 1;
		char num[20];
		sprintf_s(num, 20, "%.2f", a);
		l += strlen(num) + 1;
		char* s = new char[l];
		sprintf_s(s, l, "y^2 = x^3/(2*%.2f - x)", a);
		return s;
	}
	*/
