#pragma
#include "functionsInBlood.h"

Vector::Vector() {
//	vectorID = ID;
	size = 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
//	cout << "Constructor #" << vectorID << endl;
}

//SECOND VERSION
/*
Vector::Vector(int ID) : vectorID(ID), size(1) { //как тут списком массив проинициализировать
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	cout << "Constructor #" << vectorID << endl;
}
*/
Vector::~Vector() {
	delete[] arr;
//	cout<< vectorID << " Worked destructor\n";
}

Vector::Vector(const Vector& other){
//	vectorID = other.vectorID;
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

Vector::Vector(Vector&& other) noexcept { 
//	vectorID = other.vectorID;
//	other.vectorID = 0;
	size = other.size;
	other.size = 0;
	arr = other.arr;
	other.arr = nullptr;
}

Vector& Vector::operator=(Vector&& right) noexcept {
	if (this == &right) {
		return *this;
	}
	delete[] this->arr;
	size = right.size;
	int* ptr = this->arr;
	arr = right.arr;
	right.arr = ptr;
	return*this;
}



void Vector::set_size(int m_size){
	size = m_size;
}

int Vector::get_size(){
	return size;
}

void Vector::resize(int new_size){ 
	int* buf = nullptr;
	int tmp = size;
	int delta = new_size - size;
	size += delta;
	buf = new int[size];
	memcpy(buf, arr, tmp * sizeof(int));
//for (int i = 0; i < tmp; i++) buf[i] = arr[i];
	for (tmp; tmp < size; tmp++)
		buf[tmp] = 0;
	delete[] arr;
	arr = buf;
}

std::istream& operator >> (std::istream& in, Vector& a){
	int value = 0;
	int tmp = a.size;
	cout << "Enter size: ";
	cin >> value; 
	if (a.size < value)
		a.resize(value);
for (int i = 0; i < a.size; i++){
		cout << "arr[" << i << "]: ";
		in >> a.arr[i];
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Vector& a){
	out << "Vector: ";
	for (int i = 0; i < a.size; i++) out << a.arr[i] << " ";
	out << std::endl;
	return out;
}

int Vector::operator[](int index) const{ 
	try {
		if (index < 0 || index > size)
			throw - 1;
		return arr[index];
	}
	catch (int a) {
		std::cerr << "We caught an int exception with value: " << a << '\n';
		return -100;
	}
}

int& Vector::operator[](int index){
	try {
		if (index < 0 || index > size)
			throw - 2;
		return arr[index];
	}
	catch (int a) {
		std::cerr << "We caught an int exception with value: " << a << '\n';
		return error;
	}
}

Vector& Vector::operator=(const Vector& right){ 
	if (this == &right) {
		return *this;
	}
	if (size < right.size){
		delete[] this->arr;
		this->arr = new int[right.size];
	}
	size = right.size;
	for (int i = 0; i < size; i++)  
		this->arr[i] = right.arr[i];
	return* this;
}

Vector& Vector::operator +=(const Vector & other) {
	int tmp = size;
	int new_s = this->size + other.size;
	this->resize(new_s);
	int i = 0;
	for (tmp; tmp < size; tmp++) {
		this->arr[tmp] = other.arr[i];
		i++;
	}
	return *this;
}

Vector& Vector::operator +(const Vector& other) {
	Vector* tmp = new Vector; 
	if (this->size < other.size) {
		tmp->resize(other.size);
		tmp->arr[0] = 0;
		for (int i = 0; i < this->size; i++)
			tmp->arr[i] = other.arr[i] + this->arr[i];
		for (int j = this->size; j < other.size; j++)
			tmp->arr[j] = other.arr[j];
	}
	else if (this->size > other.size) {
		tmp->resize(this->size);
		tmp->arr[0] = 0;
		for (int i = 0; i < other.size; i++)
			tmp->arr[i] = this->arr[i] + other.arr[i];
		for (int j = other.size; j < this->size; j++)
			tmp->arr[j] = this->arr[j];
	}
	else {
		tmp->resize(this->size);
		tmp->arr[0] = 0;
		for (int i = 0; i < other.size; i++)
			tmp->arr[i] = this->arr[i] + other.arr[i];
	}
	delete tmp;
	return *tmp;
}

Vector Vector::operator ()(int index, int quantity) {//можно просто выделить концовку 
	Vector tmp;
	try {
		if (index < 0 || index > size || (index + quantity) > size)
			throw - 3;
		tmp.resize(quantity);
	for (int i = 0; i < quantity; i++){
		tmp.arr[i] = this->arr[index];
		index++;
	}
	return tmp;
	}
	catch (int a) {
		std::cerr << "We caught an int exception with value: " << a << '\n'; //тут прога вылетает
		return tmp;
	//	return -102;
	}
}

//Vector& Vector::operator +(const Vector& other){ //переписать как в () то есть создать obj tmp и в него записывать результат
//	Vector tmp(67);
//	const Vector* p;
//	if (this->size > other.size) {
//		tmp = *this;
//		p = &other;
//	}
//	else{
//		tmp = other;
//		p = this;
//	}
//		for (int i = 0; i < p->size; i++){
//			this->arr[i] = this->arr[i] + p->arr[i];
//		delete[] other.arr;
//	}
//	if (this->size < other.size){
//		tmp->resize(this->size);
//		this->resize(other.size);
//		for (int i = 0; i < other.size; i++)
//			this->arr[i] += other.arr[i];
//		delete[] other.arr;
//	}
//	else{
//		for (int i = 0; i < other.size; i++)
//			this->arr[i] += other.arr[i];
//		delete[] other.arr;
//	}
//	return *this;
//}

