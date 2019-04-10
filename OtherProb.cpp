#include "OtherProb.h"



ProblemVector P;

struct problem p1, p2, p3, p4, p5, p6, p7, p8;

void init_problems() {
	string s;

	s = "1111010000";
	p1.capacity = 165;
	p1.weights = { 23, 31, 29, 44, 53, 38, 63, 85, 89, 82 };
	p1.values = { 92,57,49,68,60,43,67,84,87,72 };
	p1.max_value = calcMaxValue(s, p1);
	if (s.size() != p1.weights.size())
		cout << "Solution length for p1 mismatch!" << endl;

	s = "01110";
	p2.capacity = 26;
	p2.weights = { 12,7,11,8,9 };
	p2.values = { 24,13,23,15,16 };
	p2.max_value = calcMaxValue(s, p2);
	if (s.size() != p2.weights.size())
		cout << "Solution length for p2 mismatch!" << endl;

	s = "110010";
	p3.capacity = 190;
	p3.weights = { 56,59,80,64,75,17 };
	p3.values = { 50,50,64,46,50,5 };
	p3.max_value = calcMaxValue(s, p3);
	if (s.size() != p3.weights.size())
		cout << "Solution length for p3 mismatch!" << endl;

	s = "1001000";
	p4.capacity = 50;
	p4.weights = { 31,10,20,19,4,3,6 };
	p4.values = { 70,20,39,37,7,5,10 };
	p4.max_value = calcMaxValue(s, p4);
	if (s.size() != p4.weights.size())
		cout << "Solution length for p4 mismatch!" << endl;

	s = "10111011";
	p5.capacity = 104;
	p5.weights = { 25,35,45,5,25,3,2,2 };
	p5.values = { 350,400,450,20,70,8,5,5 };
	p5.max_value = calcMaxValue(s, p5);
	if (s.size() != p5.weights.size())
		cout << "Solution length for p5 mismatch!" << endl;

	s = "0101001";
	p6.capacity = 170;
	p6.weights = { 41,50,49,59,55,57,60 };
	p6.values = { 442,525,511,593,546,564,617 };
	p6.max_value = calcMaxValue(s, p6);
	if (s.size() != p6.weights.size())
		cout << "Solution length for p6 mismatch!" << endl;

	s = "101010111000011";
	p7.capacity = 750;
	p7.weights = { 70,73,77,80,82,87,90,94,98,106,110,113,115,118,120 }; //15
	p7.values = { 135,139,149,150,156,163,173,184,192,201,210,214,221,229,240 }; //15
	p7.max_value = calcMaxValue(s, p7);
	if (s.size() != p7.weights.size())
		cout << "Solution length for p7 mismatch!" << endl;

	s = "110111000110100100000111";
	p8.capacity = 6404180;
	p8.weights = { 382745,799601,909247,729069,467902,44328,34610,698150,823460,903959,853665,551830,610856,670702,488960,951111,323046,446298,931161,31385,496951,264724,224916,169684 };
	p8.values = { 825594,1677009,1676628,1523970,943972,97426,69666,1296457,1679693,1902996,1844992,1049289,1252836,1319836,953277,2067538,675367,853655,1826027,65731,901489,577243,466257,369261 };
	p8.max_value = calcMaxValue(s, p8);
	if (s.size() != p8.weights.size())
		cout << "Solution length for p8 mismatch!" << endl;


	P.push_back(p1);
	P.push_back(p2);
	P.push_back(p3);
	P.push_back(p4);
	P.push_back(p5);
	P.push_back(p6);
	P.push_back(p7);
	P.push_back(p8);



	for (int i = 0; i < 8; i++) {
		if (P[i].weights.size() != P[i].values.size())
			cout << "SIZE NOT MATCH :" << i << endl;
	}


}



struct problem getProblem(int ind) {
	return P[ind];
}


int calcMaxValue(string &s, problem &p) {
	int output = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			output += p.values[i];
	}
	return output;
}