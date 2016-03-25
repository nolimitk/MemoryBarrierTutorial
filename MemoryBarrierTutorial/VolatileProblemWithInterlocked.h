#pragma once

#include <windows.h>
#include <iostream>
#include <thread>
#include <sstream>

namespace VolatileProblemWithInterlocked
{
	unsigned int g1 = 0;
	int g2 = 0;

	void func1(void)
	{
		std::wstringstream log_stream;

		// infinite loop : because of g1 is not declared as volatile
		while (g1 == 0);
		g2 = 1;

		log_stream << L"func1 g1 " << g1 << L" g2 " << g2 << std::endl;
		std::wcout << log_stream.str();
	}

	void func2(void)
	{
		std::wstringstream log_stream;

		g2 = 2;
		InterlockedIncrement(&g1);

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