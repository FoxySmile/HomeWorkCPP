#pragma once

#include <iostream>

using namespace std;

class StudentBuilder;
class PasportBuilder;

class Builder
{
public:
	void virtual setFirstName(string firstName) = 0;
	void virtual setLastName(string lastName) = 0;
	void virtual setYear(string year) = 0;
};

class Student
{
private:
	friend class StudentBuilder;
	string firstName = "Vova";
	string lastName = "Nikitin";
	string year = "21";
public:
	void showInfo() {
		cout << firstName << " " << lastName << " " << year << endl;
	};
};

class Pasport
{
private:
	friend class PasportBuilder;
	string pasport = "";
public:
	void showPasport() {
		cout << pasport << endl;
	};
};

class StudentBuilder : public Builder
{
private:
	Student student;
public:
	void setFirstName(string firstName) {
		student.firstName = firstName;
	};
	void setLastName(string lastName) {
		student.lastName = lastName;
	};
	void setYear(string year) {
		student.year = year;
	};
	Student getResult() {
		return student;
	};
};

class PasportBuilder : public Builder
{
private:
	Pasport pas;
public:
	void setFirstName(string firstName) {
		pas.pasport += firstName + " ";
	};
	void setLastName(string lastName) {
		pas.pasport += lastName + " ";
	};
	void setYear(string year) {
		pas.pasport += year;
	};
	Pasport getResult() {
		return pas;
	};
};
