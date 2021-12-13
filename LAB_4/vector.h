#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <class T> class Vector
{
private:
	T* arr;
	int _size;
public:
	Vector() {
		_size = 0;
		arr = nullptr;
	}

	~Vector() {
		delete[] arr;
	}

	Vector(const Vector& other) {
		_size = other._size;
		arr = new T[_size];
		for (int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}

	void resize(int new_size) {
		T* buf = nullptr;
		int tmp = _size;
		int delta = new_size - _size;
		_size += delta;
		buf = new T[_size];
		memcpy(buf, arr, tmp * sizeof(T));	
		delete[] arr;
		arr = buf;
	}

	void erase(int index) {
			for (index; index < _size - 1; index++)
				arr[index] = arr[index + 1];
			_size--;
			T* buf = nullptr;
			buf = new T[_size];
			memcpy(buf, arr, _size * sizeof(T));
			delete[] arr;
			arr = buf;
		}

	Vector& operator=(Vector&& right) noexcept {
		if (this == &right) {
			return *this;
		}
		delete[] this->arr;
		_size = right._size;
		int* ptr = this->arr;
		arr = right.arr;
		right.arr = ptr;
		return*this;
	}

	const T& operator[](int index) const { //коректность задания индекса проверяет метод add можно исправить в приклодной программе можно юзать try
		if (index < 0 || index >= _size)
			throw exception("Out of range!\n");
		return arr[index];
	}

	T& operator[](int index) {
		if (index < 0 || index >= _size)
			throw exception("Out of range!\n");
		return arr[index];
	}

	void push_back(const T& value) {
		int n_size = _size + 1;
		resize(n_size);
		arr[_size - 1] = value;
	}

	void set_size(int m_size) {
		_size = m_size;
	}

	int size() {
		return _size;
	}

};


//	для шаблона
// arr.push_back(element)//done 
// arr.size()//DONE
// arr.erase() //done
// перегрузка индексирования для r-value и l-value//DONE
