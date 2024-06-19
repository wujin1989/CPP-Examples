#include "example-class-copy-constructor.h"
#include <iostream>

namespace ExampleClassCopyConstructor {
	class A {
		int mA;
	public:
		A(){}
		A(int a): mA(a) {}
		A(const A& a) : mA(a.mA) {
			std::cout << "�������챻����" << std::endl;
		}
		A& operator=(A& a) {
			std::cout << "��ֵ������������" << std::endl;
			mA = a.mA;
			return *this;
		}
	};
}

void runExampleClassCopyConstructor01(void) {
	ExampleClassCopyConstructor::A a1{10};
	ExampleClassCopyConstructor::A a2 = a1;	//�������챻����
	a2 = a1;	//��ֵ������������

	//�������캯���ǵ�һ���¶�����Ҫ����ʼ��ʱ
	//��ֵ�������������ж��󱻸�����ֵʱ���õ�
}