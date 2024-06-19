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
}
void runExampleBaseNew01(void) {
	//������һ��
	ExampleBaseNew::A* a1 = new ExampleBaseNew::A;
	ExampleBaseNew::A* a2 = new ExampleBaseNew::A();
	a1->show();
	a2->show();
}

void runExampleBaseNew02(void) {
	ExampleBaseNew::B* b = new ExampleBaseNew::B();
	delete b;
}