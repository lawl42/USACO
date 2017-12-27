#include <stdio.h>
#include <string.h>

using namespace std;

char parse(char *s, long index)
{
	if (index < strlen(s))
	{
		return s[(int)index];
	}

	long length = strlen(s);
	while (2 * length <= index)
	{
		length *= 2;
	}

	if (length == index)
	{
		return parse(s, length - 1);
	}
	return parse(s, index - length - 1);
}

int main()
{
	FILE *inf = freopen("cowcode.in", "r", stdin);
	FILE *outf = freopen("cowcode.out", "w", stdout);

	char string[30];
	scanf("%s", string);

	long n;
	scanf(" %ld", &n);

	printf("%c\n", parse(string, n - 1));
	return 0;
}