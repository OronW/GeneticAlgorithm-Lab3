#pragma once


#include <vector>
#include <string>
#include <iostream>	

using namespace std;

struct problem
{
	int capacity;
	vector <int> val;
	vector <int> weights;
	int max_value;

};

typedef vector<problem> ProblemVector;
typedef struct problem Prob;
void init_problems();
struct problem getProbl(int ind);
int calcMVal(string &s, problem &p);
