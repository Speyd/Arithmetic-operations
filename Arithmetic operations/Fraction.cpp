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
void Fraction::SetScratcher(double new_scratcher) {
	scratcher = new_scratcher;
}
int Fraction::SetDenominator(double new_denominator, char choice) {
	if(choice == 4 && scratcher == 0 && new_denominator == 0) { cout << "Результат не определен"; return 0; }
	else if (choice == 4 && new_denominator == 0) { cout << "Делить на ноль нельзя!"; return 0; }
	denominator = new_denominator;
	return 1;
}