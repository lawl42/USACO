/*
ID: lgwong11
TASK: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int N;
	fin >> N;
	int j1, j2, j3;
	fin >> j1 >> j2 >> j3;
	int m1, m2, m3;
	fin >> m1 >> m2 >> m3;

	int f = m1 - j1 > 0 ? m1 - j1 : j1 - m1;
	if (N - f < f)
		f = N - f;
	int s = m2 - j2 > 0 ? m2 - j2 : j2 - m2;
	if (N - s < s)
		s = N - s;
	int t = m3 - j3 > 0 ? m3 - j3 : j3 - m3;
	if (N - t < t)
		t = N - t;
	int num = N > 5 ? 5 : N;

	int total = num * num * num * 2;
	cout << f << s << t << endl;
	if (num == N)
	{
		total = num * num * num;
	}
	else if (f < num && s < num && t < num)
	{
		int sub = (num - f) * (num - s) * (num - t);
		cout << sub << endl;
		total -= sub;
	}

	fout << total << endl;
	return 0;
}