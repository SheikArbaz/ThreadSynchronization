#include "stdafx.h"
#include "StandardThreadMutexExample.h"

std::mutex mtx;

void print_block(int n, char c) {
	mtx.lock();
	for (int i = 0; i<n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock();
}
DWORD WINAPI Add(DWORD a, DWORD b) {
	std::cout << "Thread running " << a + b << std::endl;
	return 0;
}
void StdThreadExample()
{
	std::thread thread0(Add, 10, 12);
	std::thread th2(print_block, 50, '$');
	std::thread th1(print_block, 50, '*');

	th1.join();
	thread0.join();
	th2.join();
}
