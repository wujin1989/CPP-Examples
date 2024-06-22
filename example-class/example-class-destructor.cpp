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
		//这里的virtual可以加，也可以不加。
		//因为在派生类中声明重写函数时可使用 virtual 关键字，但它不是必需的；虚函数的重写始终是虚拟的。
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
	delete a;	//这里只会调用~A(),不会调用~B(),导致B的data没有释放

	//这就可以，因为D的析构用了virtual修饰
	ExampleClassDestructor::D* d = new ExampleClassDestructor::C(128);
	delete d;

	//结论：基类中的析构函数要加virtual，只能应用于非静态类成员函数。 它表示函数的调用绑定将推迟到运行时
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
	a->ExampleClassDestructor::A::print();//通过使用范围解析运算符 ( :: ) 显式限定函数名称来禁用虚函数调用机制。

	std::cout << "---------------------" << std::endl;
}