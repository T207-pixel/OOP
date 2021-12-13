#include "student.h"
#include "table.h"
#include "junior.h"
#include "senior_student.h"
#include "graduate.h"
#include <fstream>

int dialog(const char** msgs, int rc) {//for searching mistakes in input
	int choice = -1;
	while (1)
	{
		for (int i = 0; i < rc; i++) std::cout << msgs[i] << std::endl;
		std::cout << "Enter your choice --> ";
		choice = getValueLoop<int>("Entered not int", "Enter your choice --> ");
		if (choice >= 0 && choice < rc) break;
		if (!std::cin.good()) {
			throw std::exception("Error! Incorrect input\n");
		}
		throw std::exception("Error! This option does not exist\n");
	}
	return choice;
}

int main() {
	cout << " ---------------------------------------------------------------\n";
	cout << "|\t\t\t   STUDENT LIST   \t\t\t|\n";
	cout << "|\t\tGET ANY INFO ABOUT STUDENT HERE!\t\t|\n";
	cout << " ---------------------------------------------------------------\n\n";
	Table table;	
	const char* msgs1[] = {
	"[0]: Quit",
	"[1]: Add new student", 
	"[2]: Get info with code",
	"[3]: Delete with code",
	"[4]: Get category of the student",
	"[5]: Get students marks",
	"[6]: Change student group",
	"[7]: Change students rang",
	"[8]: Get topic of scientific project",
	"[9]: Get place of scientific project",
	"[10]: Show info",
	"[11]: Load in file"
	};
	int option = -1;
	while (option != 0) {
		try {
			option = dialog(msgs1, 12);
		}
		catch (const exception& exc) {
			cerr << exc.what();
		}
		if (option == 1) {
			int option_tmp1 = -1;
			while (option_tmp1 != 0){
			cout << "Enter which categoery of studen you would like to enter\n";
			const char* msgs2[] = {
				"[0]: Junior",
				"[1]: Senior student",
				"[2]: Graduate"
				};
			try {
				option_tmp1 = dialog(msgs2, 3);
			}
			catch (const exception& exc) {
				cerr << exc.what();
			}
			if (option_tmp1 == 0) {
				string surname;
				while (true) {
					cout << "Enter surname: ";
					cin >> surname;
					if (check_for_string(surname))
						break;
				}
				cout << "Enter code: ";
				int code = -1; 
				code = getValueLoop<int>("Entered not int", "Enter code: ");
				string initials;
			while (true) {
					cout << "Enter initials: ";
					cin >> initials;
					if (check_for_string(initials))
						break;
				}                                                                                                         
				cout << "Enter group: ";
				string group;
				cin >> group;
				cout << "Enter cafedra id: ";
				int cathedra_id = -1;
				cathedra_id = getValueLoop<int>("Entered not int", "Enter group: ");
				cout << "Enter no more than five marks\n";
				int mark[5] = { 0 };
				for (int i = 0; i < 5; i++) {
					cout << "[" << i + 1 << "]: ";
					mark[i] = -10;//смотрится колхозно как-то лучше сделать красиво
					while (mark[i] < 0 || mark[i] > 5){
					cin >> mark[i];
					if (mark[i] < 0 || mark[i] > 5)
						cout << "Enter possible mark [" << i + 1 << "]: ";
					}
				}
				Student* adding_student = new Junior(surname, initials, group, cathedra_id, mark);
				Student_t obj(code, adding_student);
				table.insert(obj);
				break;
			}
			else if (option_tmp1 == 1) {
				string surname;
				while (true) {
					cout << "Enter surname: ";
					cin >> surname;
					if (check_for_string(surname))
						break;
				}
				cout << "Enter code: ";
				int code = -1;
				code = getValueLoop<int>("Entered not int", "Enter code: ");
				string initials;
				while (true) {
					cout << "Enter initials: ";
					cin >> initials;
					if (check_for_string(initials))
						break;
				}
				cout << "Enter group: ";
				string group;
				cin >> group;
				cout << "Enter cafedra id: ";
				int cathedra_id = -1;
				cathedra_id = getValueLoop<int>("Entered not int", "Enter cafedra id: ");
				cout << "Enter no more than four marks\n";
				int mark[4] = { 0 };
				for (int i = 0; i < 4; i++) {
					cout << "[" << i + 1 << "]: ";
					mark[i] = -10;
					while (mark[i] < 0 || mark[i] > 5) {
						cin >> mark[i];
						if (mark[i] < 0 || mark[i] > 5)
							cout << "Enter possible mark [" << i + 1 << "]: ";
					}	
				}
				string topic_ssp;
				while (true) {
					cout << "Enter topic_ssp: ";
					cin >> topic_ssp;
					if (check_for_string(topic_ssp))
						break;
				}
				string place;
				while (true) {
					cout << "Enter place: ";
					cin >> place;
					if (check_for_string(place))
						break;
				}
				cout << "Enter supervisor mark: ";
				int supervisor_mark = -1;
				while (supervisor_mark < 0 || supervisor_mark > 5) {
					cin >> supervisor_mark;
					if (supervisor_mark < 0 || supervisor_mark > 5)
						cout << "Enter possible mark: ";
				}
				cout << "Enter comissen mark: ";
				int comissen_mark = -1;
				while (comissen_mark < 0 || comissen_mark > 5) {
					cin >> comissen_mark;
					if (comissen_mark < 0 || comissen_mark > 5)
						cout << "Enter possible mark: ";
				}
				Student* adding_student = new Senior_student(surname, initials, group, cathedra_id, mark, topic_ssp, place, supervisor_mark, comissen_mark);
				Student_t obj(code, adding_student);
				table.insert(obj);
				break;
			}
			else if (option_tmp1 == 2) {
				string surname;
				while (true) {
					cout << "Enter surname: ";
					cin >> surname;
					if (check_for_string(surname))
						break;
				}
				cout << "Enter code: ";
				int code = -1;
				code = getValueLoop<int>("Entered not int", "Enter code: ");
				string initials;
				while (true) {
					cout << "Enter initials: ";
					cin >> initials;
					if (check_for_string(initials))
						break;
				}
				cout << "Enter group: ";
				string group;
				cin >> group;
				cout << "Enter cafedra id: ";
				int cathedra_id = -1;
				cathedra_id = getValueLoop<int>("Entered not int", "Enter cafedra id: ");
				string topic_dp;
				while (true) {
					cout << "Topic diploma project: ";
					cin >> topic_dp;
					if (check_for_string(topic_dp))
						break;
				}
				string place;
				while (true) {
					cout << "Topic place: ";
					cin >> place;
					if (check_for_string(place))
						break;
				}
				cout << "Enter supervisor mark: ";
				int supervisor_mark = -1;
				while (supervisor_mark < 0 || supervisor_mark > 5) {
					cin >> supervisor_mark;
					if (supervisor_mark < 0 || supervisor_mark > 5)
						cout << "Enter possible mark: ";
				}
				cout << "Enter reviewer mark: ";
				int reviewer_mark = -1;
				while (reviewer_mark < 0 || reviewer_mark > 5) {
					cin >> reviewer_mark;
					if (reviewer_mark < 0 || reviewer_mark > 5)
						cout << "Enter possible mark: ";
				}
				cout << "Enter gec mark: ";
				int gec_mark = -1;
				while (gec_mark < 0 || gec_mark > 5) {
					cin >> gec_mark;
					if (gec_mark < 0 || gec_mark > 5)
						cout << "Enter possible mark: ";
				}
				Student* adding_student = new Graduate(surname, initials, group, cathedra_id, topic_dp, place, supervisor_mark, reviewer_mark, gec_mark);
				Student_t obj(code, adding_student);
				table.insert(obj);
				break;
			}
		}
		}
		else if (option == 2) { 
			cout << "Enter code for searching student: ";
			int code = -1;
			while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
				if (table.check_finder(code))
					break;
				else
					cout << "Student is not found enter existing student\nEnter code for searching student: ";
			}	
			cout << "Info: ";
			table.get_info_with_code(code)->print();
		}
		else if (option == 3) {
			cout << "Enter code for deleteing student: ";
			int code = -1;
			while (true) {
				code = getValueLoop<int>("Entered not int", "Enter code: ");
				if (table.check_finder(code))
					break;
				else
					cout << "Student is not found enter existing student\nEnter code for searching student: ";
			}
			string type = table.get_info_with_code(code)->get_type(); // добавить тип студента в параметр удаления
			table.delete_with_code(code);//было type
			table.print_table();
		}
		else if (option == 4) {
		int code = -1;
		cout << "Enter code of student you would like to find: ";
		while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		}
		cout <<"Searching student with code: "<<code<<" is "<< table.get_info_with_code(code)->get_type()<<endl;
		}
		else if (option == 5) {
		int code = -1;
		cout << "Enter code of student whose marks you would like to find: ";
		while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		}
		cout << "Marks: \n";
		const int* buf = table.get_marks(code);
		for (int i = 0; i < 4; i++) //можно задефайнить или посчитать скок эл эл не нул
			cout << buf[i]<<"\n";
		}
		else if (option == 6) {
		cout << "Enter code of student whose group you would like to change: ";
		int code = -1;
		while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		}
		string new_group;	
		cout << "Enter new group: ";
		cin >> new_group;
		table.get_info_with_code(code)->srt_group(new_group);
		}
		else if (option == 7) {
		cout << "Enter shifting\n1) Junior student --> Senior student\n2) Senior student --> Graduate student\n";
		cout << "Make your choice --> ";
		int option2 = -1;
		while (option2 <= 0 || option2 > 2){
			option2 = getValueLoop<int>("Entered not int", "Make your choice --> ");
		} // ввел option
		cout << "Enter students code: ";
		int code = -1;
		while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		} //должен сохраниться code
		if (option2 == 1) {
			string surname = table.get_info_with_code(code)->get_surname();
			string initials = table.get_info_with_code(code)->get_initials();
			string group = table.get_info_with_code(code)->get_group();
			int cathedra_id = table.get_info_with_code(code)->get_cathedra_id();
			int marks[4];
			for (int i = 0; i < 4; i++)
				marks[i] = 0;
			string topic_ssp = "";
			string place = "";
			int supervisor_mark = 0;
			int comissen_mark = 0;
			Student* change_student = new Senior_student(surname, initials, group, cathedra_id, marks, topic_ssp, place, supervisor_mark, comissen_mark);
			Student_t obj(code, change_student);
			table.insert(obj);
			string type = table.get_info_with_code(code)->get_type();
			table.delete_with_code(code);
		}
		else if (option2 == 2) {
			string surname = table.get_info_with_code(code)->get_surname();
			string initials = table.get_info_with_code(code)->get_initials();
			string group = table.get_info_with_code(code)->get_group();
			int cathedra_id = table.get_info_with_code(code)->get_cathedra_id();
			string topic_dp = "";
			string place = "";
			int supervisor_mark = 0;
			int reviewer_mark = 0;
			int gec_mark = 0;
			Student* change_student = new Graduate(surname, initials, group, cathedra_id, topic_dp, place, supervisor_mark, reviewer_mark, gec_mark);
			Student_t obj(code, change_student);
			table.insert(obj);
			string type = table.get_info_with_code(code)->get_type();
			table.delete_with_code(code);
		}
		}
		else if (option == 8) {
		cout << "Enter code of student whose topic of scientific project you would like to get: ";
		int code = -1;
		while (true) {
			code = getValueLoop<int>("Entered not int", "Enter code: ");
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		}
		cout << "Topic: ";
		const string line = table.get_topic_p(code);
		cout << line<< endl;
		int option3 = -10;
		cout << "Press 1 if you want to change topic of project else press 0\nMake your choice --> ";
		while (option3 <= -1 || option3 > 2) {
			option3 = getValueLoop<int>("Entered not int", "Make your choice --> ");
		}
		if (option3 == 1) {
			string new_line;
			while (true) {
				cout << "Enter new topic: ";
				cin >> new_line;
				if (check_for_string(new_line))
					break;
			}
			new_line = table.set_topic(code, new_line);
			cout << "You entered: " << new_line<<endl;
		}
		}
		else if (option == 9) {
		cout << "Enter code of student whose place of scientific project you would like to get: ";
		int code = -1;
		code = getValueLoop<int>("Entered not int", "Enter cjde: ");
		while (true) {
			if (table.check_finder(code))
				break;
			else
				cout << "Student is not found enter existing student\nEnter code for searching student: ";
		}
		cout << "Place: ";
		const string line = table.get_place_p(code);
		cout << line << endl;
		int option4 = -10;
		cout << "Press 1 if you want to change place of project else press 0\nMake your choice --> ";
		while (option4 <= -1 || option4 > 2) {
			option4 = getValueLoop<int>("Entered not int", "Make your choice --> ");
		}
		if (option4 == 1) {
			string new_line;
			while (true) {
				cout << "Enter new place for project: ";
				cin >> new_line;
				if (check_for_string(new_line))
					break;
			}
			new_line = table.set_place_p(code, new_line);
			cout << "You entered: " << new_line << endl;
		}
		}
		else if (option == 10) {
			cout << "Show info: \n";
			table.print_table();
		}
		else if (option == 11) {
	//	cout << "LOADING IN FILE!\n";
	cout << "Load new document option 1\nLoad in exist document option 2\n";
	int option5 = -1;
	while (option5 <= -1 || option5 > 2){
		option5 = getValueLoop<int>("Entered not int", "Enter 1 or 2 --> ");
		if (option5 == 1){
			table.load_in_file_new();
			cout << "LOADING IN FILE!\n";
		}
		if (option5 == 2){
			table.load_in_file_append();
			cout << "LOADING IN FILE!\n";
		}
		}
	}
	}
	return 0;
}

//массив указателей на фу-ии//можно посмотреть и попрактиковаться
//создать класс исключений
//ПЕРЕГРУЗИТЬ ОПЕРАТОРЫ для уменьшения кода
//создать документацию то есть выгрузить на доксиджен
//использовать map + написать его реализацию
//выгрузить на github
//сделвть код string вида (B20-503 M17-903)