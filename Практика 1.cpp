#include <iostream>
using namespace std;

int main( )
{
	setlocale(0, "");
	int number1(0), number2(0), umnozenie;
	cout << "Введите 2 числа, чтобы их перемножить" << endl;
	cout << "Первое число: ";
	cin >> number1;
	cout << "Второе число: ";
	cin >> number2;
	umnozenie = number1 * number2;
	cout << number1 << " * " << number2 << " = " << umnozenie << endl; //Вывод умножения
	return 0;
}
