#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	FILE *inf = freopen("cowdance.in", "r", stdin);
	FILE *outf = freopen("cowdance.out", "w", stdout);

	int n, t_max;
	scanf("%d %d", &n, &t_max);

	vector<int> times(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &times[i]);
	}

	int min = 1;
	int max = n;
	while (min != max)
	{
		int mid = (min + max) / 2;
		int time_remaining = t_max;

		vector<int> stage(mid);
		for (int i = 0; i < mid; i++)
		{
			stage[i] = times[i];
		}
		
		for (int i = mid; i < n; i++)
		{
			auto it = min_element(begin(stage), end(stage));
			time_remaining -= *it;
			int temp = *it;
			for (int i = 0; i < mid; i++)
			{
				stage[i] = stage[i] - temp;
			}
			*it = times[i];
		}
		auto it = max_element(begin(stage), end(stage));
		time_remaining -= *it;
		if (time_remaining < 0)
		{
			min = mid + 1;
		}
		else if (time_remaining > 0)
		{
			max = mid;
		}
		else
		{
			min = mid;
			break;
		}
	}

	printf("%d\n", min);
	return 0;
}
