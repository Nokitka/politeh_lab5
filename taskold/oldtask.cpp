#include "oldtask.h"

void OldTask() {
	float a, b, c;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("������� A: ");
	scanf("%f", &a);
	printf("������� B: ");
	scanf("%f", &b);
	printf("������� C: ");
	scanf("%f", &c);

	printf("X\tResult\n");
	for (float x = -2; x <= 2; x += 0.5)
		printf("%1.1f\t%10.5f\n", x, (float)a*x*x + b*x + c);
}