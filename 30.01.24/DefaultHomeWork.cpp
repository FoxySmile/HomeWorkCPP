#include <iostream>
#include <string>
#define random(a,b) a + rand() % (b - a + 1)
using namespace std;

const int countNames = 5;
const string names[] = { "Олег", "Паша","Коля","Вика", "Оля" };

class Student {
	static int id;
	int uniqId;
	string name;
	int* marks = nullptr;
	int countMarks = 0;
public:
	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = id++;
	}
	Student(Student& st) : Student() {
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	~Student() {
		if (this->marks != nullptr) {
			delete[] marks;
		}
	}

	void operator = (Student& st) {
		name = st.name;
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	void addMark(int mark) {
		int* buf = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++) {
			buf[i] = marks[i];
		}
		buf[countMarks++] = mark;
		delete[]marks;
		marks = buf;
	}

	void delMark(int index, int mark) {
		if (countMarks == 0) return;
		if (countMarks == 1) {
			countMarks = 0;
			delete[]marks;
			marks = nullptr;
			return;
		}
		int* buf = new int[countMarks - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = marks[i];
		}
		for (int i = index + 1; i < countMarks; i++) {
			buf[i - 1] = marks[i];
		}
		delete[]marks;
		marks = buf;
		countMarks--;
	}

	void changeMark(int index, int mark) {
		if (index >= 0 && index < countMarks) {
			marks[index] = mark;
		}
	}

	void showInfo() {
		cout << uniqId << " : " << name << " : ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
	}
};

int Student::id = 0;

struct GroupName {
	static int num;
	static char alpha;
public:
	static string getUniqGroupName() {
		if (num == 3) return "";
		int numPrev = num;
		char alphaPrev = alpha;

		if (alpha == 'Д') {
			alpha = 'А';
			num += 1;
		}
		else alpha++;

		return to_string(numPrev) + alphaPrev;
	}
};

int GroupName::num = 1;
char GroupName::alpha = 'А';

class Group {
protected:
	string uniqId;
	Student** students = nullptr;
	int countStudents = 0;
public:
	Group() {
		this->countStudents = 0;
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "Достигнут предел групп";
	}

	int getCountStudents() {
		return countStudents;
	}

	void showInfo() {
		if (uniqId != "") cout << uniqId << " " << endl;
		for (int i = 0; i < countStudents; i++) {
			students[i]->showInfo();
		}
	}

	void addStudent(Student& st) {
		if (this->countStudents == 5) {
			cout << "Превышен допустимый предел количества студентов";
			return;
		}
		Student** buf = new Student*[countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		delete[]students;

		buf[countStudents] = new Student(st);

		countStudents++;
		students = buf;
	}

	void delStudent(int index) {
		if (countStudents == 0) {
			return;
		}
		if (this->countStudents == 1) {
			delete[] students[0];
			students = nullptr;
			return;
		}
		Student** buf = new Student*[countStudents - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = students[i];
		}
		for (int i = index + 1; i < countStudents; i++) {
			buf[i - 1] = students[i];
		}

		delete students[index];
		delete[]students;

		countStudents--;
		students = buf;
	}

	Student* getStudentByIndex(int index) {
		return students[index];
	}
};

class School {
private:
	Group** groups = nullptr;
	int countGroups = 0;
public:
	School(Group** groups, int countGroups) {
		this->countGroups = countGroups;
		this->groups = groups;
	}

	void transferStudents(int idStudent, int idOfGroup, int idInGroup) {
		if (groups[idInGroup]->getCountStudents() != 5) {
			Student* st = groups[idOfGroup]->getStudentByIndex(idStudent);
			groups[idOfGroup]->delStudent(idStudent);
			//groups[idInGroup]->addStudent(st);
		}
	}

	void showInfo() {
		for (int i = 0; i < countGroups; i++) {
			groups[i]->showInfo();
		}
	}
};

int main(){
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int const countGroups = 2;
	Group** groups = new Group*[countGroups];
	for (int i = 0; i < countGroups; i++) {
		groups[i] = new Group();
	}

	for (int i = 0; i < 30; i++) {
		int indexStudentInGroup = random(0, countGroups - 1);
		while (groups[indexStudentInGroup]->getCountStudents() != 5) {
			Student st;
			for (int j = 0; j < 4; j++) {
				st.addMark(random(2, 5));
			}
			groups[indexStudentInGroup]->addStudent(st);
		}
	}

	groups[0]->delStudent(0);

	School s(groups, countGroups);
	s.showInfo();
	s.transferStudents(3, 1, 0);
	cout << endl;
	s.showInfo();
}

/*Добавить класс Школа. Реализовать в нем метод переноса студента из одной группы в другую*/