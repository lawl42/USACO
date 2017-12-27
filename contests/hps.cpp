#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	FILE *inf = freopen("hps.in", "r", stdin);
	FILE *outf = freopen("hps.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<int> hoof(n+1);
	vector<int> paper(n+1);
	vector<int> scissor(n+1);
	hoof[0] = 0, paper[0] = 0, scissor[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		char ch;
		scanf(" %c", &ch);

		if (ch == 'H')
		{
			paper[i] = 1;
		}
		else if (ch == 'P')
		{
			scissor[i] = 1;
		}
		else
		{
			hoof[i] = 1;
		}

		hoof[i] += hoof[i - 1];
		paper[i] += paper[i - 1];
		scissor[i] += scissor[i - 1];
	}

	int ret = 0;
	for (int cutoff = 1; cutoff <= n; cutoff++)
	{
		int first_half = max(max(hoof[cutoff], paper[cutoff]), scissor[cutoff]);
		int second_half = max(max(hoof[n] - hoof[cutoff], paper[n] - paper[cutoff]), scissor[n] - scissor[cutoff]);

		ret = max(ret, first_half + second_half);
	}

	printf("%d\n", ret);
	return 0;
}