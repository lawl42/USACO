/*
PROB: milk3
ID: lgwong11
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int A, B, C;
unordered_set<string> milk;

void pour(string a, string b, string c)
{
	if (milk.find(a + '/' + b + '-' + c) == milk.end())
	{
		milk.insert(a + '/' + b + '-' + c);
		cout << a + b + c << endl;

		int tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		cout << tempa << tempb << tempc << endl;

		while (tempa != 0 && tempb != B)
		{
			tempa--;
			tempb++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));

		tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		while (tempa != 0 && tempc != C)
		{
			tempa--;
			tempc++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));

		tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		while (tempb != 0 && tempa != A)
		{
			tempb--;
			tempa++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));

		tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		while (tempb != 0 && tempc != C)
		{
			tempb--;
			tempc++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));

		tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		while (tempc != 0 && tempa != A)
		{
			tempc--;
			tempa++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));

		tempa = stoi(a), tempb = stoi(b), tempc = stoi(c);
		while (tempc != 0 && tempb != B)
		{
			tempc--;
			tempb++;
		}
		pour(to_string(tempa), to_string(tempb), to_string(tempc));
	}
	else {
		return;
	}
}

int main()
{
	fin >> A >> B >> C;
	
	pour("0", "0", to_string(C));

	vector<int> ans;
	for (auto it = milk.begin(); it != milk.end(); ++it)
	{
		string str = *it;
		if (str[0] == '0')
		{
			auto i = str.find('-');
			str = str.substr(i + 1);
			ans.push_back(stoi(str));
		}
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size() - 1; i++)
		fout << ans[i] << " ";
	fout << ans.back() << endl;

	return 0;
}