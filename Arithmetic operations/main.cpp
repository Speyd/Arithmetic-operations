#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
Fraction fraction;
#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tАрифметические действия" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "\nНажмите enter что-бы продолжить: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion
int main() {
	setlocale(LC_ALL, "Rus");
	int choice = 1,num;
	do {
		ClearScrean();
		cout << "Введите первое число: "; cin >> num;
		fraction.SetScratcher(num);
		do {
			ClearScrean();
			cout << "Что будем делать с числами?:\n[1] - Слаживать\n[2] - Вычитать\n[3] - Умножать\n[4] - Делить\n[5] - Узнать остаток от деления" << endl;
			if (choice >= 1 && choice <= 5)cout << "Ваш выбор: ";
			else cout << "Нету такого выбора!\nВведите ваш выбор снова: ";
			cin >> choice;
		} while (choice < 1 || choice > 5);
		do {
			ClearScrean();
			cout << "Введите второе число: "; cin >> num;
			if (fraction.SetDenominator(num, choice) == 1)break;
			else Enter();
		} while (true);
		ClearScrean();
		switch (choice) {
			case 1:cout<<"Результат сложения: " << fraction.Addition(); break;
			case 2:cout << "Результат вычитания: " << fraction.Subtraction(); break;
			case 3:cout << "Результат умножения: " << fraction.Multiplication(); break;
			case 4:cout << "Результат деления: " << fraction.Division(); break;
			case 5:cout << "Результат остатка от деления(примерно): " << fraction.Remainder_Division(); break;
		}
		Enter();
		choice = 1;
		do {
			ClearScrean();
			cout << "Хотите ещё провести какие-то операции из числами?\n[1] - Да    |    [2] - Нет" << endl;
			if (choice >= 1 && choice <= 2)cout << "Ваш выбор: ";
			else cout << "Нету такого выбора!\nВведите ваш выбор снова: ";
			cin >> choice;
		} while (choice < 1 || choice > 2);
	} while (choice != 2);
	return 0;
}