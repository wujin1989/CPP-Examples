#include "example-class-delegate-constructor.h"
#include <iostream>

namespace ExampleClassDelegateConstructor {
	class A {
		int m_i;
		int m_j;
	public:
		A(int i): A(i, 0) {	//�������ί�й��캯����ί�й��캯������ͬһ���е��������캯��������ɲ��ֳ�ʼ��������
			std::cout << "ί�й������" << std::endl;
		}
		A(int i, int j): m_i(i), m_j(j) {

		}
	};
}

void runExampleClassDelegateConstructor01(void) {
	ExampleClassDelegateConstructor::A a{2};
}