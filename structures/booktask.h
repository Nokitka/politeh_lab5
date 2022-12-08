#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

#define BUFFER_LENTGH 100

struct BOOK
{
	char author[BUFFER_LENTGH];
	char header[BUFFER_LENTGH];
	int year;
	int price;
	char category[BUFFER_LENTGH];
};

extern void BookTask();