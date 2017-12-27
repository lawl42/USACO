/*
ID: lgwong11
TASK: skidesign
LANG: C++11
*/

#include <fstream>
#include <algorithm>

using namespace std;

int n, hills[1000];

int main()
{
	ifstream fin("skidesign.in");
	fin >> n;
	for (int i = 0; i<n; i++)
		fin >> hills[i];

	int mincost = 1000000;
	for (int i = 0; i < 84; i++)
	{
		int cost = 0, x;
		for (int j = 0; j < n; j++)
		{
			if (hills[j] < i)
				x = i - hills[j];
			else if (hills[j] > i + 17)
				x = hills[j] - (i + 17);
			else
				x = 0;
			cost += x*x;
		}
		mincost = min(mincost, cost);
	}

	ofstream fout("skidesign.out");
	fout << mincost << "\n";
}