//Вариант 1
#include <iostream>

/// <summary>
/// Вычисляет площадь прямоугольника
/// </summary>
/// <param name="side_one">Длина первой стороны прямоугольника</param>
/// <param name="side_two">Длина второй стороны прямоугольника</param>
/// <returns>Площадь прямоугольника</returns>
/// <remarks>Если прямоугольника не существует, возвращает -1</remarks>
double square(int side_one, int side_two)
{
	int Square_one_and_two = side_one * side_two; // Площадь
	if (Square_one_and_two > 0)
	{
		return Square_one_and_two;
	}
	else
	{
		return -1;
	}
}

int main()
{
	setlocale(0, "");
	std::cout << "===== ПРОГРАММА ДЛЯ РАСЧЕТА ПЛОЩАДИ ПРЯМОУГОЛЬНИКА =====" << std::endl;
	int side_one(0), side_two(0),square_sides(0);
	std::cout << "Введите первую сторону прямоугольника: ";
	std::cin >> side_one; // Первая сторона прямоугольника
	std::cout << "Введите вторую сторону прямоугольника: ";
	std::cin >> side_two; // Вторая сторона прямоугольника
	square_sides = square(side_one, side_two);
	std::cout << "Площадь данного прямоугольника равна " << square_sides << std::endl;
	return 0;
}
// η1 = 3
// η2 = 2
// Gillb = η1 + η2 = 3 + 2 = 5
// Уровни сложности: Низкая сложность (Gillb ≤ 10)