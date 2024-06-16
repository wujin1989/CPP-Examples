#include "example-base-new.h"
#include <iostream>

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
void runExampleBaseNew01(void) {
	//这两个一样
	A* a1 = new A;
	A* a2 = new A();
	a1->show();
	a2->show();
}

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

void runExampleBaseNew02(void) {
	B* b = new B();
	delete b;
}