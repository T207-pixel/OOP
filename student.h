#pragma once
#include <iostream>
#include <string>
#include <exception>
//#include <vector>
#include "vector.h"
using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
protected:
	string surname;//фамилия
	string initials;//инициалы студента
	string group;//индекс группы
	int cathedra_id;//номер профилирующей кафедры

public:
	virtual void print(){
		cout << "Surname: " << surname << endl;
		cout << "Initials: " << initials << endl;
		cout << "Group: " << group << endl;
		cout << "cathedra_id: " << cathedra_id << endl;
	}
	
	Student( string surname_c, string initials_c, string group_c, int cathedra_id_c){
		surname = surname_c;
		initials = initials_c;
		group = group_c;
		cathedra_id = cathedra_id_c;
	}

	virtual string get_surname(){
		return surname;
	}

	virtual string get_initials(){
		return initials;
	}

	virtual string get_group(){
		return group;
	}

	virtual int get_cathedra_id(){
		return cathedra_id;
	}

	virtual string get_type() {
		return "Basic student";
	}

	virtual string srt_group(string group_c) {
		group =group_c;
		return group;
	}
	/*
	virtual const int* get_marks() {
		return nullptr;
	}*/
	//перегруженный оператор вывода в поток вызывая метод print из студента
};

	template<typename T>
	int getValue(T& forRecord) {
		cin >> forRecord;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1000 - 7,'\n');
			return -1;
		}
	//	if (T == string) {
	//		if (!check_for_string(forRecord))
	//			return -1;
	//	}
		return 0;
	}

	template<typename T>
	T getValueLoop(const string& err_message, const string& err_message2) { // added err_message2
		T value;
		while (getValue<T>(value) != 0) {
			std::cout << err_message << std::endl;
			std::cout << err_message2 << std::endl;
		}
		return value;
	}

	bool check_for_string(string line) {
		auto it = std::find_if(line.begin(), line.end(), isdigit);
		if (it != line.end()){
			cout << "String contains digits\n";
			return false;
		}
		return true;
	}



#endif