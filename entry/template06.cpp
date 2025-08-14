// std::accumulate改写多线程版本

#include <iostream>
#include <thread>
#include <iterator>
#include <vector>
#include <functional>
#include <numeric>

#include "Timer.h"

#define MIN_PROGRESS_COUNT 2

template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T& init)
{
	size_t const length = std::distance(first, last);

	if (!length)
		return init;

	size_t const min_per_thread = 25;
	size_t const max_threads = (length + min_per_thread - 1) / min_per_thread;
	size_t const hardware_threads = std::thread::hardware_concurrency();
	size_t const num_threads = std::min(hardware_threads != 0 ? hardware_threads : MIN_PROGRESS_COUNT, max_threads);

	size_t const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);

	Iterator block_start = first;

	for (size_t i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		// 实例化 accumulate_block 对象，并传递给 std::thread
		threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}

	// 处理最后一个块
	accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

	// 等待所有线程完成
	for (auto& t : threads)
	{
		t.join();
	}

	return std::accumulate(results.begin(), results.end(), init);
}

int main(int argc, char* argv[])
{
	// 示例数据
	std::vector<int> data;

	for (int i = 0; i < 1065000; ++i)
	{
		data.push_back(i);
	}

	// 初始值
	int init = 0;

	{
		EVENT_TIMER_TAG("Parallel")
		// 执行并行累加
		int result = parallel_accumulate(data.begin(), data.end(), init);

		std::cout << "The result is: " << result << std::endl;
	}

	{
		EVENT_TIMER_TAG("SingleProgress")

		int result = std::accumulate(data.begin(), data.end(), init);

		std::cout << "The result is: " << result << std::endl;
	}
	

	return 0;
}
