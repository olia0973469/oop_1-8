//////////////////////////////////////////////////////////////////////////////
// Goods.cpp
// файл реалізації – реалізація методів класу

#include "Goods.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // підключаємо бібліотеку, яка описує літерні потоки

using namespace std;

////////////////////////////////////////////////////////////
// class Goods
void Goods::Init(const string& n, int d, int q, int x, int y)
{
	name = n;
	date = d;
	quantity = q;
	money.Init(x, y);
}

void Goods::Read()
{
	cout << "Enter name: "; cin >> name;
	cout << "Enter date: "; cin >> date;
	cout << "Enter quantity: "; cin >> quantity;
	money.Read(); // використовуємо делегування
}

void Goods::Display()
{
	cout << "Name: " << name << endl;
	cout << "Date: " << date << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: " << money.toString() << endl;
	money.Display(); // використовуємо делегування
}

void Goods::ChangePrice(double newPriceHr, double newPriceKop)
{
	money.SetHr(newPriceHr);
	money.SetKop(newPriceKop);
}

void Goods::PlusQuantity(int amount)
{
	quantity += amount;
}

void Goods::MinusQuantity(int amount)
{
	quantity -= amount;
	if (quantity < 0)
		quantity = 0;
}

Goods::Money Goods::Cost() const
{
	double total = money.GetHr() + (money.GetKop() / 100);
	total *= quantity;

	Money result;
	result.SetHr(floor(total));
	result.SetKop((total - floor(total)) * 100);

	return result;
}

string Goods::toString()
{
	return Cost().toString();
}
////////////////////////////////////////////////////////////
// class Goods::Money
void Goods::Money::Display() const
{
	cout << endl;
	cout << " Hryvni = " << hr << endl;
	cout << " Kopijky = " << kop << endl;
}

void Goods::Money::Init(double x, double y)
{
	hr = x;
	kop = y;
}

void Goods::Money::Read()
{
	double x, y;
	cout << "Input money:" << endl;
	cout << " Hryvni = "; cin >> x;
	cout << " Kopijky = "; cin >> y;
	Init(x, y);
}

string Goods::Money::toString() const
{
	stringstream sout;
	sout << hr << " UAH, Kop ";
	sout << kop;
	return sout.str();
}

Goods::Money Goods::Money::Add(const Money& other) const
{
	Money result;
	result.hr = this->hr + other.hr;
	result.kop = this->kop + other.kop;

	if (result.kop >= 100)
	{
		result.hr += result.kop / 100;
		result.kop = 100;
	}

	return result;
}

Goods::Money Goods::Money::Sub(const Money& other) const
{
	Money result;
	result.hr = this->hr - other.hr;
	result.kop = this->kop - other.kop;

	if (result.kop >= 100)
	{
		result.hr -= result.kop / 100;
		result.kop = 100;
	}

	return result;
}

double Goods::Money::Divide(const Money& other) const
{
	if (other.hr == 0 || other.kop == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return 0.0;
	}

	double totalThis = hr - (static_cast<double>(kop) / 100);
	double totalOther = other.hr - (static_cast<double>(other.kop) / 100);

	return totalThis / totalOther;
}

Goods::Money Goods::Money::DivideFraction(double division)
{
	if (division == 0.0)
	{
		cerr << "Error.\n";
		exit(1);
	}
	Money result;
	result.hr = this->hr / division;
	result.kop = this->kop / division;
	return result;
}

Goods::Money Goods::Money::MultFraction(double mult)
{
	Money result;
	result.hr = this->hr * mult;
	result.kop = this->kop * mult;
	return result;
}

bool Goods::Money::operator==(const Money& other) const
{
	return (hr == other.hr) && (kop == other.kop);
}

bool Goods::Money::operator!=(const Money& other) const
{
	return !(*this == other);
}

bool Goods::Money::operator<(const Money& other) const
{
	double totalThis = hr + (static_cast<double>(kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);
	return totalThis < totalOther;
}

bool Goods::Money::operator<=(const Money& other) const
{
	return (*this < other) || (*this == other);
}

bool Goods::Money::operator>(const Money& other) const
{
	return !(*this <= other);
}

bool Goods::Money::operator>=(const Money& other) const
{
	return !(*this < other);
}

void Goods::Money::Discount(double percentage)
{
	double discount = (percentage / 100) * (hr + (static_cast<double>(kop) / 100));
	hr -= static_cast<int>(discount);
	kop -= static_cast<int>((discount - floor(discount)) * 100);

	while (kop < 0)
	{
		hr--;
		kop += 100;
	}

	if (hr < 0)
	{
		cerr << "Error: Negative price after discount!" << endl;
		exit(1);
	}
}
