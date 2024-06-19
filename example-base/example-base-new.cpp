#include "example-base-new.h"
#include <iostream>

namespace ExampleBaseNew {
	class A {
	public:
		/*A(int d): data(d) {

		}*/
		void show(void) {
			std::cout << "hello" << std::endl;
		}
	private:
		int data;
	};

	//operator new
	class B {
	public:
		//如果有两个参数，那么创建对象要new(xxx) B;这里的xxx传给operator new的第二个参数
		//placement new就是通过重写operator new实现的
		void* operator new(size_t objSize) {
			std::cout << "operator new called" << std::endl;

			void* pB = malloc(objSize);
			if (pB) {
				return nullptr;
			}
			return pB;
		}
		void operator delete(void* mem) {
			std::cout << "operator delete called" << std::endl;
			if (mem) {
				free(mem);
				mem = nullptr;
			}
		}
	private:
		int data;
	};
}
void runExampleBaseNew01(void) {
	//这两个一样
	ExampleBaseNew::A* a1 = new ExampleBaseNew::A;
	ExampleBaseNew::A* a2 = new ExampleBaseNew::A();
	a1->show();
	a2->show();
}

void runExampleBaseNew02(void) {
	ExampleBaseNew::B* b = new ExampleBaseNew::B();
	delete b;
}