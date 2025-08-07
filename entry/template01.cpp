#include <iostream>
#include <thread>

void EntryA()
{
	std::cout << "Hello Concurrency World!" << std::endl;
}

int main(int argc, char * argv[])
{
	std::thread EntryAThread(EntryA);
	EntryAThread.join();

	return 0;
}