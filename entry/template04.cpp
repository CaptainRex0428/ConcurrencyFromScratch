// 利用std::move的线程保护

#include <iostream>
#include <thread>

#include "Function.h"
#include "ScopedThread.h"

int main(int argc, char * argv[])
{

	int local = 1;
	func aFunc(local);
	std::thread NThread(aFunc);
	ScopedThread ST(std::move(NThread));

	return 0;

}