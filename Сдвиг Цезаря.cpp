#include <iostream>
#include <unordered_map>
#include <vector>
#include<Windows.h>
#include <string>
#include<conio.h>

using std::string;
using std::vector;

using dict = std::unordered_map<char, char>;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    int k;
    vector<char> result;
    string alphabet("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    dict alphabet_map;
    std:: cout << "Введите сообщение на русском языке строчными буквами, которое будет закодировано: " << std::endl;
    std::getline(std::cin, s);
    std:: cout << "\nВведите сдвиг:" << std::endl;
    std::cin >> k;
    int n = alphabet.size();
    k = ((k % n) + n) % n;
    for (int i = 0; i < n; i++) {
        auto ind = (i + k) % n;
        alphabet_map[alphabet[i]] = alphabet[ind];
    }
    std::cout << "\nПолученное закодированное сообщение:" << std::endl;
    for (auto it : s) {
        try {
            result.push_back(alphabet_map.at(it));
        }
        catch (const std::out_of_range& exception) {
            result.push_back(it);
        }
    }
    for (auto it : result) {
        std::cout << it;
    }
    _getch();
    return 0;
}