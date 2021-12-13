#include "Prog.h"
#include <iostream>
using namespace std;

int main()
{
	Line* arr = nullptr; // array for number of rows
	int m;
	std::cout << "Enter quantity of rows #" << std::endl;
	getValue(m);
	arr = input(m);
	output("Entered matrix", arr, m);
	solve(arr, m);
	output("Sourced matrix", arr, m);
	return 0;
}

