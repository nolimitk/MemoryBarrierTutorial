#pragma once

#include <atomic>

namespace DoubleCheckedLockingProblem
{
	char* p = nullptr;
	std::atomic<int> c = 0;
	std::atomic<int> g1 = 0;

	char* getInstance(void)
	{
		if (p == nullptr)
		{
			if (p == nullptr)
			{
				// this is for occuring multi thread problem
				std::this_thread::yield();
				p = new char[256];
				c++;
			}
			g1++;
		}
		return p;
	}

	void func(void)
	{
		char *p = getInstance();

		std::wstringstream log_stream;
		log_stream << L"func p " << (void *)p << std::endl;
		std::wcout << log_stream.str();
	}

	void run(void)
	{
		const static int NUM_THREADS = 1000;
		std::thread t[NUM_THREADS];

		{
			std::wstringstream log_stream;
			log_stream << L"main g2 " << c << std::endl;
			std::wcout << log_stream.str();
		}

		for (int i = 0; i < NUM_THREADS; ++i)
		{
			t[i] = std::thread([i](void)->void
				{
					std::thread::id id = std::this_thread::get_id();
					std::this_thread::yield();
					char *p = getInstance();

					std::wstringstream log_stream;
					log_stream << L"lambda thread " << id << " pointer " << (void *)p << std::endl;
					std::wcout << log_stream.str();
				}
			);
		}

		for (int i = 0; i < NUM_THREADS; ++i)
		{
			t[i].join();
		}

		{
			std::wstringstream log_stream;
			log_stream << L"main g1 " << g1 << " count " << c << std::endl;
			std::wcout << log_stream.str();
		}
	}
}