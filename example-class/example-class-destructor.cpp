#include "example-class-destructor.h"
#include <iostream>

namespace ExampleClassDestructor {
	class A {
	public:
		~A() {
			std::cout << "~A() called" << std::endl;
		}
		virtual void print(void) {
			std::cout << "A::print called" << std::endl;
		}
	};
	class B: public A {
		char* data;
	public:
		B(){}
		B(int sz)
			:data(new char[sz])
		{
		}
		~B() {
			delete[] data;
			std::cout << "~B() called" << std::endl;
		}
		void print(void) {
			std::cout << "B::print called" << std::endl;
		}
	};
	class D {
	public:
		virtual ~D() {
			std::cout << "~D() called" << std::endl;
		}
		
	};
	class C : public D {
		char* data;
	public:
		C() {}
		C(int sz)
			:data(new char[sz])
		{
		}
		//�����virtual���Լӣ�Ҳ���Բ��ӡ�
		//��Ϊ����������������д����ʱ��ʹ�� virtual �ؼ��֣��������Ǳ���ģ��麯������дʼ��������ġ�
		virtual ~C() {	

			delete[] data;
			std::cout << "~C() called" << std::endl;
		}
	};
	class E:public A {
	public:
		virtual void print(void) {
			std::cout << "E::print called" << std::endl;
		}
	};
}

void runExampleClassDestructor01(void) {
	ExampleClassDestructor::A* a = new ExampleClassDestructor::B();
	a->print();
}

void runExampleClassDestructor02(void) {
	ExampleClassDestructor::A* a = new ExampleClassDestructor::B(128);
	delete a;	//����ֻ�����~A(),�������~B(),����B��dataû���ͷ�

	//��Ϳ��ԣ���ΪD����������virtual����
	ExampleClassDestructor::D* d = new ExampleClassDestructor::C(128);
	delete d;

	//���ۣ������е���������Ҫ��virtual��ֻ��Ӧ���ڷǾ�̬���Ա������ ����ʾ�����ĵ��ð󶨽��Ƴٵ�����ʱ
}

void runExampleClassDestructor03(void) {
	std::cout << "---------------------" << std::endl;

	ExampleClassDestructor::E e;
	e.print();

	std::cout << "---------------------" << std::endl;
	ExampleClassDestructor::E* e1 = new ExampleClassDestructor::E{};
	e1->print();

	std::cout << "---------------------" << std::endl;
	ExampleClassDestructor::A* a = new ExampleClassDestructor::E{};
	a->print();
	a->ExampleClassDestructor::A::print();//ͨ��ʹ�÷�Χ��������� ( :: ) ��ʽ�޶����������������麯�����û��ơ�

	std::cout << "---------------------" << std::endl;
}