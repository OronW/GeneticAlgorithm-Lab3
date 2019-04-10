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
//#include "Queens.cpp"


void testfunc(string &s) {
	s += "HIJKLMNOPTGY";
}

void testQueensLS(int epoch, int N) {
	double time;
	int success = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveQueensConflict(N, 10000))
			success++;
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(success) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " QUEENS PROBLEM (Min Conflict):" << endl;
	cout << "Success rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}


void run_knapsack() {
	int cross;
	int N;
	int mutate;

	cout << "Solving Knapsack:" << endl;
	cout << "Choose problem (0...7):";
	cin >> N;
	cout << "Choose cross type:" << endl;
	cout << "1: Single Point" << endl;
	cout << "2: Uniform" << endl;
	cin >> cross;
	cout << "Choose mutation type:" << endl;
	cout << "1: Random item shift" << endl;
	cout << "2: Smart item shift" << endl;
	cin >> mutate;



	if (solveSack(N, 2000, cross, mutate))
		cout << "Success!" << endl;
	else
		cout << "Failure" << endl;

	cout << endl << endl << endl;
	cout << "Program finished, press enter to exit." << endl;
	getchar(); getchar();
	//(int problem, int itr, int cross_type, int mutatation_type)
}


void run_queens_GA() {
	int selection;
	int cross;
	int N;
	int mutate;

	cout << "Solving Queens (Genetic Algorithm):" << endl;
	cout << "Choose board size:";
	cin >> N;
	cout << "Choose mutation type:" << endl;
	cout << "1: Random column change" << endl;
	cout << "2: Randon conflict min" << endl;
	cin >> mutate;
	cout << "Choose cross type:" << endl;
	cout << "1: Single Point" << endl;
	cout << "2: Uniform" << endl;
	cin >> cross;

	if (solveQueensProb(N, 1000, cross, mutate))
		cout << "Success!" << endl;
	else
		cout << "Failure" << endl;

	cout << endl << endl << endl;
	cout << "Program finished, press enter to exit." << endl;
	getchar(); getchar();


}


void run_queens_LS() {
	int N;

	cout << "Solving Queens (Minimum Conflict):" << endl;
	cout << "Choose board size:";
	cin >> N;

	if (solveQueensConflict(N, 20000))
		cout << "Success!" << endl;
	else
		cout << "Failure" << endl;

	cout << endl << endl << endl;
	cout << "Program finished, press enter to exit." << endl;
	getchar(); getchar();

}



void run_genetics() {
	int h;
	int selection;
	int cross;
	int N;
	double mutate;

	cout << "Solving Genetics:" << endl;
	cout << "Choose population size:";
	cin >> N;
	cout << "Choose heuristic:" << endl;
	cout << "1: Manhattan distance" << endl;
	cout << "2: Bullseye" << endl;
	cin >> h;
	cout << "Choose selection type:" << endl;
	cout << "1: Elitism" << endl;
	cout << "2: SUS" << endl;
	cout << "3: Tournament" << endl;
	cin >> selection;
	cout << "Choose mutation rate [0,1]:";
	cin >> mutate;
	cout << "Choose cross type:" << endl;
	cout << "1: Single Point" << endl;
	cout << "2: Uniform" << endl;
	cout << "3: Smart " << endl;
	cin >> cross;

	if (solveUsingGen(N, 500, h, cross, mutate, selection))
		cout << "Success!" << endl;
	else
		cout << "Failire!" << endl;

	cout << endl << endl << endl;
	cout << "Program finished, press enter to exit." << endl;
	getchar(); getchar();

}


void run() {
	cout << "Choose an option:" << endl;
	cout << "1: Solve Genetics" << endl;
	cout << "2: Solve Queens (using genetic algorithm)" << endl;
	cout << "3: Solve Queens (using local search algorithm)" << endl;
	cout << "4: Solve Knapsack" << endl;
	int opt;
	cin >> opt;
	if (opt == 1)
		run_genetics();
	else if (opt == 2)
		run_queens_GA();

	else if (opt == 3)
		run_queens_LS();

	else if (opt == 4)
		run_knapsack();

	else {
		cout << "Invalid option" << endl;
		return;
	}
}


void testQueensGA(int epoch, int N, int cross_type = 1, int mutatation_type = 2) {
	double time;
	int success = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveQueensProb(N, 500, cross_type, mutatation_type))
			success++;
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(success) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " QUEENS PROBLEM (Genetic Algorithm):" << endl;
	cout << "Success rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}


void testPop(int epoch, int N = 2048, int itr = 1000, int h = 1, int cross_type = 1, double mutation_rate = 0.25, int selection_type = 1) {
	double time;
	int success = 0;
	clock_t t = clock();
	for (int i = 0; i < epoch; i++) {
		if (solveUsingGen(N, itr, h, cross_type, mutation_rate, selection_type)) {
			//(solve_genetics(2000, 500, 1,2,0.250)
			//int N, int itr, int h, int cross_type, int mutation_rate
			cout << "Success!" << endl;
			success++;
		}
	}
	time = double((clock() - t) / CLOCKS_PER_SEC);
	double avg_time = time / epoch;
	double rate = double(success) / epoch;

	cout << endl << endl;
	cout << "******************************************************" << endl;
	cout << "AVERAGE TOTALS FOR " << N << " POPULATION PROBLEM:" << endl;
	cout << "Success rate: " << rate << endl;
	cout << "Average time: " << avg_time << endl;
}



//TODO : WHY DIVIDEPOPSIZE BY 2 WHEN MATING?

int main()
{
	srand(unsigned(time(NULL)));
	run();
	//testPop(10);

	return 0;
}