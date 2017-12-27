#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// vectors
vector<vector<int>> barn;

// checks accessibility to location (r,c)
bool accessible(int r, int c, int bound)
{
	if (barn[r][c] == 2)
		return true;
	else if (c+1 < bound && barn[r][c + 1] == 2)
		return true;
	else if (c-1 >= 0 && barn[r][c - 1] == 2)
		return true;
	else if (r+1 < bound && barn[r + 1][c] == 2)
		return true;
	else if (r-1 >= 0 && barn[r - 1][c] == 2)
		return true;
	else
		return false;
}

// new room is lit and accessible // light up rooms from the new room
void updateBarn(int r, int c, const vector<pair<int, int>> locs, const vector<pair<int, int>> lit, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (locs[i].first == r && locs[i].second == c) {
			if (barn[lit[i].first][lit[i].second] == 0)
			{
				barn[lit[i].first][lit[i].second] = 1;
			}
		}
	}
}

int main()
{
	FILE *inf = freopen("lightson.in", "r", stdin);
	FILE *outf = freopen("lightson.out", "w", stdout);

	int n;
	scanf("%d", &n);
	
	int m;
	scanf("%d", &m);


	// initialize the barn as all unlit
	//vector<vector<int>> barn(n);
	barn.resize(n);
	for (int i = 0; i < n; i++)
	{
		barn[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			barn[i][j] = 0;
		}
	}
	// starting point is lit
	barn[0][0] = 2;

	// determine where the switches are and what rooms they light up
	vector< pair<int, int>> locs(m);
	vector< pair<int, int>> lit(m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &locs[i].first);
		scanf("%d", &locs[i].second);
		scanf("%d", &lit[i].first);
		scanf("%d", &lit[i].second);

		--locs[i].first;
		--locs[i].second;
		--lit[i].first;
		--lit[i].second;

		// light all the rooms from (1,1)
		if (locs[i].first == 0 && locs[i].second == 0)
		{
			barn[lit[i].first][lit[i].second] = 1;
		}
	}

	bool change;
	do
	{
		change = false;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (accessible(r, c, n) && barn[r][c] == 1) 
				{
					barn[r][c] = 2;
					change = true;
					updateBarn(r, c, locs, lit, m);
				}
			}
		}
	} while (change);

	// calculate lit rooms
	int ret = 0;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (barn[r][c] >= 1)
			{
				ret++;
			}
		}
	}
	printf("%d", ret);
	return 0;
}