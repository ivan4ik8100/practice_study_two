#include <iostream>
using namespace std;

void SystemDivideByZeroException()
{
	int number_one(5), number_two(0), value(0);
	value = number_one / number_two;
	cout << value << endl;
}
void SystemIndexOutOfRangeException()
{
	int a[3] = { 1, 2 ,3 };
	int value = a[4];
	cout << value << endl;
}
int main()
{
	setlocale(0, "");
	int number(1), dlinna(10);
	SystemDivideByZeroException();
	while (true)
	{
		if (number > dlinna)
		{
			break;
		}
		cout << number << endl;
		number += 1;
	}
	SystemDivideByZeroException();
	return 0;
}
