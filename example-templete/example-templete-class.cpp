#include "example-templete-class.h"
#include <iostream>
#include <string>

namespace ExampleTempleteClass {
	class B {
	public:
		class C {
		public:
			std::string str;
		};
	};

	template <typename T>
	class A {
	public:
		typename T::C c;    //这里是依赖模板类型参数的类型，所以需要用typename。
		A(T& t) {
			c.str = "hello";
		}
		void show(void) {
			std::cout << c.str << std::endl;
		}
	};

	template <typename T, typename U>
	class D {
	public:
		T calcMin(T m, U n);
	};

	template <typename T, typename U>
	T D<T, U>::calcMin(T m, U n) {	//模板成员函数
		return m < n ? m : n;
	}

	template <typename T>
	class D<int, T> {	//模板部分特化
	public:
		T calcMin(int m, T n);
	};

	template <typename T>
	T D<int, T>::calcMin(int m, T n) {
		return m < n ? m : n;
	}

	/////////////模板友元
	template <typename T>
	class E {
	public:
		E(int sz) : size(sz) {
			data = new T[size];
			memset(data, 0, sizeof(T) * size);
		}
		E(const E& e) {
			size = e.size;
			data = new T[size];
			memcpy(data, e.data, size);
		}
		~E() {
			if (data != nullptr) {
				delete[] data;
				data = nullptr;
			}
		}
		T& operator[](int i) {
			return *(data + i);
		}
		int length(void) {
			return size;
		}
		void print(void) {
			for (int i = 0; i < size; i++) {
				std::cout << *(data + i) << " ";
			}
			std::cout << std::endl;
		}
		E* combine(E& e) {
			T* tmpData = new T[size];
			int tmpSize = size;
			memcpy(tmpData, data, size);

			if (data != nullptr) {
				delete[] data;
				data = nullptr;
			}
			size = e.size + size;
			data = new T[size];

			memcpy(data, tmpData, tmpSize);

			if (tmpData != nullptr) {
				delete[] tmpData;
				tmpData = nullptr;
			}
			memcpy(data + tmpSize, e.data, e.size);
			return this;
		}
		template <typename T>
		friend E<T>* combine2(E<T>& e1, E<T>& e2);	//模板友元
	private:
		T* data;
		int size;
	};

	template <typename T>
	E<T>* combine2(E<T>& e1, E<T>& e2) {
		E<T>* tmp = new E<T>(e1.size + e2.size);
		for (int i = 0; i < e1.length(); i++) {
			(*tmp)[i] = e1[i];
		}
		for (int i = 0; i < e2.length(); i++) {
			(*tmp)[i + e1.size] = e2[i];
		}
		return tmp;
	}
}

void runExampleTempleteClass01(void) {
	ExampleTempleteClass::B b;
	ExampleTempleteClass::A<ExampleTempleteClass::B> a(b);
	a.show();
}

void runExampleTempleteClass02(void) {
	ExampleTempleteClass::D<double, double> d;
	std::cout << d.calcMin(2.0, 4.0) << std::endl;

	ExampleTempleteClass::D<int, int> d2;
	std::cout << d2.calcMin(4, 6) << std::endl;
}

void runExampleTempleteClass03(void) {
	ExampleTempleteClass::E<char> e1(26);
	for (int i = 0; i < e1.length(); i++) {
		e1[i] = 'a' + i;
	}
	e1.print();

	ExampleTempleteClass::E<char> e2(26);
	for (int i = 0; i < e2.length(); i++) {
		e2[i] = 'A' + i;
	}
	e2.print();

	//下面两个不要同时运行。
	//e1.combine(e2)->print();   //成员函数
	combine2(e1, e2)->print(); //友元函数
}