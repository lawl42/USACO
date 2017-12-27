/*
ID: lgwong11
TASK: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void)
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int N, M;
	fin >> N >> M;

	if (N == 0)
	{
		fout << 0 << endl;
		return 0;
	}

	vector< pair <int, int> > pairs;
	for (int i = 0; i < M; i++)
	{
		int P, A;
		fin >> P >> A;
		pairs.push_back(make_pair(P, A));
	}
	// would be faster if i sorted the vector first

	int cost = 0;
	do {
		int min = 0;
		for (int i = 0; i < M; i++)
		{
			if (pairs[i].first < pairs[min].first)
				min = i;
		}

		if (pairs[min].second > N)
		{
			cost += N * pairs[min].first;
			N = 0;
		}
		else {
			cost += pairs[min].second * pairs[min].first;
			N -= pairs[min].second;
			cout << min << endl;
			pairs.erase(pairs.begin() + min);
			M--;
		}
	} while (N > 0);

	fout << cost << endl;
	return 0;
}