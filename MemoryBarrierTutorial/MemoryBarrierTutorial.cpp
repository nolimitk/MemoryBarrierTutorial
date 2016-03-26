// MemoryBarrierTutorial.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "VolatileProblem.h"
#include "VolatileProblemWithInterlocked.h"
#include "MemoryBarrierProblem.h"
#include "DoubleCheckedLockingProblem.h"

#include "NKThread.h"

int g1 = 0;
int count1 = 0;
int count2 = 0;

//void producer(void)
//{
//	g1++;
//	count1++;
//}
//
//void consumer(void)
//{
//	g1--;
//	count2++;
//}

unsigned int __stdcall producer(void*)
{
	for (int i = 0; i < 100; ++i)
	{
		g1++;
		Sleep(0);
	}
	count1++;
	return 0;
}

unsigned int __stdcall consumer(void*)
{
	for (int i = 0; i < 100; ++i)
	{
		g1--;
		Sleep(0);
	}
	count2++;
	return 0;
}

int main()
{
	/*
	const static int NUM_THREADS = 10;
	//std::thread t_p[NUM_THREADS];
	//std::thread t_c[NUM_THREADS];
	NKCore::NKThread t_p[NUM_THREADS];
	NKCore::NKThread t_c[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		//t_p[i] = std::thread(producer);
		//t_c[i] = std::thread(consumer);

		t_p[i].start(producer);
		t_c[i].start(consumer);
	}

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		t_p[i].join();
		t_c[i].join();
	}

	std::wstringstream log_stream;
	log_stream << L"main g1 " << g1 << " count " << count1 << " , " << count2 << std::endl;
	std::wcout << log_stream.str();
	*/

	//VolatileProblem::run();
	//VolatileProblemWithInterlocked::run();
	//MemoryBarrierProblem::run();
	DoubleCheckedLockingProblem::run();
	
    return 0;
}