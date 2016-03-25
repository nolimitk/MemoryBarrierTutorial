// MemoryBarrierTutorial.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "VolatileProblem.h"
#include "VolatileProblemWithInterlocked.h"
#include "MemoryBarrierProblem.h"
#include "DoubleCheckedLockingProblem.h"

int main()
{
	//VolatileProblem::run();
	//VolatileProblemWithInterlocked::run();
	//MemoryBarrierProblem::run();
	DoubleCheckedLockingProblem::run();
	
    return 0;
}