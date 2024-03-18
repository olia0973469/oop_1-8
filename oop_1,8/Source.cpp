#include "Goods.h"
#include <iostream>
using namespace std;
int main()
{
	Goods z;
	Goods::Money t;
	string c;
	int n1 = 1, n2 = 5;
	cout << " Name = "; cin >> c;
	z.SetName(c);
	z.Read();
	cout << endl << "Output:" << endl;
	cout << " Name = " << z.GetName() << endl;
	z.Display();
	cout << " CangePrice = " << endl;
	z.ChangePrice(n1, n2);
	z.Display();
	t = z.Cost();
	t.Display();
	cout << "Cost = " << endl;  t.Display();
	return 0;
}
