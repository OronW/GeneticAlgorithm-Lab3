#pragma once
#ifndef GENETIC
#define GENETIC


#include <vector>			
#include <string>
#include <iostream>	
#include <algorithm>				// for sort algorithm
#include <time.h>					// for random seed
#include <math.h>					// for abs()

using namespace std;

struct ga_struct
{
	string str;
	int fitness;
};

typedef vector<ga_struct> ga_vector;// for brevity


#endif

#pragma once



void mutate(ga_struct &member);
void SUS_elitism(ga_vector &output, ga_vector &pop);
int getTotalFitness(ga_vector &Population);
void tournament(ga_vector &pop, ga_vector &output, int n);
int fitnessSum(ga_vector &Population, int end);
int bullseye_heuristic(string source, string target);
void RWS(ga_vector &Population, vector<int> &Points, ga_vector &Keep);
void SUS_elitism(ga_vector &output, ga_vector &pop);
void SUS(ga_vector &Population, ga_vector &output, int N);
bool goalState(string source);
void bullseye_fitness(ga_vector &population);
string uniform_cross(string source1, string source2);
void init_population(ga_vector &population, ga_vector &buffer);
void calc_fitness(ga_vector &population);
bool fitness_sort(ga_struct x, ga_struct y);
inline void sort_by_fitness(ga_vector &population);
void elitism(ga_vector &population, ga_vector &buffer, int esize);
void mutate(ga_struct &member);
void onePointCross(ga_vector &population, ga_vector &buffer);
void mate(ga_vector &population, ga_vector &buffer, int cross_type, double mutation_rate);
inline void print_best(ga_vector &gav);
inline void print_stats();
inline void swap(ga_vector *&population, ga_vector *&buffer);
bool solve_genetics(int N = 2048, int itr = 1000, int h = 1, int cross_type = 1, double mutation_rate = 0.25, int selection_type = 1);
string smart_cross(string source1, string source2, int fitness1, int fitness2);






