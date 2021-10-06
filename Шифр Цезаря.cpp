#include <iostream>
#include<Windows.h>
#include<string>
#include <conio.h>

using namespace std;

int main()
{    
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        int i, k;

        char alphabet[] =
        {
                    'а','б','в','г','д','е','ё','ж','з','и',
                    'й','к','л','м','н','о','п','р','с',
                    'т','у','ф','х','ц','ч','ш','щ','ъ',
                    'ы','ь','э','ю','я'
        };
        char arr[150];
        cout << "Введите сообщение на русском языке строчными буквами, которое будет закодировано: " << endl;
        cin.getline(arr, 150);

        cout << "\nВведите сдвиг:" << endl;
        cin >> k;

        char* begin = alphabet;
        char* end = alphabet + sizeof(alphabet);

        for (int i = 0; i < strlen(arr); ++i)
        {
            char* ch = find(begin, end, arr[i]);
            if (ch != end)
            {
                arr[i] = *(begin + (ch - begin + k) % sizeof(alphabet));
            }
        }
        cout << "\nПолученное закодированное сообщение:\n" << arr << endl;

        _getch();
        return 0;
}

            
