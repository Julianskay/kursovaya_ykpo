#include "stdafx.h"
#include "CppUnitTest.h"
#include "../kurs_ykpo/Source.cpp"
const int n1 = 1;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool string_test (string a, int b) {

	if (a[0]<-64 || a[0]>-1) {
		return 0;
	}
	else return 1;
}
bool CompareTwoElem (int a, int b)
{
	if (a == b)
	{
		return true;
	}
	else {
		return false;
	}
}

namespace UnitTest1
{
	TEST_CLASS (UnitTest1)
	{
	public:

		TEST_METHOD (GoodInput)
		{

			int ji = 7;
			Assert::IsTrue (inputch (ji));
		}

		TEST_METHOD (FalseInput)
		{
			int ji1 = -9;
			Assert::IsFalse (inputch (ji1));

		}

		TEST_METHOD (GoodWay)
		{
			int a = 1, b = 10;
			Assert::IsTrue (checkWay (a, b));
		}

		TEST_METHOD (FalseWay_ab)
		{
			int a = -5, b = 15;
			Assert::IsFalse (checkWay (a, b));
		}

		TEST_METHOD (FalseWay_b)
		{
			int a = 5, b = -40;
			Assert::IsFalse (checkWay (a, b));
		}

		TEST_METHOD (FalseWay_a)
		{
			int a = -5, b = 10;
			Assert::IsFalse (checkWay (a, b));;
		}

		/*TEST_METHOD (FalseWay)
		{
		Assert::IsFalse(step (5, 10, 1));
		}*/

		TEST_METHOD (String_input)
		{
			string c = "coolstring";
			bool a = string_test (c, n1);
		}

		/*	TEST_METHOD (Compare)
		{
		int a, b;
		a = 5; b = a;
		Assert::AreEqual<int> (a, b);
		}

		TEST_METHOD (NOTCompare)
		{
		int a, b;
		a = 1; b = 7;
		Assert::AreNotEqual<int> (a, b);
		}*/

		TEST_METHOD (GOODSearching)
		{
			Assert::IsTrue (foundWay (true));
		}

		TEST_METHOD (FALSESearching)
		{
			Assert::IsFalse (foundWay (false));
		}
	};
}
