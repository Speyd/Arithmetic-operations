#include <iostream>
using namespace std;
class Fraction {
private:
	double scratcher;
	double denominator;
public:
	~Fraction() { cout << "Программа закончила работу!"; }
	void SetScratcher(double new_scratcher);
	int SetDenominator(double new_denominator, char choice);
	double Addition() { return scratcher + denominator; }
	double Subtraction() { return scratcher - denominator; }
	double Multiplication() { return scratcher * denominator; }
	double Division() { return scratcher / denominator; }
	int Remainder_Division() { return int(scratcher) % int(denominator); }
};
