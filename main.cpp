#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout << "Введите пользователя: "; cin >> username;
    cout << "Введите пароль: "; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Здравствуйте, пожалуйста, зарегистрируйтесь или войдите под своим логином" << endl;
    
    int choice;
    cout << "1: Регистрация\n2: Логин\nВаш выбор: "; cin >> choice;
    
    switch (choice)
    {
        case 1:
        {
        string username, password;

        cout << "Введите свой логин: "; cin >> username;
        cout << "Введите свой пароль: "; cin >> username;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
        }
        case 2:
        {
        bool status = IsLoggedIn();
        
            if (!status)
            {
                cout << "Неправильный логин!" << endl;
                system("PAUSE");
                return 0;
            }
            else
            {
                cout << "Успешный вход!" << endl;
                system("PAUSE");
                return 1;
            }
        }    
    }
    
}
