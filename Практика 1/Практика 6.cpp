#include <iostream>
using namespace std;

class Squares {
private:
	double a_Squar;
	double b_Squar;
	double remember;
public:

	void setNumbers(double a, double b)
	{
		a_Squar = a * a;
		b_Squar = b * b;
	}
	void addSquares()
	{
		remember = a_Squar + b_Squar;
	}
	void subtractSquares()
	{
		remember = a_Squar - b_Squar;
	}
	double getResults()
	{
		return remember;
	}
};

int main()
{
	system("chcp 1251>null");
	Squares arrow;
	double a(0), b(0);
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	arrow.setNumbers(a, b);
	arrow.addSquares();
	cout << "Сумма квадратов равна " << arrow.getResults() << endl;
	arrow.subtractSquares();
	cout << "Разность квадратов равна " << arrow.getResults() << endl;
	system("pause");
	return 0;
}
