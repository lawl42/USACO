/*
ID: lgwong11
TASK: palsquare
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// check if string is palindrome
bool check(string num)
{
	for (int i = 0; i < num.size() / 2; i++)
		if (num[i] != num[num.size() - i - 1])
			return false;
	return true;
}

// change Base 10 to Base N
string base(int num, int base)
{
	string val = "";
	for (int i = 0; true; i++)
	{
		string mod;
		switch (num % base)
		{
			case 10:
				mod = "A";
				break;
			case 11:
				mod = "B";
				break;
			case 12:
				mod = "C";
				break;
			case 13:
				mod = "D";
				break;
			case 14:
				mod = "E";
				break;
			case 15:
				mod = "F";
				break;
			case 16:
				mod = "G";
				break;
			case 17:
				mod = "H";
				break;
			case 18:
				mod = "I";
				break;
			case 19:
				mod = "J";
				break;
			default:
				mod = to_string(num % base);
				break;
		}
		num /= base;
		val.insert(0, mod);

		if (num == 0) break;
	}
	return val;
}

int main(void)
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int B;
	fin >> B;

	for (int i = 1; i <= 300; i++)
	{
		if (check(base(i * i, B)))
			fout << base(i, B) << " " << base(i * i, B) << endl;
	}

	return 0;
}