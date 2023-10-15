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
	cout << "\t�������������� ��������" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "\n������� enter ���-�� ����������: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion
int main() {
	setlocale(LC_ALL, "Rus");
	int choice = 1,num;
	do {
		ClearScrean();
		cout << "������� ������ �����: "; cin >> num;
		fraction.SetScratcher(num);
		do {
			ClearScrean();
			cout << "��� ����� ������ � �������?:\n[1] - ���������\n[2] - ��������\n[3] - ��������\n[4] - ������\n[5] - ������ ������� �� �������" << endl;
			if (choice >= 1 && choice <= 5)cout << "��� �����: ";
			else cout << "���� ������ ������!\n������� ��� ����� �����: ";
			cin >> choice;
		} while (choice < 1 || choice > 5);
		do {
			ClearScrean();
			cout << "������� ������ �����: "; cin >> num;
			if (fraction.SetDenominator(num, choice) == 1)break;
			else Enter();
		} while (true);
		ClearScrean();
		switch (choice) {
			case 1:cout<<"��������� ��������: " << fraction.Addition(); break;
			case 2:cout << "��������� ���������: " << fraction.Subtraction(); break;
			case 3:cout << "��������� ���������: " << fraction.Multiplication(); break;
			case 4:cout << "��������� �������: " << fraction.Division(); break;
			case 5:cout << "��������� ������� �� �������(��������): " << fraction.Remainder_Division(); break;
		}
		Enter();
		choice = 1;
		do {
			ClearScrean();
			cout << "������ ��� �������� �����-�� �������� �� �������?\n[1] - ��    |    [2] - ���" << endl;
			if (choice >= 1 && choice <= 2)cout << "��� �����: ";
			else cout << "���� ������ ������!\n������� ��� ����� �����: ";
			cin >> choice;
		} while (choice < 1 || choice > 2);
	} while (choice != 2);
	return 0;
}