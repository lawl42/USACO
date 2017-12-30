/*
ID: lgwong11
PROB: numtri
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int R;
int tri[1001][1001];

int main()
{
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	fin >> R;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= i; j++)
			fin >> tri[i][j];

    for (int r = 2; r <= R; r++)
    {
        for (int c = 1; c <= r; c++)
        {
			if (c == 1)
				tri[r][c] += tri[r - 1][c];
            else if (c == r)
                tri[r][c] += tri[r-1][c-1];
            else
                tri[r][c] += max(tri[r-1][c-1], tri[r-1][c]);
        }
    }

    int sum = 0;
    for (int i = 0; i <= R; i++)
        if (tri[R][i] > sum)
            sum = tri[R][i];
	fout << sum << endl;

	return 0;
}
