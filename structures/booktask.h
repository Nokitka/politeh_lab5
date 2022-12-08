#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

#define BUFFER_SIZE 100

struct BOOK
{
	char author[BUFFER_SIZE];
	char header[BUFFER_SIZE];
	int year;
	int price;
	char category[BUFFER_SIZE];
};

extern void BookTask();