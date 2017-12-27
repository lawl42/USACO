/*
ID: lgwong11
LANG: C++11
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, char> alpha;

int main()
{
	alpha.insert({ 'A', '2' });
	alpha.insert({ 'B', '2' });
	alpha.insert({ 'C', '2' });
	alpha.insert({ 'D', '3' });
	alpha.insert({ 'E', '3' });
	alpha.insert({ 'F', '3' });
	alpha.insert({ 'G', '4' });
	alpha.insert({ 'H', '4' });
	alpha.insert({ 'I', '4' });
	alpha.insert({ 'J', '5' });
	alpha.insert({ 'K', '5' });
	alpha.insert({ 'L', '5' });
	alpha.insert({ 'M', '6' });
	alpha.insert({ 'N', '6' });
	alpha.insert({ 'O', '6' });
	alpha.insert({ 'P', '7' });
	alpha.insert({ 'R', '7' });
	alpha.insert({ 'S', '7' });
	alpha.insert({ 'T', '8' });
	alpha.insert({ 'U', '8' });
	alpha.insert({ 'V', '8' });
	alpha.insert({ 'W', '9' });
	alpha.insert({ 'X', '9' });
	alpha.insert({ 'Y', '9' });

	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream namenumdict("dict.txt");

	string name;
	fin >> name;

	int length = name.length();

	string names[5000];
	for (int i = 0, it = 0; i < 5000; i++)
	{
		namenumdict >> names[it];
		if (names[it].length() == length) it++;
		else names[it] = "";
	}

	for (int letter = 0; letter < length; letter++)
	{
		for (int i = 0; i < 5000; i++)
		{
			if (names[i] == "") break;
			else if (names[i] == "123")	continue;
			else
			{
				if (alpha[names[i][letter]] != name[letter]) {
					names[i] = "123";
				}
			}
		}
	}

	int count = false;
	for (int i = 0; i < 5000; i++)
	{
		if (names[i] != "123" && names[i] != "") {
			fout << names[i] << endl;
			count = true;
		}
	}

	if (!count) fout << "NONE" << endl;

	return 0;
}