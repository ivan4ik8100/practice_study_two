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
		shareid_real = (real_one + real_two);
		shareid_imag = (imag_one + imag_two);
	}
	static void multiplyComplex(double real_one, double imag_one, double real_two, double imag_two)
	{
		shareid_real = real_one * real_two - imag_one * imag_two;
		shareid_imag = real_one * imag_two + real_two * imag_one;
	}
	static double modulus(double real_one, double imag_one)
	{
		return sqrt(real_one * real_one + imag_one * imag_one);
	}
	static string toString()
	{
		if (shareid_imag < 0)
		{
			return to_string(shareid_real) + " - " + to_string(-1 * shareid_imag) + "i";
		}
		else if (shareid_imag > 0)
		{
			return to_string(shareid_real) + " + " + to_string(shareid_imag) + "i";
		}
		else
		{
			return to_string(shareid_real);
		}
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
	while (bufferka == 0)
	{
		cin >> remember;
		try {

			switch (remember)
			{
			case 1:
				bufferka = 1;
				cout << endl << "Введите первое комплексное число";
				cout << endl << "Вещественная часть: ";
				cin >> real_one;
				cout << "Мнимая часть: ";
				cin >> imag_one;

				cout << endl << "Введите второе комплексное число";
				cout << endl << "Вещественная часть: ";
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
				cout << endl << "Вещественная часть: ";
				cin >> real_one;
				cout << "Мнимая часть: ";
				cin >> imag_one;

				cout << endl << "Введите второе комплексное число";
				cout << endl << "Вещественная часть: ";
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
				cout << endl << "Вещественная часть: ";
				cin >> real_one;
				cout << "Мнимая часть: ";
				cin >> imag_one;
				cout << "Вывод функции:" << endl << Eigth_one.modulus(real_one, imag_one) << endl;
				break;
			default:
				throw std::invalid_argument("Функции под таким номером не существует");
			}
		}
		catch (invalid_argument) { cout << "Выберите существующие действие" << endl; }
	}
}
