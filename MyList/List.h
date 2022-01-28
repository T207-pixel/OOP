#pragma once
#include <iostream>

typedef struct sNode {
	struct sNode* next;
	int number;
}Node;

class List {
private:
	Node *head;
	//size
public:
	List();
	List(int first);
	List(const List& other);//coping constructor
	List(List&& other);//removeable constructor
	Node* creatNode();
	void adding(int number);
	void print();
	void insert(int position, int number);
	void deleteByKey(int keyD);
	friend std::istream& operator >> (std::istream& in, List& node);
	friend std::ostream& operator << (std::ostream & out,  List & node); //было const
	List& operator +=(int number);//add element in the end 
	List& operator -=(int number);//add element to the beginning
	//{} сделать инициализацию как unit8 у вектора
	
	
};
