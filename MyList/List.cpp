#pragma once
#include "List.h"

List::List() {
	head = new Node;
	head->number = 1;
	head->next = nullptr;
}

List::List(int first) {
	head = new Node;
	head->number = first;
	head->next = nullptr;
}

List::List(const List& other) { //other is from where we are coping!!!//coping constructor
	this->head = creatNode();
	this->head->number = other.head->number;
	Node* tmp = this->head;
	Node* tmp1 = other.head;
	while (tmp1 != nullptr) {
		Node* insCopy = creatNode();
		if (tmp1->number == other.head->number) {
			tmp1 = tmp1->next;
			continue;
		}
		insCopy->number = tmp1->number;
		insCopy->next = nullptr;
		tmp->next = insCopy;
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
}

List::List(List&& other) {

}

List& List::operator +=(int number) { //можно ли юзануть const проверить
	
	Node* tmp = this->head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	Node* insNode = new Node;
	insNode->number = number;
	insNode->next = nullptr;
	tmp->next = insNode;
	return *this;
}

List& List::operator -=(int number) {//можно свопнуть значения а можно старую голову двинуть влево и свопнуть значения
	Node* insNode = new Node;
	insNode->number = this->head->number;
	this->head->number = number;
	Node* tmp2 = this->head->next;
	Node* tmp1 = this->head;
	this->head->next = insNode;
	insNode->next = tmp2;
	return *this;
}


std::istream& operator >> (std::istream& in, List& node) { //нужно переписать более красиво
	std::cout << "Entet value -1 if you want to stop entering list\n";
	Node* tmp = node.head;
	int counter = 1;
	while (counter >= 0) {
		if (tmp == node.head) {
			std::cout << "Enter root number(1): ";
			in >> tmp->number;	
			Node* secNode = new Node;
			secNode->next = nullptr;
			secNode->number = 1;
			tmp->next = secNode;
			tmp = tmp->next;
			counter++;
		}
		else {
			std::cout << "Enter value of node(" << counter << "): ";
			in >> tmp->number;
			if (tmp->number < 0) {
				tmp->number = -10;
				node.deleteByKey(tmp->number);
				break;
			}
			else {	
				tmp->next = nullptr;
				Node* secNode = new Node;
				secNode->next = nullptr;
				secNode->number = 0;
				tmp->next = secNode;
				tmp = tmp->next;
				counter++;
			}
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, List& node) {
	Node* tmp = node.head;
	out << "List: ";
	while (tmp != nullptr){
		out << tmp->number;
		std::cout << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
	return out;
}



//removeable constructor ?

Node* List::creatNode() {
	Node* ins = new Node;
	ins->next = nullptr;
	ins->number = 0;
	return ins;
}

void List::adding(int number) {
	Node* ins = creatNode();
	Node* tmp = head;
	ins->next = nullptr;
	ins->number = number;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = ins;
}


void List::print() {
	Node* tmp = head;
	while (tmp != nullptr){
		std::cout << tmp->number<<" ";
		tmp = tmp->next;
	}
	std::cout << "\n";
}

void List::insert(int position, int number) {
	Node* tmp = head;
	Node* ins = creatNode();
	ins->number = number;
	while (tmp != nullptr) {
		if (tmp->number == position) {
			Node* tmp1 = tmp->next;
			tmp->next = ins; 
			ins->next = tmp1; 
			break;
		}
		else {
			tmp = tmp->next;
		}
	}
}

void List::deleteByKey(int keyD) {
	Node* tmp = head;
	if (head->number == keyD) {
		head = tmp->next;
		delete tmp;
	}
	else {
		while (tmp != nullptr) { 
			if (tmp->next->number == keyD) {
				Node* del = tmp->next;
				tmp->next = tmp->next->next;
				delete del;
				break;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}
