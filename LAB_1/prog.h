#pragma once

#include <iostream>
using namespace std;

struct Line {
	int n; // quantity of elements in one row
	double *a; // array of elements
	int* index_arr; // array of indexes
};

template<typename T> T getValue(T &forRecord);
int getNum_double(double& a);
int getNum_int(int& a);
double* getMaxElement(Line* a);
double* getMinElement(Line* a);
void solve(Line* a, int m);
Line* input(int m);
void output(const char* msg, Line* a, int m);
Line* erase(Line*& lines, int m);
