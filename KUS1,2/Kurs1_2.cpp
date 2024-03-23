#include "functions.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string text[quantity];
    int amount = 0; // ���������� �����
    int punkt = 1; // ����� ����

    do
    {
        system("cls");
        cout << "�������� ����������� ��������: \n" <<
            "1. ������� ����� �� �����.\n" <<
            "2. ������� �������� ����� �����.\n"
            "3. �������� �������� ����� ���������� �������� � ������ ������.\n" <<
            "4. �������� �������� ����� �������� � ������ ������ �� ������ ������������������ ��������. \n" <<
            "5. ������� �������� ����� �������� � ������ ������. \n" <<
            "6. ��������� ����� � ����.\n" <<
            "0. ��������� ������.\n";

        punkt = input_int("������� ����� ������ ����: \n", 0, 6);

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
            cout << "������������ ����� ������ ����.\n";
            system("pause");
            break;
        }
    } while (punkt != 0);

    return 0;
}
