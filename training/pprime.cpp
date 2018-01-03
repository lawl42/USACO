/*
ID: lgwong11
PROB: pprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int a, b;

vector<int> primes;

bool isprime(int k)
{
	for (int i : primes)
	{
		if (k % i == 0 && k != i) return 0;
		if (i * i > k) return 1;
	}
	return 1;
}

int rev(int k)
{
	string s = to_string(k);
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main()
{
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	fin >> a >> b;

	primes.push_back(2);
	for (int i = 3; i < 10001; i += 2)
	{
		bool f = true;
		for (int j : primes)
		{
			if (i % j == 0)
			{
				f = false;
				break;
			}
			if (i * i > 0) break;
		}
		if (f) primes.push_back(i);
	}

	for (int i = 1; i < 9; i++) // num of digits 
	{
		if (i % 2 == 0) // length 2n
		{
			for (int j = pow(10, i / 2 - 1); j < pow(10, i / 2); j++)
			{
				int t = pow(10, i / 2) * j + rev(j); // palindrome
				if (isprime(t) && t >= a && t <= b)
					fout << t << endl;
			}
		}
		else { // length 2n+1
			for (int j = pow(10, i / 2 - 1); j < pow(10, i / 2); j++)
			{
				for (int k = 0; k < 10; k++)
				{
					int t = pow(10, i / 2 + 1) * j + pow(10, i / 2) * k + rev(j); // palindrome
					if (isprime(t) && t >= a && t <= b)
						fout << t << endl;
				}
			}
		}
	}

	return 0;
}