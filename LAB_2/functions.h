#pragma once
#include <iostream>
#include <math.h>
#include <cmath>
#include <string.h>
#define PI  3.141592653589793
using namespace std;

#ifndef _LEMNISCATA_H_
#define _LEMNISCATA_H_

// (1) Определить состояние класса
class Lemniscata {
	private:
		double m;
		double c;
	public:
		Lemniscata();
		void set_m(double l_m);
		void set_c(double c_m);
		double get_m();
		double get_c();
		double area();
		void print_type(double fi);
		void koef();
		double koef1();
		double koef2();
		double dist(double fi);
//		char* formula();
};

#endif

