#pragma once
#include "student.h"
#include "junior.h"
#include "senior_student.h"
#include "graduate.h"
#include "iomanip"

typedef struct Student_s {
	int code;
	Student* ptr;

	Student_s(int code_c, Student* obj_c) : code(code_c), ptr(obj_c) {}
	Student_s() = default;

	void print_struct() {
		cout <<"Code: "<< code<<"\n";
		ptr->print();
	}

	Student_s& operator=(const Student_s& right) {
		if (this == &right) {
			return *this;
		}
		this->ptr = right.ptr;
		this->code = right.code;
		return *this;
	}
}Student_t;

class Table {
private:
	Vector<Student_t> arr;//array for all students (stl vector)
public:
	Table() : arr() {}

	const Student_t& insert(const Student_t& element) {//можно создать ни как вектор, а как map (сортировку выполняет map)
		arr.push_back(element);
		bubble_sort1();
		return element;
	}

	void bubble_sort1() {
		for (int i = 0; i < arr.size() - 1; i++) {
			for (int j = (arr.size() - 1); j > i; j--) {
				if (arr[j - 1].code > arr[j].code) {
					Student* temp1 = nullptr;
					int temp = arr[j - 1].code;
					temp1 = arr[j - 1].ptr;
					arr[j - 1] = arr[j];
					arr[j - 1].ptr = arr[j].ptr;
					arr[j].code = temp;
					arr[j].ptr = temp1;
				}
			}
		}
	}

	void print_table() {
		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i].print_struct();
	}

	Student* get_info_with_code(int code) { 
		for (int i = 0; i < arr.size(); i++) {
			if (code == arr[i].code) {
				return arr[i].ptr;
			}
		}
	}

	~Table() {
		for (unsigned int i = 0; i < arr.size(); i++) {
			delete arr[i].ptr;
		}
	}

	void delete_with_code(int code) { 
		for (int i = 0; i < arr.size(); i++) {
			if (code == arr[i].code)
				arr.erase(i);
		}
	}

	const int* get_marks(int code) {
		Student* buf = get_info_with_code(code);
		string type = buf->get_type();
		if (type == "Junior student") {
			return dynamic_cast<Junior*>(buf)->get_marks_J();
		}
		else if (type == "Senior student") {
			return dynamic_cast<Senior_student*>(buf)->get_marks_Sen();
		}
		else {
			return nullptr;
		}
	}

	string get_topic_p(int code) {
		Student* buf = get_info_with_code(code);
		string type = buf->get_type();
		if (type == "Senior student") {
			return dynamic_cast<Senior_student*>(buf)->get_topic_p();
		}
		else if (type == "Graduate student") {
			return dynamic_cast<Graduate*>(buf)->get_topic_p();
		}
		else
			return string();
	}

	string set_topic(int code, string line) {
		Student* buf = get_info_with_code(code);
		string type = buf->get_type();
		if (type == "Senior student") {
			return dynamic_cast<Senior_student*>(buf)->set_topic(line);
		}
		else if (type == "Graduate student") {
			return dynamic_cast<Graduate*>(buf)->set_topic(line);
		}
		else
			return "";
	}

	const string get_place_p(int code) {
		Student* buf = get_info_with_code(code);
		string type = buf->get_type();
		if (type == "Senior student") {
			return dynamic_cast<Senior_student*>(buf)->get_place();
		}
		else if (type == "Graduate student") {
			return dynamic_cast<Graduate*>(buf)->get_place();
		}
		else
			return "";
	}

	string set_place_p(int code, string line) {
		Student* buf = get_info_with_code(code);
		string type = buf->get_type();
		if (type == "Senior student") {
			return dynamic_cast<Senior_student*>(buf)->set_place(line);
		}
		else if (type == "Graduate student") {
			return dynamic_cast<Graduate*>(buf)->set_place(line);
		}
		else
			return "";
	}

	bool check_finder(int code) {
		for (int i = 0; i < arr.size(); i++) {
			if (code == arr[i].code)
				return true;
		}
		return false;	
	}

	void load_in_file_append() {
		ofstream fout1;
		fout1.open("outfile.csv", ios::app);
		for (int i = 0; i < arr.size(); i++) {
			Student* tmp_student = arr[i].ptr;
			tmp_student->print_in_file(fout1);
		}
		fout1.close();
	}

	void load_in_file_new() {
		ofstream fout1;
		fout1.open("outfile.csv", ios::out);
	//	print_file_string(fout1);
		for (int i = 0; i < arr.size(); i++) {
			Student* tmp_student = arr[i].ptr;
			tmp_student->print_in_file(fout1);
		}
		fout1.close();
	}

	void print_file_string(ofstream& fout) {
		fout << " Surname ;";
		fout << " Initials ;";
		fout << " Group ";
		fout << " Cathedra_id ;";
		fout << " Type ;";
		fout << " Marks ;";
		fout << " Topic ssp ;";
		fout << " Place ;";
		fout << " Supervisor mark ;";
		fout << " Comissen mark ;";
		fout << " Diplom project topic ;";
		fout << " Place ;";
		fout << " Reviewer mark ;";
		fout << " Gec mark ;";
		fout << "\n";
	}

};


