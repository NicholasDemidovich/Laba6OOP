
#pragma once
#include "stdio.h"
#include <iostream>
#include <fstream>

bool verificationAdmin()
{
	using namespace std;
	int counter = 0;
	ifstream in;
	char* password = new char[30];
	char* login = new char[30];
	char* passwordTmp = new char[30];
	char* loginTmp = new char[30];
	while (true)
	{
		system("cls");
		cout << "\nПоптыка номер: " << counter + 1;
		cout << "\nВведите логин:  ";
		cin >> login;
		cout << "\nВведите пароль:  ";
		cin >> password;
		in.open("AdminFile.txt", ios::in);
		if (!in)
		{
			cerr << "\nОшибка открытия файла!" << endl;
			system("pause");
			return false;
		}
		in >> loginTmp >> passwordTmp;
		in.close();
		if (strcmp(login, loginTmp) == 0 && strcmp(password, passwordTmp) == 0)
		{
			cout << "\nАвторизация выполнена успешно!" << endl;
			system("pause");
			return true;
		}
		counter++;
		if (counter == 3) { return false; }
	}

}