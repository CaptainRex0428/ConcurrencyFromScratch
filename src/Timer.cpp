#include "Timer.h"
#include <iostream>


Timer::Timer(std::string _TaskTag)
	:m_Tag(_TaskTag)
{
	m_StartTime = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
	m_EndTime = std::chrono::steady_clock::now();
	long long microDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_EndTime - m_StartTime).count();

	std::cout << "[" << microDuration / 1000.f << " us]" << m_Tag << std::endl;
}
