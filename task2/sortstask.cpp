#include "sortstask.h"

void SwapInt(void* a, void* b) {
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	int tmp = *a1;
	*a1 = *b1;
	*b1 = tmp;
}

int CmpInt(void* a, void* b) {
	int* a1 = (int*)a;
	int* b1 = (int*)b;
	return *a1 > *b1 ? 1 : *a1 < *b1 ? -1 : 0;
}

void SwapDouble(void* a, void* b) {
	double* a1 = (double*)a;
	double* b1 = (double*)b;
	double tmp = *a1;
	*a1 = *b1;
	*b1 = tmp;
}

int CmpDouble(void* a, void* b) {
	double* a1 = (double*)a;
	double* b1 = (double*)b;
	return *a1 > *b1 ? 1 : *a1 < *b1 ? -1 : 0;
}

void SwapStr(void* a, void* b) {
	char** a1 = (char**)a;
	char** b1 = (char**)b;
	char *tmp = *a1;
	*a1 = *b1;
	*b1 = tmp;
}

int CmpStr(void* a, void* b) {
	char** a1 = (char**)a;
	char** b1 = (char**)b;

	int flag = 0;
	int i;
	
	for (i = 0; flag == 0 && (*(*a1 + i) != 0 || *(*b1 + i) != 0); i++)
		if (*(*a1 + i) < *(*b1 + i))
			flag = 1;
		else if (*(*a1 + i) > *(*b1 + i))
			flag = -1;
	if (flag && (*(*a1 + i) == 0))
		flag = 1;
	return -flag;
}

void Sort(char* arr, int numOfElements, size_t sizeOfElement, void (*Swap)(void *a, void *b), int (*Compare)(void* a, void* b)) {
	for (int i = 0; i < numOfElements; i++)
		for (int j = i + 1; j < numOfElements; j++)
			if (Compare(arr + sizeOfElement * i, arr + sizeOfElement * j) > 0)
				Swap(arr + sizeOfElement * i, arr + sizeOfElement * j);
}

void SecondA() {
	int nAr[] = {
		3, 2, 1, 5, 3, 6, 7, 8, 10, 9
	};
	int nTotal = sizeof(nAr) / sizeof(int);

	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf("%i", nAr[i]);
		printf("\n");
	}
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);
	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf("%i", nAr[i]);
		printf("\n");
	}
}

void SecondB() {
	double nAr[] = {
		(double)rand() / RAND_MAX * 100.0, (double)rand() / RAND_MAX * 100.0, (double)rand() / RAND_MAX * 100.0, (double)rand() / RAND_MAX * 100.0, (double)rand() / RAND_MAX * 100.0, (double)rand() / RAND_MAX * 100.0
	};
	int nTotal = sizeof(nAr) / sizeof(double);

	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf("%f", nAr[i]);
		printf("\n");
	}
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);
	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf("%f", nAr[i]);
		printf("\n");
	}

}

void SecondC() {
	char* nAr[] = {
		(char*)"QQQ",
		(char*)"SDF",
		(char*)"ABC",
		(char*)"BCA",
		(char*)"CBA",
		(char*)"CAB",
		(char*)"ERRS",
	};

	int nTotal = sizeof(nAr) / sizeof(char*);

	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf(nAr[i]);
		printf("\n");
	}
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(char *), SwapStr, CmpStr);
	for (int i = 0; i < nTotal; i++) {
		printf("%i: ", i);
		printf(nAr[i]);
		printf("\n");
	}

}