#include <iostream>
#include <vector>

using namespace std;

int main()
{
	FILE *inf = freopen("highcard.in", "r", stdin);
	FILE *outf = freopen("highcard.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<int> elsie(2 * n + 1);

	for (int i = 0; i < n; i++)
	{
		int card;
		scanf("%d", &card);
		elsie[card] = 1;
	}

	vector<int> bessie(2 * n + 1);
	for (int i = 0; i < 2 * n + 1; i++)
	{
		if (elsie[i] == 0) bessie[i] = 1;
	}
	bessie[0] = 0;

	int points = 0, b_start = 2 * n, b_end = 1;
	for (int e = 2 * n; e > 0; e--)
	{
		if (elsie[e] == 0)
		{
			continue;
		}
		else // elsie must have this card
		{
			for (int b = b_start; b > e; b--)
			{
				if (bessie[b] == 1)
				{
					elsie[e] = 0;
					bessie[b] = 0;
					b_start = b;
					points++;
					break;
				}
			}
			
			if (elsie[e] == 1)
			{
				for (int b = b_end; b < e; b++)
				{
					if (bessie[b] == 1)
					{
						elsie[e] = 0;
						bessie[b] = 0;
						b_end = b;
						break;
					}
				}
			}
		}
	}

	printf("%d", points);
	return 0;
}