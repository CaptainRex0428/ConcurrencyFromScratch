// 线程保护，自动等待和释放

#include <iostream>
#include <thread>

#include "Function.h"
#include "ThreadGuard.h"

int main(int argc, char * argv[])
{

	int local = 1;
	func aFunc(local);
	std::thread NThread(aFunc);
	ThreadGuard TG(NThread);

	return 0;
}