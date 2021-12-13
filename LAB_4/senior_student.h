#pragma once
#include "student.h"

class Senior_student : public Student {
private:	
	int marks[4];//оценки за прошедшую сессию (максимум 4 числа)
	string topic_ssp;//направление темы УИР 
	string place;//место выполнения
	int supervisor_mark;//оценка руководителя
	int comissen_mark;//оценка комиссии сделать инт
public:
	Senior_student(string surname_c, string initials_c, string group_c, int cathedra_id_c, int marks_c[4], string topic_ssp_c, string place_c, int supervisor_mark_c, int comissen_mark_c)
		: Student(surname_c, initials_c, group_c, cathedra_id_c) {
		for (int i = 0; i < 4; i++) 
			marks[i] = marks_c[i];
		topic_ssp = topic_ssp_c;
		place = place_c;
		supervisor_mark = supervisor_mark_c;
		comissen_mark = comissen_mark_c;
	}
	
	void print() override{
		Student::print();
		for (int i = 0; i < 4; i++)
			cout << "[" << i + 1 << "]: " << marks[i] << endl;
		cout << "Topic ssp: " << topic_ssp << endl;
		cout << "Place: " << place << endl;
	}
	
	void print_in_file(ofstream& fout) override {
		fout << "Studen type: ;Senior student\n";
		Student::print_in_file(fout);
		for (int i = 0; i < 4; i++)
			fout << "[" << i + 1 << "]: ;" << marks[i] << endl;
		fout << "Topic ssp: ;" << topic_ssp << endl;
		fout << "Place: ;" << place << endl;
		fout << "Supervisor mark;" << supervisor_mark << endl;
		fout << "comissen mark;" << comissen_mark << endl;
		fout << "\n";
	}
	
	string get_type() override{
		return "Senior student";
	}

	const int* get_marks_Sen() {
		return marks;
	}

	string srt_group(string group_c) override {
		group = group_c;
		return group;
	}

	const string get_topic_p() { 
		return topic_ssp;
	}

	string set_topic(string topic_ssp_c) {
		topic_ssp = topic_ssp_c;
		return topic_ssp;
	}

	const string get_place() {
		return place;
	}

	string set_place(string place_c) {
		place = place_c;
		return place;
	}
};


