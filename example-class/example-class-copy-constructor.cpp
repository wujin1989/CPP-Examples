#include "example-class-copy-constructor.h"
#include <iostream>

namespace ExampleClassCopyConstructor {
	class A {
		int mA;
	public:
		A(){}
		A(int a): mA(a) {}
		A(const A& a) : mA(a.mA) {
			std::cout << "拷贝构造被调用" << std::endl;
		}
		A& operator=(A& a) {
			std::cout << "赋值操作符被调用" << std::endl;
			mA = a.mA;
			return *this;
		}
	};
}

void runExampleClassCopyConstructor01(void) {
	ExampleClassCopyConstructor::A a1{10};
	ExampleClassCopyConstructor::A a2 = a1;	//拷贝构造被调用
	a2 = a1;	//赋值操作符被调用

	//拷贝构造函数是当一个新对象需要被初始化时
	//赋值操作符是在已有对象被赋予新值时调用的
}