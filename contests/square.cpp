#include <stdio.h>
#include <stdlib.h>

int find_max(int i1, int i2, int i3, int i4) {
	int max = i1;

	if (i2 > max) {
		max = i2;
	}
	if (i3 > max) {
		max = i3;
	}
	if (i4 > max) {
		max = i4;
	}

	return max;
}

int main() {
	FILE *inf = freopen("square.in", "r", stdin);
	FILE *outf = freopen("square.out", "w", stdout);

	// get the data
	int square1[4], square2[4];

	for (int i = 0; i < 4; i++) {
		scanf("%d", &square1[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &square2[i]);
	}

	// analyze the data
	int total_width = find_max(abs(square1[2] - square2[0]), abs(square2[2] - square1[0]), abs(square1[2] - square1[0]), abs(square2[2] - square2[0]));
	int total_height = find_max(abs(square1[3] - square2[1]), abs(square2[3] - square1[1]), abs(square1[3] - square1[1]), abs(square2[3] - square2[1]));

	if (total_width > total_height) {
		printf("%d", total_width * total_width);
	}
	else {
		printf("%d", total_height * total_height);
	}


	return 0;
}