#include <iostream>
#include <cmath>
#include <Complex>

using namespace std;

struct Complex_Calculator
{
	static double shareid_real;
	static double shareid_imag;
	void addComplex(double real_one, double imag_one, double real_two, double imag_two)
	{
		double one = (real_one + real_two);
		double two = (imag_one + imag_two);
		shareid_real = one;
		shareid_imag = two;
	}
	static void multiplyComplex(double real_one, double imag_one, double real_two, double imag_two)
	{
		double one = real_one * real_two - imag_one * imag_two;
		double two = real_one * imag_two + real_two * imag_one;
		shareid_real = one;
		shareid_imag = two;
	}
	static double modulus(double real_one, double imag_one)
	{
		double modulus_number = sqrt(real_one * real_one + imag_one * imag_one);
		return modulus_number;
	}
	static string toString()
	{
		string Vivod;
		if (shareid_imag < 0)
		{
			Vivod = to_string(shareid_real) + " - " + to_string(-1 * shareid_imag) + "i";
		}
		else if (shareid_imag > 0)
		{
			Vivod = to_string(shareid_real) + " + " + to_string(shareid_imag) + "i";
		}
		else
		{
			Vivod = to_string(shareid_real);
		}
		return Vivod;
	}
};
double Complex_Calculator::shareid_real = 0.0;
double Complex_Calculator::shareid_imag = 0.0;
int main()
{
	system("chcp 1251>null");
	Complex_Calculator Eigth_one;
	double real_one, imag_one, real_two, imag_two;
	int remember, bufferka = 0;
	cout << "Выберите действие:" << endl;
	cout << "1 - сложение двух комплексных чисел" << endl;
	cout << "2 - умножение двух комплексных чисел" << endl;
	cout << "3 - модуль комплексного числа" << endl;
	cin >> remember;
	while (bufferka == 0)
	{
		switch (remember)
		{
		case 1: 
			bufferka = 1;
			cout << endl << "Введите первое комплексное число";
			cout << endl << "Существующая часть: ";
			cin >> real_one;
			cout << "Мнимая часть: ";
			cin >> imag_one;

			cout << endl << "Введите второе комплексное число";
			cout << endl << "Существующая часть: ";
			cin >> real_two;
			cout << "Мнимая часть: ";
			cin >> imag_two;

			Eigth_one.addComplex(real_one, imag_one, real_two, imag_two);
			cout << "Вывод функции: " << endl;
			cout << Eigth_one.toString() << endl;
			break;
		case 2:
			bufferka = 1;
			cout << endl << "Введите первое комплексное число";
			cout << endl << "Существующая часть: ";
			cin >> real_one;
			cout << "Мнимая часть: ";
			cin >> imag_one;

			cout << endl << "Введите второе комплексное число";
			cout << endl << "Существующая часть: ";
			cin >> real_two;
			cout << "Мнимая часть: ";
			cin >> imag_two;

			Eigth_one.multiplyComplex(real_one, imag_one, real_two, imag_two);
			cout << "Вывод функции: " << endl;
			cout << Eigth_one.toString() << endl;
			break;
		case 3:
			bufferka = 1;
			cout << endl << "Введите комплексное число";
			cout << endl << "Существующая часть: ";
			cin >> real_one;
			cout << "Мнимая часть: ";
			cin >> imag_one;
			cout << "Вывод функции:" << endl << Eigth_one.modulus(real_one,imag_one) << endl;
			break;
		default:
			cout << "Такой функции не существует, выберите другую функцию!" << endl << endl;
			cin >> remember;
		}
	}
}
