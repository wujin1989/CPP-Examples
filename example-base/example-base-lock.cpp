#include "example-base-lock.h"
#include <iostream>
#include <thread>
#include <mutex>

namespace ExampleBaseLock {
	int n = 0;
	std::mutex mutex;
	void threadFunc01(void) {
		std::lock_guard<std::mutex> lock(mutex);
		for (int i = 0; i < 100; i++) {
			n++;
		}
	}
	void threadFunc02(void) {
		std::lock_guard<std::mutex> lock(mutex);
		for (int i = 0; i < 100; i++) {
			n++;
		}
	}
}

void runExampleBaseLock01(void) {
	std::thread t1(ExampleBaseLock::threadFunc01);
	std::thread t2(ExampleBaseLock::threadFunc02);

	t1.join();
	t2.join();
	std::cout << "n=" << ExampleBaseLock::n << std::endl;
}