#pragma once

#include <windows.h>
//#include <atomic>
//#include "NKSingleton.h"
//#include <strsafe.h>

namespace DoubleCheckedLockingProblem
{
	char* p = nullptr;
	//int g1 = 0;
	//volatile int g1 = 0;
	//std::atomic<int> g2 = 0;
	//volatile int g2 = 0;
	unsigned int g2 = 0;

	char* getInstance(void)
	{
		if (p == nullptr)
		{
			p = new char[128];
			InterlockedIncrement(&g2);
			//g2++;
		}
		return p;
	}

	void run(void)
	{
		const static int NUM_THREADS = 100;
		std::thread t[NUM_THREADS];

		{
			std::wstringstream log_stream;
			log_stream << L"main g2 " << g2 << std::endl;
			std::wcout << log_stream.str();
		}

		for (int i = 0; i < NUM_THREADS; ++i)
		{
			t[i] = std::thread([i](void)->void
				{
					char *p = getInstance();

					//StringCchCopy(p, 128, "abc");

					std::wstringstream log_stream;
					//log_stream << L"lambda i " << i << " p " << (void *)p << L" g2 " << g2 << std::endl;
					log_stream << L"lambda i " << i << " p " << (void *)p << std::endl;
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
			log_stream << L"main g2 " << g2 << std::endl;
			std::wcout << log_stream.str();
		}
	}
}