#include "example-class-inheriting-constructor.h"
#include <iostream>

namespace ExampleClassInheritingConstructor {
	class Base {
		int mI;
	public:
		Base() {
			std::cout << "Base ctor called" << std::endl;
		}
		Base(int i): mI(i) {
			std::cout << "Base with param ctor called" << std::endl;
		}
	};

	class Derived : Base {
	public:
		Derived() {
			std::cout << "Derived ctor called" << std::endl;
		}
		Derived(int i): Base(i) {	//如果这里没有指定基类构造，那么就会调用默认的Base ctor
			std::cout << "Derived with param ctor called" << std::endl;
		}
	};

	class Derived2 : Base {//一般而言，当派生类未声明新数据成员或构造函数时，最好使用继承构造函数
	public:
		using Base::Base;	//从基类继承所有构造
	};
}

void runExampleClassInheritingConstructor01(void) {
	ExampleClassInheritingConstructor::Derived d1;
	ExampleClassInheritingConstructor::Derived d2(1);
}

void runExampleClassInheritingConstructor02(void) {
	ExampleClassInheritingConstructor::Derived2 d1;
	ExampleClassInheritingConstructor::Derived2 d2(1);
}
