#include "OtherProb.h"



ProblemVector Sack;

struct problem prob1, prob2, prob3, prob4, prob5, prob6, prob7, prob8;

struct problem getProbl(int ind) {
	return Sack[ind];
}
int calcMVal(string &s, problem &p) {
	int output = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			output += p.val[i];
	}
	return output;
}

void init_problems() {
	string expected;

	prob1.capacity = 165;
	prob1.weights = { 23, 31, 29, 44, 53, 38, 63, 85, 89, 82 };
	prob1.val = { 92,57,49,68,60,43,67,84,87,72 };
	expected = "1111010000";
	prob1.max_value = calcMVal(expected, prob1);
	if (expected.size() != prob1.weights.size())
		cout << "Error with size" << endl;

	prob2.capacity = 26;
	prob2.weights = { 12,7,11,8,9 };
	prob2.val = { 24,13,23,15,16 };
	expected = "01110";
	prob2.max_value = calcMVal(expected, prob2);
	if (expected.size() != prob2.weights.size())
		cout << "Error with size" << endl;

	prob3.capacity = 190;
	prob3.weights = { 56,59,80,64,75,17 };
	prob3.val = { 50,50,64,46,50,5 };
	expected = "110010";
	prob3.max_value = calcMVal(expected, prob3);
	if (expected.size() != prob3.weights.size())
		cout << "Error with size" << endl;

	prob4.capacity = 50;
	prob4.weights = { 31,10,20,19,4,3,6 };
	prob4.val = { 70,20,39,37,7,5,10 };
	expected = "1001000";
	prob4.max_value = calcMVal(expected, prob4);
	if (expected.size() != prob4.weights.size())
		cout << "Error with size" << endl;
	
	prob5.capacity = 104;
	prob5.weights = { 25,35,45,5,25,3,2,2 };
	prob5.val = { 350,400,450,20,70,8,5,5 };
	expected = "10111011";
	prob5.max_value = calcMVal(expected, prob5);
	if (expected.size() != prob5.weights.size())
		cout << "Error with size" << endl;
	
	prob6.capacity = 170;
	prob6.weights = { 41,50,49,59,55,57,60 };
	prob6.val = { 442,525,511,593,546,564,617 };
	expected = "0101001";
	prob6.max_value = calcMVal(expected, prob6);
	if (expected.size() != prob6.weights.size())
		cout << "Error with size" << endl;
	
	prob7.capacity = 750;
	prob7.weights = { 70,73,77,80,82,87,90,94,98,106,110,113,115,118,120 }; //15
	prob7.val = { 135,139,149,150,156,163,173,184,192,201,210,214,221,229,240 }; //15
	expected = "101010111000011";
	prob7.max_value = calcMVal(expected, prob7);
	if (expected.size() != prob7.weights.size())
		cout << "Error with size" << endl;
	
	prob8.capacity = 6404180;
	prob8.weights = { 382745,799601,909247,729069,467902,44328,34610,698150,823460,903959,853665,551830,610856,670702,488960,951111,323046,446298,931161,31385,496951,264724,224916,169684 };
	prob8.val = { 825594,1677009,1676628,1523970,943972,97426,69666,1296457,1679693,1902996,1844992,1049289,1252836,1319836,953277,2067538,675367,853655,1826027,65731,901489,577243,466257,369261 };
	expected = "110111000110100100000111";
	prob8.max_value = calcMVal(expected, prob8);
	if (expected.size() != prob8.weights.size())
		cout << "Error with size" << endl;

	Sack.push_back(prob1);
	Sack.push_back(prob2);
	Sack.push_back(prob3);
	Sack.push_back(prob4);
	Sack.push_back(prob5);
	Sack.push_back(prob6);
	Sack.push_back(prob7);
	Sack.push_back(prob8);
	for (int i = 0; i < 8; i++) {
		if (Sack[i].weights.size() != Sack[i].val.size())
			cout << "SIZE NOT MATCH :" << i << endl;
	}


}
