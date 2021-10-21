#include <iostream>
#include <unordered_map>
#include <vector>
#include<Windows.h>
#include <string>
#include<conio.h>

using std::string;
using std::vector;

using dict = std::unordered_map<char, char>; // Использование несортируемого словаря

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    int k;
    vector<char> result; // Создание вектора для вывода результата
    string alphabet("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    dict alphabet_map; // Перевод строки алфавита в словарь
    std:: cout << "Введите сообщение на русском языке строчными буквами, которое будет закодировано: " << std::endl;
    std::getline(std::cin, s); // Ввод текста
    std:: cout << "\nВведите сдвиг:" << std::endl;
    std::cin >> k; // Ввод сдвига
    int n = alphabet.size(); // Подсчет количества символов в алфавите
    k = ((k % n) + n) % n; // Условие, для шага больше чем количество символов в алфавите и для декодировки (отрицательного шага)
    for (int i = 0; i < n; i++) // Цикл проходящий по каждому введенному символу
    {
        auto ind = (i + k) % n; // Считает индекс символа со сдвигом
        alphabet_map[alphabet[i]] = alphabet[ind]; // Присваивание символу значения со здвигом
    }
    std::cout << "\nПолученное закодированное сообщение:" << std::endl;
    for (auto it : s) {
        try {
            result.push_back(alphabet_map.at(it)); // Вставка изменённого символа в конечный результат 
        }
        catch (const std::out_of_range& exception) // Обработка исчключений для пробела и других символов. Возвращает то же, что и ввели
        {
            result.push_back(it);
        }
    }
    for (auto it : result) // Вывод результата
    {
        std::cout << it;
    }
    _getch();
    return 0;
}
