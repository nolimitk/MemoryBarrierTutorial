// MemoryBarrierTutorial.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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