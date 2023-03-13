#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	TEST_CLASS(UnitTests) {
	public:
		
		TEST_METHOD(DefaultConstuctorTest) {
			Point p;
			Assert::AreEqual(0.0, p.getX());
			Assert::AreEqual(0.0, p.getY());
		}

		TEST_METHOD(SimpleConstructor) { // getter проверяется здесь же
			Point p = Point(3, 4);
			Assert::AreEqual(3, p.getX(), 0.0000001);
			Assert::AreEqual(4, p.getY(), 0.0000001);
		}

		TEST_METHOD(AddToTest) {
			Point p1 = Point(3, 4);
			Point p2 = Point(4, 3);
			p1.add(p2);
			Assert::AreEqual(7, p1.getX(), 0.0000001);
			Assert::AreEqual(7, p1.getY(), 0.0000001);
		}

		TEST_METHOD(SetPointTest) {
			Point p = Point(3, 4);
			p.setPoint(4, 5);
			Assert::AreEqual(4, p.getX(), 0.0000001);
			Assert::AreEqual(5, p.getY(), 0.0000001);
		}

		TEST_METHOD(SetterTest) {
			Point p = Point(3, 4);
			p.setX(5); p.setY(6);
			Assert::AreEqual(5, p.getX(), 0.0000001);
			Assert::AreEqual(6, p.getY(), 0.0000001);
		}

		TEST_METHOD(ShiftTest) {
			Point p = Point(3, 4);
			p.shiftX(3); p.shiftY(4);
			Assert::AreEqual(6, p.getX(), 0.0000001);
			Assert::AreEqual(8, p.getY(), 0.0000001);
		}

		TEST_METHOD(EqualTest) {
			Point p1 = Point(3.034, 4.444);
			Point p2 = Point(3.034, 4.444);
			Assert::IsTrue(p1.isEqual(p2));

			Point p3 = Point(3.034, 4.444);
			Point p4 = Point(3.035, 4.444);
			Assert::IsFalse(p3.isEqual(p4));
		}

		TEST_METHOD(DistanceToTest) {
			Point p1 = Point(0, 4);
			Point p2 = Point(2, 4);
			Assert::AreEqual(2, p1.distanceTo(p2), 0.00000001);
		}

		TEST_METHOD(Add1Test) {
			Point p1 = Point(3, 4);
			Point p2 = Point(4, 3);
			Point result = Point(7, 7);
			Assert::IsTrue(result.isEqual(add1(p1, p2)));
		}

		TEST_METHOD(Add2Test) {
			const Point p1 = Point(3, 4);
			const Point p2 = Point(4, 3);
			Point result = Point(7, 7);
			Assert::IsTrue(result.isEqual(add2(p1, p2)));
		}

	};
}
