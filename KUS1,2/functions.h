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
        cout << "�������������� ����� �������� �������� ������ " << min << endl << message << endl;
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
        cout << "�������������� ����� �������� �������� �� " << min << " �� " << max << endl << message << endl;
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
        cout << "����� ������ ������ 1 ������.\n";
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
        cout << "�� ������� ������� ����.\n";
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
        cout << "�� ������� ������� ����.\n";
    } while (true);
}

//**************************************************************************************

void output_char(string* text, const int &n)
{
    int start = input_int("������� ����� ������, � ������� ���� ������ �����", 1, n) - 1;
    int length = input_int("������� ����������� ����� ��� ������", 1, n - start);
    for (int i = start; i < start + length; i++)
    {
        cout << setw(5) << i + 1 << ". |" << text[i] << std::endl;
    }
}

//**************************************************************************************

void input_same_char(string* text, const int &n)
{
    char symbol = input_char("������� ������, ������� �� ������ �������� � ������: ");
    int count = input_int("������� ���������� ���������� ��������: ", 0);
    int start = input_int("������� ����� ������, � ������� ���� ������ �������: ", 1, n) - 1;
    int end = input_int("������� ����� ������, � ������� ���� �������� �������: ", start + 1, n) - 1;
    for (int i = start; i <= end; i++)
    {
        text[i].insert(0, count, symbol);
    }
}

void replace_char(string* text, const int &n)
{
    int count = input_int("������� ����� ����� �������� ���� �������� � ������: ", 0);
    string str = input_string("������� ������������������ ��������, �� ������� ����� ��������: ");
    int start = input_int("������� ����� ������, � ������� ���� ������ �������: ", 1, n) - 1;
    int end = input_int("������� ����� ������, � ������� ���� �������� �������: ", start + 1, n) - 1;
    for (int i = start; i <= end; i++)
    {
        text[i].replace(0, count, str);
    }
}

void char_remove(string* text, const int &n)
{
    int count = input_int("������� ��������� ��������, ������� ������ �������: ", 0);
    int start = input_int("������� ����� ������, � ������� ���� ������ �������: ", 1, n) - 1;
    int end = input_int("������� ����� ������, � ������� ���� �������� �������: ", start + 1, n) - 1;
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
    string filename = file_open_read("������� �������� �����: ");
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
    string filename = file_open_write("������� �������� �����: ");
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
