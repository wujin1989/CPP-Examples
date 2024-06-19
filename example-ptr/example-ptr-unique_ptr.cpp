#include "example-ptr-unique_ptr.h"
#include <memory>
#include <iostream>

namespace ExamplePtrUniquePtr {
	class Widget0 {
	public:
		Widget0(int size) {
			data = new int[size];
		}
		~Widget0() {
			if (data) {
				std::cout << "~Widget0 called" << std::endl;
				delete[] data;
			}
		}
		void doSomething(void) {}
	private:
		int* data = nullptr;
	};
	class Widget {
	private:
		std::unique_ptr<int[]> data;
	public:
		Widget(int size) {
			data = std::make_unique<int[]>(size);
		}
		void doSomething(void) {}
	};

	//通过下面这个例子，看上面的智能指针是不是一回事
	class B {
	public:
		~B() {
			std::cout << "~B called" << std::endl;
		}
	};

	class A {
	public:
		~A() {
			std::cout << "~A called" << std::endl;
		}
	private:
		B b;
	};
}

void runExamplePtrUniquePtr01(void) {
	ExamplePtrUniquePtr::Widget w(10);
	w.doSomething();
}

void runExamplePtrUniquePtr02(void) {
	ExamplePtrUniquePtr::A a;
}

void runExamplePtrUniquePtr03(void) {
	ExamplePtrUniquePtr::Widget0 w(10);
	w.doSomething();
}