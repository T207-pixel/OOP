#pragma once
#include "student.h"

class Junior : public Student {
private:
	int marks[5];//оценки за прошедшую сессию (max 5 оценок)
public:
	 void print() override{
		Student::print();
		for (int i = 0; i < 5; i++)
			cout << "[" << i+1 << "]: " << marks[i] << endl;
	}

	 void print_in_file(ofstream& fout) override {
		 fout << "Type: ;Junior student\n";
		Student::print_in_file(fout);
		for (int i = 0; i < 5; i++)
			fout << "[" << i + 1 << "]: ;" << marks[i] << endl;
		fout << "\n";
	 }
	
	Junior(string surname_c, string initials_c, string group_c, int cathedra_id_c, int marks_c[5]) :
		Student(surname_c, initials_c, group_c, cathedra_id_c) {
		for (int i = 0; i < 5; i++) 
			marks[i] = marks_c[i];
	}
	
	string get_type() override {
		return "Junior student";
	}

	const int* get_marks_J() {
		return marks;
	}

	string srt_group(string group_c) override{
		group = group_c;
		return group;
	}


};
	
