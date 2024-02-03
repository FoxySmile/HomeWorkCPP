#pragma once
#include <iostream>
class MyString
{
private:
	char* str;
	int size;
	int index;
public:
	MyString(const char arr[]);
	void show();
	bool empty();
	void clear();
	void append(const char arr[]);
	void append(const MyString& newString);
	void operator=(const char arr[]);
	int compare(const char arr[]);
	int compare(const MyString& newString);
	static int stoi(const char arr[]);
	//int find(const char arr[]);
	//void insert(const char arr[]);
};

