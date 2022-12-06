#include "stringstask.h"

const char* GetString1() {
	static const char* c = (char *)"String 1";
	return c;
}

const char* GetString2() {
	static const char* c = (char *)"String 2";
	return c;
}

const char* GetString3() {
	static const char* c = (char *)"String 3";
	return c;
}

const char* GetString4() {
	static const char* c = (char *)"String 4";
	return c;
}

const char* GetString5() {
	static const char* c = (char *)"String 5";
	return c;
}

void ThirdTask() {
	const char* (*arr[])() = {
		GetString1, GetString2, GetString3, GetString4, GetString5, 
	};

	int n;

	printf("Input n: ");
	scanf("%i", &n);
	printf(arr[abs(n) % 5]());
}