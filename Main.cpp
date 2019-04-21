#ifdef CHECK

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}

#endif

#pragma warning(disable:4786)		// disable debug warning

#include "Genetic.h"
#include "QueenProblem.h"
#include "OtherProb.h"
#include "sack01.h"
#include <ctime>


void testfunc(string &s) {
	s += "OSNGHKNAS";
}

int main()
{
	srand(unsigned(time(NULL)));
	
	clock_t startElapsed;
	double elapsedDuration;
	
	startElapsed = clock();

	solveUsingGen(5000, 500, 1, 1, 0.1, 3);
		//		(popSize, iterations, 	Heuristic,		crossbreed,  muatation,	selection)
		//								1-Manhattan,	1-single,		rate,	1-eltism	
		//								2-BE			2-Unifrm,				2-SUS,
		//																		3-Tour
		
	//solveQueensProb(1000, 1000, 1, 0.2);
		//		(popSize,	iterations,		crossbreed,  muatation)
		//									1-single,		rate	
		//									2-Unifrm,					
		//												


	//solveQueensConflict(1000, 20000);
		//			(popSize,  iteration)

	//solveSack(1000, 2000, 1);
		//	(popSize ,iteration , cross)
		//						1-single
		//						2-Unifrm

	elapsedDuration = (clock() - startElapsed) / (double)CLOCKS_PER_SEC;

	system("pause");

	return 0;
}