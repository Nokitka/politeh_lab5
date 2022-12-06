#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

struct BOOK
{
	string author;
	string header;
	int year;
	int price;
	string category;
};

extern void BookTask();