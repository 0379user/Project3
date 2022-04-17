#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/system.h"
#include "../Project3/mouseevent.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(1 == 1);
		}
		TEST_METHOD(TestMethod2)
		{
			Core::System s();
			Core::MouseButtonPressedEvent e(3);
			//Assert::IsTrue(1 == 2);
		}
	};
}
