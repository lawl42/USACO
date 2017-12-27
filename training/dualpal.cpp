/*
ID: lgwong11
TASK: dualpal
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check(string num)
{
	for (int i = 0; i < num.size() / 2; i++)
		if (num[i] != num[num.size() - i - 1])
			return false;
	return true;
}

string base(int num, int base)
{
	string val = "";
	for (int i = 0; true; i++)
	{
		string mod = to_string(num % base);
		num /= base;
		val.insert(0, mod);

		if (num == 0) break;
	}
	return val;
}

int main(void)
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	
	int N, S;
	fin >> N >> S;
	S++;

	for (int i = 0; i < N; S++)
	{
		int num = 0;
		for (int j = 2; j <= 10; j++)
		{
			if (check(base(S, j)))
				num++;
			if (num == 2) {
				fout << S << endl;
				i++;
				break;
			}
		}
	}

	return 0;
}