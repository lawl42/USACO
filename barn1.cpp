/*
ID: lgwong11
TASK: barn1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int M, S, C, sum, stall[201], dif[201];

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	
	fin >> M >> S >> C;
	
	int k;
	for (int i = 0; i < C; i++)
	{
		fin >> k;
		stall[i] = k;
	}

	if (M > C)
		M = C;
	
	sort(stall, stall + C);
	sum = stall[C - 1] - stall[0] + 1;
	
	for (int i = 0; i < C - 1; i++)
		dif[i] = stall[i + 1] - stall[i] - 1;
	sort(dif, dif + C - 1);
	
	for (int i = C - 2; i > C - M - 1; i--)
		sum = sum - dif[i];
	
	fout << sum << endl;
	return 0;
}