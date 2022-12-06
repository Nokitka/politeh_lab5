#include "calculatortask.h"

using namespace std;

double (*calculator)(double a, double b);

double Sum(double a, double b) {
	return a + b;
}

double Sub(double a, double b) {
	return a - b;
}

double Mul(double a, double b) {
	return a * b;
}

double Div(double a, double b) {
	if (b == 0)
		return -INFINITY;
	return a / b;
}

void First() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool isWork = true;

	while (isWork) {

		bool flag = true;
		double a, b;
		char symbol;

		cout << "������� ������ �����: ";
		cin >> a;
		cout << "������� ������ �����: ";
		cin >> b;
		cout << "������� ��������: ";
		cin >> symbol;

		switch (symbol)
		{
		case '+':
			calculator = Sum;
			break;

		case '-':
			calculator = Sub;
			break;

		case '*':
			calculator = Mul;
			break;

		case '/':
			calculator = Div;
			break;

		case '^':
			calculator = static_cast<double(*)(double, double)>(pow);
			break;

		default:
			cout << "Error" << endl;
			flag = false;
		}

		if (flag) cout << "���������: " << calculator(a, b) << endl;

		cout << "���� ������ �����, ������� esc, ����� - ����� �������" << endl;

		switch (_getch())
		{
		case 27:
			isWork = false;
		default:
			break;
		}
	}
}
