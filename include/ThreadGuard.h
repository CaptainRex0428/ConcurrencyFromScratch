#include <thread>

class ThreadGuard
{
	std::thread& t;

public:
	explicit ThreadGuard(std::thread & _t)
		:t(_t)
	{}

	~ThreadGuard()
	{
		if(t.joinable())
		{
			t.join();
		}
	}

	ThreadGuard(ThreadGuard const&) = delete;
	ThreadGuard& operator=(ThreadGuard const&) = delete;
};