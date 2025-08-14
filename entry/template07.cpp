// 批量生成线程并获取线程ID

#include <iostream>
#include <thread>
#include <vector>

#include "Function.h"
#include "ScopedThread.h"

#include "Timer.h"

#define WORK_COUNT 10
#define PROGRESS_COUNT 5

void do_work(unsigned int count)
{
	for (unsigned int c = 0; c < WORK_COUNT; ++c)
	{
		std::stringstream ss;
		ss << std::this_thread::get_id() << ":" << count << std::endl;
		std::cout << ss.str();
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

		for (int i = 0; i < countTime; ++i)
		{
			std::cout << (i % (PROGRESS_COUNT-1));
		}

		std::cout << std::endl;
	}


	return 0;

}