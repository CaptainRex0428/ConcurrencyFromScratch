// Ω‚ Õstd::move

#include <iostream>
#include <thread>

#include "Function.h"
#include "ThreadGuard.h"

#include <vector>

int main(int argc, char * argv[])
{

	std::vector<int> v;
	v.emplace_back(int{1});
	v.emplace_back(int{2});

	std::cout << "Before move\t-------------" << std::endl;
	std::cout << "v:\t" << & v << std::endl;
	std::cout << "v[0]:\t" << &v[0] << std::endl;
	std::cout << "v size:\t" << v.size() << std::endl;

	std::vector<int> v2{ std::move(v) };

	std::cout << "After move\t--------------" << std::endl;
	std::cout << "v:\t" << &v << std::endl;
	//std::cout << "v[0]:" << &v[0] << std::endl;
	std::cout << "v size:\t" << v.size() << std::endl;
	std::cout << "v2:\t" << &v2 << std::endl;
	std::cout << "v2[0]:\t" << &v2[0] << std::endl;
	std::cout << "v2 size:\t" << v2.size() << std::endl;

	return 0;

}