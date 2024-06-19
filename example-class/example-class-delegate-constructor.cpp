#include "example-class-delegate-constructor.h"
#include <iostream>

namespace ExampleClassDelegateConstructor {
	class A {
		int m_i;
		int m_j;
	public:
		A(int i): A(i, 0) {	//这个就是委托构造函数。委托构造函数调用同一类中的其他构造函数，以完成部分初始化工作。
			std::cout << "委托构造调用" << std::endl;
		}
		A(int i, int j): m_i(i), m_j(j) {

		}
	};
}

void runExampleClassDelegateConstructor01(void) {
	ExampleClassDelegateConstructor::A a{2};
}