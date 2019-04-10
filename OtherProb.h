#pragma once


#include <vector>
#include <string>
#include <iostream>	

using namespace std;

struct problem
{
	int capacity;
	vector <int> values;
	vector <int> weights;
	int max_value;

};

typedef vector<problem> ProblemVector;
typedef struct problem Prob;

void init_problems();

struct problem getProblem(int ind);
int calcMaxValue(string &s, problem &p);
