/*
ID: lgwong11
TASK: crypt1
LANG: C++11
*/

#include <iostream>
#include <fstream>
using namespace std;

int s[15] = { 0 };

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int n, a, b, c, d, e, add = 0, k, p;
	fin >> n;
	while (n--) {
		fin >> k;
		s[k] = 1;
	}

	for (a = 1; a <= 9; a++)
		for (b = 1; b <= 9; b++)
			for (c = 1; c <= 9; c++)
				for (d = 1; d <= 9; d++)
					for (e = 1; e <= 9; e++) 
					{
						if (s[a] && s[b] && s[c] && s[d] && s[e]) 
							p = 1;
						else 
							p = 0;

						k = (a * 100 + b * 10 + c)*d;
						if (k / 1000) 
							p = 0;
						while (k) {
							if (s[k % 10] == 0) p = 0;
							k /= 10;
						}

						k = (a * 100 + b * 10 + c)*e;
						if (k / 1000) 
							p = 0;
						while (k) {
							if (s[k % 10] == 0) p = 0;
							k /= 10;
						}

						k = (a * 100 + b * 10 + c)*(d * 10 + e);
						if (k / 10000) 
							p = 0;
						while (k) {
							if (s[k % 10] == 0) p = 0;
							k /= 10;
						}

						if (p) add++;
					}
	
	fout << add << endl;
	return 0;
}
