#pragma once

#include <iostream>

struct func
{
	int i;

	func(int & _i):i(_i){}

	void operator()()
	{
		for(unsigned j =0; j < 1000; ++j)
		{
			std::cout << j << std::endl;
		}
	}
};