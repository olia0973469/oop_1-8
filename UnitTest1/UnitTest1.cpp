#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_1,8/Goods.h"
#include "../oop_1,8/Goods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Goods::Money initialPrice;
			initialPrice.Init(10, 50);
			Goods goods;
			goods.SetMoney(initialPrice);

			goods.ChangePrice(5, 25); 

			Assert::AreEqual(5.0, goods.GetMoney().GetHr());
			Assert::AreEqual(25.0, goods.GetMoney().GetKop());
		}
	};
}
