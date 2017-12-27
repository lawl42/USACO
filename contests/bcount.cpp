#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	FILE *inf = freopen("bcount.in", "r", stdin);
	FILE *outf = freopen("bcount.out", "w", stdout);

	int n, q;
	scanf("%d %d", &n, &q);

	vector<vector<int> > prefix(4);
	for (int i = 1; i <= 3; i++)
	{
		prefix[i].resize(n + 1);
		for (int j = 0; j <= n; j++)
		{
			prefix[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int curr;
		scanf("%d", &curr);

		for (int j = 1; j <= 3; j++)
		{
			prefix[j][i] = prefix[j][i - 1];
		}

		prefix[curr][i]++;
	}
	
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d %d %d\n", (prefix[1][b] - prefix[1][a - 1]), (prefix[2][b] - prefix[2][a - 1]), (prefix[3][b] - prefix[3][a - 1]));
	}

	/* Orignial Code = TLE
	vector<int> line(n+1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &line[i]);
	}

	for (int i = 0; i < q; i++)
	{
		int breeds[4] = { 0 };
		int start, finish;
		scanf("%d %d", &start, &finish);

		for (int index = start; index <= finish; index++)
		{
			breeds[line[index]]++;
		}
		
		printf("%d %d %d\n", breeds[1], breeds[2], breeds[3]);
	}*/

	return 0;
}