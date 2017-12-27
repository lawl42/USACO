#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int curr, bool canHear[], vector<vector<bool>> canTransmit)
{
	if (canHear[curr])
	{
		return 0;
	}
	canHear[curr] = true;
	int ret = 1;
	for (int i = 0; i < canTransmit[curr].size(); i++)
	{
		if (canTransmit[curr][i])
			ret += dfs(i, canHear, canTransmit);
	}
	return ret;
}

int main()
{
	FILE *inf = freopen("moocast.in", "r", stdin);
	FILE *outf = freopen("moocast.out", "w", stdout);

	int n;
	scanf("%d", &n);

	int *x = new int[n];
	int *y = new int[n];
	int *p = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
		scanf("%d", &p[i]);
	}

	vector<vector<bool>> canTransmit(n);
	for (int i = 0; i < n; i++)
	{
		canTransmit[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			int squareDist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (squareDist <= p[i] * p[i])
				canTransmit[i][j] = true;
			
		}
	}

	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		bool *canHear = new bool[n];
		for (int i = 0; i < n; i++)
			canHear[i] = false;
		ret = max(ret, dfs(i, canHear, canTransmit));
	}

	cout << ret;
	return 0;
}