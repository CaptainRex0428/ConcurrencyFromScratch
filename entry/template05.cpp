// 批量生成线程

#include <iostream>
#include <thread>
#include <vector>

#include "Function.h"
#include "ScopedThread.h"

#include "Timer.h"

#define WORK_COUNT 1
#define PROGRESS_COUNT 2

void do_work(unsigned int count)
{
	for (unsigned int c = 0; c < WORK_COUNT; ++c)
	{
		std::cout << count;
	}
}

int main(int argc, char* argv[])
{

	std::vector<std::thread> threads;

	{
		EVENT_TIMER_TAG("MultiProgress");

		for (unsigned int i = 0; i < PROGRESS_COUNT; ++i)
		{
			threads.push_back(std::thread(do_work, i));
		}

		for (auto j = threads.begin(); j != threads.end(); ++j)
		{
			j->join();
		}

		std::cout << std::endl;
	}

	int countTime = PROGRESS_COUNT * WORK_COUNT;

	{
		EVENT_TIMER_TAG("LinearProgress");

		for (unsigned int i = 0; i < countTime; ++i)
		{
			std::cout << (i % 2);
		}

		std::cout << std::endl;
	}


	return 0;

}