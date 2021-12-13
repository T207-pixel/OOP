//если несколько макс элементов то менять местами все мкс1 мкс2
// 2 2 2 3 3
// 3 3 2 2 2
#include "Prog.h"
#include <iostream>
using namespace std;

template<typename T>
 T getValue(T &forRecord) {
	std::cin >> forRecord;
	if (!std::cin.good()) { return 1; }
	return -1;

}

double* getMaxElement(Line* a)
{
	int counter = 0;
	double* res = a->a;
	for (int i = 0; i < a->n; i++) {
		if (*res < a->a[i])
		{ res = a->a + i; }
		//if (*res == a->a[i])
		//{counter++;}
		std::cout << counter << std::endl;
	}
	return res;
}



double* getMinElement(Line* a)
{
	double* res = a->a;
	for (int i = 0; i < a->n; i++) {
		if (*res > a->a[i])
		{ res = a->a + i; }
	}
	return res;
}

void swap(double& max, double& min) {
	double tmp = max;
	max = min;
	min = tmp;
}

void solve(Line* a, int m)
{
	for (int i = 0; i < m; i++) {
		double* max = getMaxElement(a + i);
		double* min = getMinElement(a + i);
		swap(*max, *min);
	}
}

Line* input(int m)
{
	double* buf = nullptr;


	Line* lines = nullptr;
	lines = new Line[m]; //allocateing memory for quantity of rows
	for (int i = 0; i < m; i++) { //filling rows with quantity of elements in it
		std::cout << "Enter number of items in line '-1' #" << (i + 1) << " --> ";
		int n_max;
		getValue(n_max);
		//getNum_int(n_max);

		buf = new double[n_max];
		for (int j = 0; j < n_max; j++)
		{
			buf[j] = 0; //filling all elements in array with zeros
		}
		int index = 0;

		//ONE more array for saveing indexes
		int* remainder = nullptr;
		remainder = new int[n_max];
		for (int j = 0; j < n_max; j++)
		{
			remainder[j] = 0;
		}
		//DONE

		double value = 0;
		int counter = 0;
		while (index != -1)
		{
			std::cout << "Enter index[] and value" << std::endl;
			std::cout << "If you want to stop filling array press -1" << std::endl;
			std::cin >> index;
			if (index == -1)
				break;
			//NEW
			remainder[index] = index;
			//DONE
			std::cin >> value;
			buf[index] = value;
			counter++;
		}
		lines[i].a = new double[counter];
		lines[i].index_arr = new int[counter];//NEW
		int used = 0;
		lines[i].n = counter;
		for (int k = 0; k < n_max; k++)
		{
			if (buf[k] != 0)
			{
			//	lines[i].a.index = k;

				lines[i].a[used] = buf[k];
				lines[i].index_arr[used] = k;
				used++;
			}
		}
		delete[] buf;
		delete[] remainder;
	}
	return lines;
}

void output(const char* msg, Line* a, int m)
{
	int i, j;
	std::cout << msg << ":\n";
	for (i = 0; i < m; ++i) {
		for (j = 0; j < a[i].n; ++j)
		{
				std::cout << " index[" << a[i].index_arr[j] << "]_" << a[i].a[j] << " ";
		}
		std::cout << std::endl;
	}
}

Line* erase(Line*& lines, int m)
{
	int i;
	for (i = 0; i < m; i++)
		delete[] lines[i].a;
	delete[] lines;
	return nullptr;
}
