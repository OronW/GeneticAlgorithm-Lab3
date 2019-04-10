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

void testQueensLS(int epoch, int N) {
	double time;
	int solved = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveQueensConflict(N, 10000))
			solved++;
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(solved) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " QUEENS PROBLEM (Min Conflict):" << endl;
	cout << "solved rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}


void testQueensGA(int epoch, int N, int cross_type = 1, int mutatation_type = 2) {
	double time;
	int solved = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveQueensProb(N, 500, cross_type, mutatation_type))
			solved++;
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(solved) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " QUEENS PROBLEM (Genetic Algorithm):" << endl;
	cout << "solved rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}


void popTester(int epoch, int N = 2048, int itr = 1000, int h = 1, int cross_type = 1, double mutation_rate = 0.25, int selection_type = 1) {
	double time;
	int solved = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveUsingGen(N, itr, h, cross_type, mutation_rate, selection_type)) {
			//(solve_genetics(2000, 500, 1,2,0.250)
			//int N, int itr, int h, int cross_type, int mutation_rate
			cout << "solved!" << endl;
			solved++;
		}
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(solved) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " POPULATION PROBLEM:" << endl;
	cout << "solved rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}


int main()
{
	srand(unsigned(time(NULL)));
	
	clock_t startElapsed;
	double elapsedDuration;
	
	startElapsed = clock();

	solveUsingGen(5000, 500, 1, 1, 0.1, 3);
		//			(popSize,  ,crossbreed , Heuristic, muatation, selection)
		//						1-eltism,	1-Manhattan,	rate,	1-single	
		//						2-SUS,		2-BE					2-Unifrm
		//						3-Tour								3-smrt
		
	//solveQueensProb(1000, 1000, 1, 0.2)
		//		(popSize,  crossbreed,  muatation)
		//					1-eltism,		rate	
		//					2-SUS,						
		//					3-Tour				


	//solveQueensConflict(1000, 20000)
		//			(popSize,  iteration)

	//solveSack(1000, 2000, 1, 0.05)
		//	(popSize ,iteration , cross , muatation)


	elapsedDuration = (clock() - startElapsed) / (double)CLOCKS_PER_SEC;

	system("pause");

	return 0;
}