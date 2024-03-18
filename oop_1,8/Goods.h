//////////////////////////////////////////////////////////////////////////////
// Goods.h
// заголовний файл Ц визначенн€ класу
#pragma once
#include<string>
using namespace std;
class Goods
{
	string name;
	int price, quantity, no, date;
public:
	class Money
	{
		double hr, kop;
	public:
		double GetHr() const { return hr; }
		double GetKop() const { return kop; }
		void SetHr(double value) { hr = value; }
		void SetKop(double value) { kop = value; }
		void Init(double, double);
		void Read();
		void Display() const;
		string toString() const;
		Money Add(const Money& other) const;
		Money Sub(const Money& other) const;
		double Divide(const Money& other) const;
		Money DivideFraction(double division);
		Money MultFraction(double mult);
		bool operator==(const Money& other) const;
		bool operator!=(const Money& other) const;
		bool operator<(const Money& other) const;
		bool operator<=(const Money& other) const;
		bool operator>(const Money& other) const;
		bool operator>=(const Money& other) const;
		void Discount(double percentage);
	};
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	Money GetMoney() const { return money; }
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}
	void Init(const string&, int, int, int, int);
	void Read();
	void Display();
	string toString();
	void ChangePrice(double newPriceHr, double newPriceKop);
	void PlusQuantity(int amount);
	void MinusQuantity(int amount);
	Money Cost() const;
private:
	Money money;
};
