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
	//������һ��
	A* a1 = new A;
	A* a2 = new A();
	a1->show();
	a2->show();
}

//operator new
class B {
public:
	//�����������������ô��������Ҫnew(xxx) B;�����xxx����operator new�ĵڶ�������
	//placement new����ͨ����дoperator newʵ�ֵ�
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