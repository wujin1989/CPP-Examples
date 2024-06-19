#include "example-base-uniform_initialization.h"
#include <iostream>
#include <initializer_list>

namespace ExampleBaseUniformInitialization {
	class A {
	public:
		int i;
		std::string s;
		double d;

		void toString(void) {
			std::cout << i << ", " << s << ", " << d << std::endl;
		}
	};

	class B {
	public:
		int i;
		std::string s;
		double d;
		B(std::string p1, int p2, double p3): s(p1), i(p2), d(p3) {

		}
	};
}

void runExampleBaseUniformInitialization01(void) {
	//ExampleBaseUniformInitialization::A a3{ 2, 2.0 }; //������������
	//ExampleBaseUniformInitialization::A a4{ "hey", 2, 2.0 }; //û�й��캯������ʼ���б��ʼ�����ձ���������˳��
	ExampleBaseUniformInitialization::A a1{ 1, "hello", 1.0 };
	ExampleBaseUniformInitialization::A a2{ 2, "world" };

	a1.toString();
	a2.toString();
}

void runExampleBaseUniformInitialization02(void) {
	//ExampleBaseUniformInitialization::B b1{ 1, "hello", 1.0 }; //�й��캯������ʼ���б��ʼ������ctor�Ĳ���˳��
	ExampleBaseUniformInitialization::B b2{ "hello", 1, 1.0 };
}

void runExampleBaseUniformInitialization03(void) {
	std::initializer_list<int> ilist{ 3, 2, 1, 4 };
	std::cout << *ilist.begin() << std::endl;
	std::cout << *ilist.end() << std::endl; //����ָ�� initializer_list �����һ��Ԫ��֮���Ԫ�ص�ָ�롣
	std::cout << ilist.size() << std::endl;

	std::initializer_list<int> ilist2(ilist.begin() + 1, ilist.end());	//��ʾ���ù��캯��
	std::cout << *ilist2.begin() << std::endl;
	std::cout << *ilist2.end() << std::endl;
	std::cout << ilist2.size() << std::endl;
	//initializer_list ��Ԫ����ֻ����
}