#include <stdio.h>

int main() {
	FILE *inf = freopen("blocks.in", "r", stdin);
	FILE *outf = freopen("blocks.out", "w", stdout);

	// vars
	int N; // Number of Boards
	char words[100][2][10];
	int alphabets[200][26] = { 0 };

	// get data
	scanf("%d", &N);
	for (int board = 0; board < N; board++) {
		for (int side = 0; side < 2; side++) {
			scanf("%s", words[board][side]);
			
			// record letters in each word
			for (int word = 0; words[board][side][word] != '\0'; word++) {
				alphabets[(board * 2) + side][words[board][side][word] - 97]++;
			}
		}
	}

	// analyze data
	for (int board = 0; board < (N * 2); board+=2) {
		for (int i = 0; i < 26; i++) {
			alphabets[board][i] = alphabets[board][i] > alphabets[board + 1][i] ? alphabets[board][i] : alphabets[board + 1][i];
		}
	}
	for (int board = 2; board < (N * 2); board += 2) {
		for (int i = 0; i < 26; i++) {
			alphabets[0][i] += alphabets[board][i];
		}
	}

	// print answer
	for (int i = 0; i < 26; i++) {
		printf("%d\n", alphabets[0][i]);
	}


	fclose(inf);
	fclose(outf);
	return 0;
}