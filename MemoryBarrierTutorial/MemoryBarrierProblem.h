#pragma once

#include <iostream>
#include <thread>
#include <sstream>

namespace MemoryBarrierProblem
{
	volatile int g1 = 0;
	volatile int g2 = 0;

	void func1(void)
	{
		std::wstringstream log_stream;

		while (g1 == 0);
		
		// memory barrier problem is not occur in visual studio 2015 on Windows 10
		log_stream << L"func1 g1 " << g1 << L" g2 " << g2 << std::endl;
		std::wcout << log_stream.str();
	}

	void func2(void)
	{
		std::wstringstream log_stream;

		g2 = 42;
		g1 = 1;

		log_stream << L"func2 g1 " << g1 << L" g2 " << g2 << std::endl;
		std::wcout << log_stream.str();
	}

	void run(void)
	{
		std::thread t1(func1);
		std::thread t2(func2);

		t1.join();
		t2.join();
	}
}