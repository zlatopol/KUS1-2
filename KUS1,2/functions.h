#pragma once

#include "header.h"

int input_int(string message, int min)
{
    int n = min;

    std::cout << message << endl;
    std::cin >> n;
    while ((std::cin.fail()) || (n < min))
    {
        std::cin.clear();
        std::cin.ignore(BUFSIZ, '\n');
        //std::cin.sync();
        cout << "Поддерживаются целые числовые значения больше " << min << endl << message << endl;
        std::cin >> n;
    }
    std::cin.ignore(BUFSIZ, '\n');
    //std::cin.sync();
    return n;
}

int input_int(string message, int min, int max)
{
    int n = min;

    std::cout << message << endl;
    std::cin >> n;

    while ((std::cin.fail()) || (n < min || n > max))
    {
        std::cin.clear();
        std::cin.ignore(BUFSIZ, '\n');
        //std::cin.sync();
        cout << "Поддерживаются целые числовые значения от " << min << " до " << max << endl << message << endl;
        std::cin >> n;
    }
    std::cin.ignore(BUFSIZ, '\n');
    //std::cin.sync();
    return n;
}

char input_char(string message)
{
    string come;
    do
    {
        cout << message << '\n';
        cin >> come;
        std::cin.ignore(BUFSIZ, '\n');
        if (come.size() == 1)
        {
            return come[0];
        }
        cout << "Нужно ввести только 1 символ.\n";
    } while (true);
}

string input_string(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str, '\n');
    return str;
}
//**************************************************************************************

string file_open_read(string message)
{
    string filename = "";
    do
    {
        filename = input_string(message);
        ifstream file;
        file.open(filename);
        if (file.is_open())
        {
            file.close();
            return filename;
        }
        cout << "Не удалось открыть файл.\n";
    } while (true);
}

string file_open_write(string message)
{
    string filename = "";
    do
    {
        filename = input_string(message);
        ofstream file;
        file.open(filename);
        if (file.is_open())
        {
            file.close();
            return filename;
        }
        cout << "Не удалось открыть файл.\n";
    } while (true);
}

//**************************************************************************************

void output_char(string* text, const int &n)
{
    int start = input_int("Введите номер строки, с которой надо начать вывод", 1, n) - 1;
    int length = input_int("Введите колличество строк для вывода", 1, n - start);
    for (int i = start; i < start + length; i++)
    {
        cout << setw(5) << i + 1 << ". |" << text[i] << std::endl;
    }
}

//**************************************************************************************

void input_same_char(string* text, const int &n)
{
    char symbol = input_char("Введите символ, которое вы хотите вставить в начале: ");
    int count = input_int("Введите количество одинаковых символов: ", 0);
    int start = input_int("Введите номер строки, с которой надо начать вставку: ", 1, n) - 1;
    int end = input_int("Введите номер строки, с которой надо окончить вставку: ", start + 1, n) - 1;
    for (int i = start; i <= end; i++)
    {
        text[i].insert(0, count, symbol);
    }
}

void replace_char(string* text, const int &n)
{
    int count = input_int("Введите какое число символов надо заменить в начале: ", 0);
    string str = input_string("Введите последовательность символов, на которую будем заменять: ");
    int start = input_int("Введите номер строки, с которой надо начать вставку: ", 1, n) - 1;
    int end = input_int("Введите номер строки, с которой надо окончить вставку: ", start + 1, n) - 1;
    for (int i = start; i <= end; i++)
    {
        text[i].replace(0, count, str);
    }
}

void char_remove(string* text, const int &n)
{
    int count = input_int("Введите колчество символов, которые хотите удалить: ", 0);
    int start = input_int("Введите номер строки, с которой надо начать удалять: ", 1, n) - 1;
    int end = input_int("Введите номер строки, с которой надо окончить удалять: ", start + 1, n) - 1;
    for (int i = start; i <= end; i++)
    {
        if (count < text[i].size()) // text[i].length()
        {
            text[i].erase(0, count);
        }
        else
        {
            text[i].erase();
        }
    }
}

//***********************************************************************************************

void file_read(string* text, int &n)
{
    string filename = file_open_read("Введите название файла: ");
    ifstream file;
    file.open(filename);
    n = 0;
    while (!file.eof())
    {
        getline(file, text[n++]);
    }
    file.close();
}

void file_write(string* text, const int &n)
{
    string filename = file_open_write("Введите название файла: ");
    ofstream file;
    file.open(filename);
    for (int i = 0; i < n; i++)
    {
        file << *text << '\n';
        text++;
    }
    file.close();
}

//**************************************************************************************
