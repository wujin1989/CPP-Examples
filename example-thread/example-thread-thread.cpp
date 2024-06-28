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
	//对于全局函数和静态函数可以用&取函数地址，也可以不用。
	//对于成员函数必须要&
	std::thread t1(ExampleThreadThread::threadFunc01);
	std::thread t2(&ExampleThreadThread::threadFunc02);
	ExampleThreadThread::A a;
	std::thread t3(&ExampleThreadThread::A::threadFunc03, &a);
	std::thread t4(std::move(t2));
	//在C++中，任何重载了 operator() 的类的对象都可以像函数一样被调用
	std::thread t5(a);
	t1.join();
	//t2.join(); 这里不需要了，因为t4替代了t2
	t3.join();
	t4.join();
	t5.join();
}