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
		Derived(int i): Base(i) {	//�������û��ָ�����๹�죬��ô�ͻ����Ĭ�ϵ�Base ctor
			std::cout << "Derived with param ctor called" << std::endl;
		}
	};

	class Derived2 : Base {//һ����ԣ���������δ���������ݳ�Ա���캯��ʱ�����ʹ�ü̳й��캯��
	public:
		using Base::Base;	//�ӻ���̳����й���
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
