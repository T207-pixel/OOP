#pragma once
#include "student.h"

class Graduate : public Student {
private:	
	string topic_dp;//направление темы ДП (дипломного проекта)
	string place;//место выполнения
	int supervisor_mark;//оценка руководителя
	int reviewer_mark;//оценка комиссии
	int gec_mark;//государственной экзаменационной комиссии
public:
	Graduate(string surname_c, string initials_c, string group_c, int cathedra_id_c, string topic_dp_c, string place_c, int supervisor_mark_c, int reviewer_mark_c, int gec_mark_c)
		: Student(surname_c, initials_c, group_c, cathedra_id_c){
		topic_dp = topic_dp_c;
		place = place_c;
		supervisor_mark = supervisor_mark_c;
		reviewer_mark = reviewer_mark_c;
		gec_mark = gec_mark_c;
	}
	
	void print() override {
		Student::print();
		cout << "Diplom project topic: "<< topic_dp<<endl;
		cout << "Place: " << place<<endl;
		cout << "Supervisor mark: " << supervisor_mark<<endl;
		cout << "Reviewer mark: " << reviewer_mark<<endl;
		cout << "Gec mark: " << gec_mark<<endl;
	}

	void print_in_file(ofstream& fout) override {
		fout << "Studen type: ;Graduate student;-;-\n";
		Student::print_in_file(fout);
		fout << "Diplom project topic: ;" << topic_dp << endl;
		fout << "Place: ;" << place << endl;
		fout << "Supervisor mark: ;" << supervisor_mark << endl;
		fout << "Reviewer mark: ;" << reviewer_mark << endl;
		fout << "Gec mark: ;" << gec_mark << endl;
		fout << "\n";
	}
	
	string get_type() override{
		return "Graduate student";
	}

	string srt_group(string group_c) override {
		group = group_c;
		return group;
	}

	const string get_topic_p() { 
		return topic_dp;
	}

	string set_topic(string topic_dp_c) {
		topic_dp = topic_dp_c;
		return topic_dp;
	}

	const string get_place() {
		return place;
	}

	string set_place(string place_c) {
		place = place_c;
		return place;
	}
};