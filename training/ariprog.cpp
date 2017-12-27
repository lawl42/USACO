/*
ID: lgwong11
PROG: ariprog
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 125001

using namespace std;

int N, M;
bool bs[MAX];

int main() {
	ifstream fin ("ariprog.in");
	ofstream fout ("ariprog.out");

	fin >> N >> M;
	for (int i = 0; i < M + 1; i++)
		for (int j = i; j < M + 1; j++)
			bs[i * i + j * j] = 1;

	vector<int> pos;
	for (int i = 0; i < MAX; i++)
		if (bs[i])
			pos.push_back(i);

	set<pair<int, int>> ans;
	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = i + 1; j < pos.size(); j++)
		{
			if (pos[i] + (N - 1) * (pos[j] - pos[i]) > 2 * M * M) break;
			
			bool in = true;
			for (int k = 0; k < N; k++)
			{
				if (!bs[pos[i] + k * (pos[j] - pos[i])]) {
					in = false;
					break;
				}
			}

			if (in) ans.insert(make_pair(pos[j] - pos[i], pos[i]));
		}
	}

	for (const auto& a : ans) fout << a.second << " " << a.first << endl;
	if (ans.size() == 0) fout << "NONE" << endl;

	return 0;
}