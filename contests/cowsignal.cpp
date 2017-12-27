#include <stdio.h>
#include <string.h>

int main() {
	FILE *inf = freopen("cowsignal.in", "r", stdin);
	FILE *outf = freopen("cowsignal.out", "w", stdout);

	// get data
	int M, N, K;
	scanf("%d", &M);
	scanf("%d", &N);
	scanf("%d", &K);
	
	// variables
	char new_line[100];
	char temp;

	// the real code
	for (int row = 0; row < M; row++) {
		scanf("%c", &temp);
		for (int col = 0; col < N; col++) {
			scanf("%c", &temp);
			for (int times_bigger = 0; times_bigger < K; times_bigger++) {
				new_line[(col * K) + times_bigger] = temp;
			}
		}

		new_line[N * K] = '\0';
		for (int times_bigger = 0; times_bigger < K; times_bigger++) {
			for (int length = 0; length < N * K; length++) {
				printf("%c", new_line[length]);
			}
			printf("\n");
		}
	}

	fclose(inf);
	fclose(outf);
	return 0;
}