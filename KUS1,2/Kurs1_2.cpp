#include "functions.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string text[quantity];
    int amount = 0; // Количество строк
    int punkt = 1; // Пункт меню

    do
    {
        system("cls");
        cout << "Выберите необходимое действие: \n" <<
            "1. Считать текст из файла.\n" <<
            "2. Вывести заданное число строк.\n"
            "3. Вставить заданное число одинаковых символов в начало строки.\n" <<
            "4. Заменить заданное число символов в начале строки на другую последовательность символов. \n" <<
            "5. Удалить заданное число символов в начале строки. \n" <<
            "6. Сохранить текст в файл.\n" <<
            "0. Закончить работу.\n";

        punkt = input_int("Введите номер пункта меню: \n", 0, 6);

        switch (punkt)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            file_read(text, amount);
            system("pause");
            break;
        }
        case 2:
        {
            output_char(text, amount);
            system("pause");
            break;
        }
        case 3:
        {
            input_same_char(text, amount);
            system("pause");
            break;
        }
        case 4:
        {
            replace_char(text, amount);
            system("pause");
            break;
        }
        case 5:
        {
            char_remove(text, amount);
            system("pause");
            break;
        }
        case 6:
        {
            file_write(text, amount);
            system("pause");
            break;
        }
        default:
            cout << "Неправильный выбор пункта меню.\n";
            system("pause");
            break;
        }
    } while (punkt != 0);

    return 0;
}
