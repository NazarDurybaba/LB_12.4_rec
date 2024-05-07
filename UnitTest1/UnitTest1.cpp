#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestAllElementsInList)
		{
			// Arrange
			CircularLinkedList L1, L2;

			// Додавання елементів у списки L1 та L2
			L1.addElement(1);
			L1.addElement(2);
			L1.addElement(3);

			L2.addElement(3);
			L2.addElement(2);
			L2.addElement(1);

			// Act
			bool result = L1.allElementsInList(L2);

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(TestAllElementsNotInList)
		{
			// Arrange
			CircularLinkedList L1, L2;

			// Додавання елементів у списки L1 та L2
			L1.addElement(1);
			L1.addElement(2);
			L1.addElement(3);

			L2.addElement(4);
			L2.addElement(5);
			L2.addElement(6);

			// Act
			bool result = L1.allElementsInList(L2);

			// Assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(TestEmptyList)
		{
			// Arrange
			CircularLinkedList L1, L2;

			// Act
			bool result = L1.allElementsInList(L2);

			// Assert
			Assert::IsTrue(result);
		}
	};
}
