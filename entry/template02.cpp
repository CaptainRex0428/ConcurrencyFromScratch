// �̱߳������Զ��ȴ����ͷ�

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