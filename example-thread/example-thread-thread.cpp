#include "example-thread-thread.h"
#include <thread>
#include <iostream>

namespace ExampleThreadThread {
	void threadFunc01(void) {
		std::cout << "threadFunc01 running..." << std::endl;
	}
	void threadFunc02(void) {
		std::cout << "threadFunc02 running..." << std::endl;
	}
	class A {
	public:
		void threadFunc03(void) {
			std::cout << "A::threadFunc03 running..." << std::endl;
		}
		void operator()(void) {
			std::cout << "A::operator(void) running..." << std::endl;
		}
	};
}

void runExampleThreadThread01(void) {
	//����ȫ�ֺ����;�̬����������&ȡ������ַ��Ҳ���Բ��á�
	//���ڳ�Ա��������Ҫ&
	std::thread t1(ExampleThreadThread::threadFunc01);
	std::thread t2(&ExampleThreadThread::threadFunc02);
	ExampleThreadThread::A a;
	std::thread t3(&ExampleThreadThread::A::threadFunc03, &a);
	std::thread t4(std::move(t2));
	//��C++�У��κ������� operator() ����Ķ��󶼿�������һ��������
	std::thread t5(a);
	t1.join();
	//t2.join(); ���ﲻ��Ҫ�ˣ���Ϊt4�����t2
	t3.join();
	t4.join();
	t5.join();
}