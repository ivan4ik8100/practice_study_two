#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

/// функция для установки цвета консоли по названию и сохранение их
void vievConsoleColor(int buferka , int clr1 , int clr2)
{
    if (buferka == 1)
    {
        char color1, color2;
        string color1_name, color2_name, Word_name;
        char sys[10] = "color ";
        ifstream fin("настройки-консоли.txt"); //Создает объект fin для чтения из файла и открывает файл
        fin >> color1 >> color2 >> Word_name;// Читает данные из файла  
        fin.close(); //Закрывает файл и освобождает ресурсы
        sys[6] = color1;
        sys[7] = color2;
        system(sys);
    }
    else
    {
        ofstream fout("настройки-консоли.txt"); //Создает объект fin для чтения из файла и открывает файл
        fout << clr1 << " " << clr2 << " "; //Записывает данные в файл 
    }
    
}
/// Функция для вывода и сохранения любимого слова
string vievFavoriteWord(int buferka, string Word_input)
{
    if (buferka == 1)
    {
        string Word;
        ifstream fin("настройки-консоли.txt"); //Создает объект fin для чтения из файла и открывает файл
        fin >> Word >> Word >> Word;// Читает данные из файла  
        fin.close(); //Закрывает файл и освобождает ресурсы
        return Word;
    }
    else
    {
        ofstream fout("настройки-консоли.txt", ios::app); //Создает объект fin для чтения из файла и открывает файл
        fout << Word_input; //Записывает данные в файл 
        return "";
    }
}
int main() 
{
    system("chcp 1251 > null");
    int color1(-1), color2(-1);
    string slovo;
    int buferka;
    ifstream fin("настройки-консоли.txt"); //Создает объект fin для чтения из файла и открывает файл
    if (fin.is_open())
    {
        string color1_name, color2_name;
        buferka = 1;
        fin >> color1 >> color2 >> slovo;
        fin.close();
        cout << "===== Сохраненные настройки =====" << endl;
        vievConsoleColor(buferka, color1, color2);
        switch (color1)
        {
        case 0: color1_name = "Черный"; break;
        case 1: color1_name = "Синий"; break;
        case 2: color1_name = "Зеленый"; break;
        case 3: color1_name = "Голубой"; break;
        case 4: color1_name = "Красный"; break;
        case 5: color1_name = "Фиолетовый"; break;
        case 6: color1_name = "Желтый"; break;
        case 7: color1_name = "Белый"; break;
        }
        switch (color2)
        {
        case 0: color2_name = "Черный"; break;
        case 1: color2_name = "Синий"; break;
        case 2: color2_name = "Зеленый"; break;
        case 3: color2_name = "Голубой"; break;
        case 4: color2_name = "Красный"; break;
        case 5: color2_name = "Фиолетовый"; break;
        case 6: color2_name = "Желтый"; break;
        case 7: color2_name = "Белый"; break;
        }
        cout << "Цвет фона консоли: " << color1_name << endl;
        cout << "Цвет текста консоли: " << color2_name << endl;
        cout << "Любимое слово: " << vievFavoriteWord(buferka, slovo) << endl;
        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;
        cout << endl;
        if (choice == 'y' || choice == 'Y')
        {
            buferka = 0;
            int choice(-1);
            int colors[2];
            cout << "Выберите 2 цвета: 1 - фона, 2 - текста консоли (разных):" << endl;
            cout << "0 - Черный" << endl << "1 - Синий" << endl << "2 - Зеленый" << endl << "3 - Голубой" << endl;
            cout << "4 - Красный" << endl << "5 - Фиолетовый" << endl << "6 - Желтый" << endl << "7 - Белый" << endl;
            for (int i = 0; i < 2; i++)
            {
                cout << "Выберите " << i + 1 << " цвет: ";
                cin >> choice;
                while (choice > 7 or choice < -1)
                {
                    cout << endl << "Выберите число из списка." << endl << endl;
                    cout << "Выберите " << i + 1 << " цвет: ";
                    cin >> choice;
                    if (choice > -1 and choice < 7)
                    {
                        break;
                    }
                }
                colors[i] = choice;
            }
            color1 = colors[0];
            color2 = colors[1];
            cout << endl << "Введите любимое слово: ";
            cin >> slovo;
            vievConsoleColor(buferka, color1, color2);
            vievFavoriteWord(buferka, slovo);
            cout << endl << "Настройки обновлены!" << endl;
        }
    }    
    else // файла нет – вводим новые настройки
    {
        buferka = 0;
        int choice(-1);
        int colors[2];
        cout << "Выберите 2 цвета: 1 - фона, 2 - текста консоли (разных):" << endl;
        cout << "0 - Черный" << endl << "1 - Синий" << endl << "2 - Зеленый" << endl << "3 - Голубой" << endl;
        cout << "4 - Красный" << endl << "5 - Фиолетовый" << endl << "6 - Желтый" << endl << "7 - Белый" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Выберите " << i + 1 << " цвет: ";
            cin >> choice;
            while (choice > 7 or choice < -1)
            {
                cout << endl << "Выберите число из списка." << endl << endl;
                cout << "Выберите " << i + 1 << " цвет: ";
                cin >> choice;
                if (choice > -1 and choice < 7)
                {
                    break;
                }
            }
            colors[i] = choice;
        }
        color1 = colors[0];
        color2 = colors[1];
        cout << endl << "Введите любимое слово: ";
        cin >> slovo;
        vievConsoleColor(buferka, color1, color2);
        vievFavoriteWord(buferka, slovo);
        cout << endl << "Настройки сохранены!" << endl;
    }
    return 0;
}