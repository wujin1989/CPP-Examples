#include "example-class-move-constructor.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace ExampleClassMoveConstructor {
	class A {
	public:
		A(){}
		A(A&& a) {
			std::cout << "移动构造调用" << std::endl;
		}
		A(const A& a) {
			std::cout << "拷贝构造调用" << std::endl;
		}
		A& operator=(A a) {
			std::cout << "赋值操作符调用" << std::endl;
			return *this;
		}
		void toString(void) {
			std::cout << mStr << std::endl;
		}
		std::string mStr = "hello";
	};
	A getA(bool change) {
		A a;
		if (change) {
			a.mStr = "world";
		}
		return a;
	}
	class B {
	public:
		B(){}
		B(const B& b) {
			std::cout << "拷贝构造调用" << std::endl;
		}
	};
	B getB(void) {
		B b;
		return b;
	}
	
	class MemoryBlock {
	public:
		MemoryBlock(int size)
			: mSize(size)
			, mData(new int[size])
		{
		}
		MemoryBlock(MemoryBlock&& mb) {
			/*mSize = mb.mSize;
			mData = mb.mData;

			mb.mSize = 0;
			mb.mData = nullptr;*/

			//如果为你的类同时提供了移动构造函数和移动赋值运算符，则可以编写移动构造函数来调
			//用移动赋值运算符，从而消除冗余代码。
			*this = std::move(mb);
		}
		MemoryBlock& operator=(MemoryBlock&& mb) {
			if (this != &mb) {
				delete[] mData;

				mSize = mb.mSize;
				mData = mb.mData;

				mb.mSize = 0;
				mb.mData = nullptr;
			}
			return *this;
		}
	private:
		int mSize = 0;
		int* mData = nullptr;
	};
}

void runExampleClassMoveConstructor01(void) {
	//这里没有发生拷贝和移动构造的原因是编译器的"copy elision"优化机制。
	ExampleClassMoveConstructor::getA(false).toString();
	ExampleClassMoveConstructor::A a1(ExampleClassMoveConstructor::getA(true));
	a1.toString();

	std::cout << "-------------------------------" << std::endl;
	//所以，为了没有歧义，尽量明确用移动构造，如下
	ExampleClassMoveConstructor::A a2(std::move(ExampleClassMoveConstructor::getA(true)));
	a2.toString();
}

void runExampleClassMoveConstructor02(void) {
	//如果没有显式的移动构造函数，则原本使用移动构造函数的操作会改用复制构造函数。
	ExampleClassMoveConstructor::B b(std::move(ExampleClassMoveConstructor::getB()));
}

void runExampleClassMoveConstructor03(void) {
	
	ExampleClassMoveConstructor::MemoryBlock mb1(10);
	ExampleClassMoveConstructor::MemoryBlock mb2(20);

	mb1 = std::move(mb2);
}