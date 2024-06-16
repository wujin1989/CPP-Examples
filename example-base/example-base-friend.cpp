#include "example-base-friend.h"
#include <iostream>

class A {
private:
	int aa;
public:
	A(int n) : aa(n){
	}
	friend void showA(A& a);
};

static void showA(A& a) {	//友元函数
	std::cout << a.aa << std::endl;
}

void runExampleBaseFriend01(void) {
	A a(2);
	showA(a);
}

//////////////////友元类

class C {
private:
	int data;
public:
	C(int d): data(d) {

	}
	void showData(void) {
		std::cout << data << std::endl;
	}
	friend class D;
};

class D {
public:
	void changeData(C& c, int d) {
		c.data = d;
	}
	void showData(C& c) {
		std::cout << c.data << std::endl;
	}
};

void runExampleBaseFriend02(void) {
	C c(100);
	c.showData();

	D d;
	d.changeData(c, 200);
	d.showData(c);
}

