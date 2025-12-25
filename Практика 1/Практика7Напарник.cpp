#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct EducationCalc {
	static double averageGrade(const double Grade[], int size) {
		if (size <= 0) {
			throw invalid_argument("Количество оценок не может быть меньше 1");
		}
		double sum = 0.0;
		for (int i = 0; i < size; i++)
		{
			if (Grade[i] < 2 || Grade[i] > 5)
			{
				throw out_of_range("оценка не может быть меньше 2 или больше 5");
			}
			sum += Grade[i];
		}
		return sum / size;
	}

	static double examPassPercentage(const double correctAnswers, int numberOfResponses) {
		if (correctAnswers < 0 || correctAnswers>numberOfResponses) {
			throw out_of_range("Количество правильных ответов не может быть отрицательным или больше, чем все количество ответов");
		}
		double procent = (correctAnswers / numberOfResponses) * 100;
		return procent;
	}
	static double studyTimePerTopic(const double topic, int time) {
		if (topic < 1) {
			throw invalid_argument("Количество тем не может быть меньше 1");
		}
		if (time < 0) {
			throw invalid_argument("Время не может быть отрицательное");
		}
		return time / topic;

	}
	static double gradeNeeded(const double gradeYear, int need) {
		if (gradeYear < 2 || gradeYear > 5) {
			throw out_of_range("Ваша оценка за год не может быть больше 5 или меньше 2");
		}
		if (need < gradeYear)
		{
			throw invalid_argument("Оценка которую человек хочет не может быть меньше его оценки в нынешнее время");
		}
		double avg = (gradeYear + need) / 2;
		double gradeExam = round(avg);
		return gradeExam;
	}
};

int main() {
	setlocale(0, "");

	int size;
	cout << "Введите количество оценок: ";
	cin >> size;

	vector<double> Grade(size);
	for (int i = 0; i < size; i++) {
		cout << "Введите оценку " << (i + 1) << ": ";
		cin >> Grade[i];
	}

	cout << "Ваш средний балл: " << EducationCalc::averageGrade(Grade.data(), size) << endl;

	double correctAnswers;
	int numberOfResponses;
	cout << "\nвведите количество правильных ответов: ";
	cin >> correctAnswers;
	cout << "введите количество всех ответов: ";
	cin >> numberOfResponses;
	cout << "процент правильных ответов: " << EducationCalc::examPassPercentage(correctAnswers, numberOfResponses) << "%" << endl;

	double topic;
	int time = 0;
	cout << "\nВведите количество тем: ";
	cin >> topic;
	cout << "Введите количество времени в минутах: ";
	cin >> time;
	cout << "Время на изучение одной темы: " << EducationCalc::studyTimePerTopic(topic, time) << " минут" << endl;

	double gradeYear = 0.0;
	int need = 0;
	cout << "\nВведите вашу годовую оценку: ";
	cin >> gradeYear;
	cout << "Введите оценку которую хотите получить, чтобы узнать, что вы должны получить за экзамен: ";
	cin >> need;
	if (gradeYear == 3 && need == 5 || gradeYear == 2 && need == 4 || gradeYear == 2 && need == 5)
	{
		cout << "Невозможно получить такую оценку с вашей оценкой" << endl;
	}
	else
		cout << "Для получения итоговой оценки: " << need << ", на экзамене нужно получить: " << EducationCalc::gradeNeeded(gradeYear, need) << ", с вашим баллом: " << gradeYear << endl;

	system("pause");
	return 0;

}
