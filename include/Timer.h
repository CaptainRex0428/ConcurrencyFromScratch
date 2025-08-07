#pragma once

#include <string>
#include <chrono>

#define EVENT_TIMER_TAG(tag) Timer t##__Line__(tag)

class Timer
{

public:
	Timer(std::string _TaskTag);
	~Timer();

private:
	std::chrono::steady_clock::time_point m_StartTime;
	std::chrono::steady_clock::time_point m_EndTime;
	std::string m_Tag;
};