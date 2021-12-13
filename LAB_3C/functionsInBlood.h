#pragma once
#include <iostream>
#include <exception>
#include <utility>
#include <string>
using namespace std;

#ifndef _FUNCTIONSINBLOOD_H_
#define _FUNCTIONSINBLOOD_H_

class Vector {
private:
	int size;
	int* arr; //dynamic 
//	int vectorID;
	int error = -101;
public:
	Vector();
	~Vector();
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept; 
	Vector& operator=(Vector&& right) noexcept;
	void set_size(int m_size);
	int get_size();
	void resize(int new_size);
	friend std::istream& operator >> (std::istream& in, Vector& a);
	friend std::ostream& operator << (std::ostream& out, const Vector& a);
	int operator[](int index) const;
	int& operator[](int index);
	Vector& operator=(const Vector& right);
	Vector& operator +=(const Vector& other);
	Vector& operator +(const Vector& right);
	Vector operator ()(int index, int quantity);
};

#endif