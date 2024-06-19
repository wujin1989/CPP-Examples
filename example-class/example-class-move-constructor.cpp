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
			std::cout << "�ƶ��������" << std::endl;
		}
		A(const A& a) {
			std::cout << "�����������" << std::endl;
		}
		A& operator=(A a) {
			std::cout << "��ֵ����������" << std::endl;
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
			std::cout << "�����������" << std::endl;
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

			//���Ϊ�����ͬʱ�ṩ���ƶ����캯�����ƶ���ֵ�����������Ա�д�ƶ����캯������
			//���ƶ���ֵ��������Ӷ�����������롣
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
	//����û�з����������ƶ������ԭ���Ǳ�������"copy elision"�Ż����ơ�
	ExampleClassMoveConstructor::getA(false).toString();
	ExampleClassMoveConstructor::A a1(ExampleClassMoveConstructor::getA(true));
	a1.toString();

	std::cout << "-------------------------------" << std::endl;
	//���ԣ�Ϊ��û�����壬������ȷ���ƶ����죬����
	ExampleClassMoveConstructor::A a2(std::move(ExampleClassMoveConstructor::getA(true)));
	a2.toString();
}

void runExampleClassMoveConstructor02(void) {
	//���û����ʽ���ƶ����캯������ԭ��ʹ���ƶ����캯���Ĳ�������ø��ƹ��캯����
	ExampleClassMoveConstructor::B b(std::move(ExampleClassMoveConstructor::getB()));
}

void runExampleClassMoveConstructor03(void) {
	
	ExampleClassMoveConstructor::MemoryBlock mb1(10);
	ExampleClassMoveConstructor::MemoryBlock mb2(20);

	mb1 = std::move(mb2);
}