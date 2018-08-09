#include<stdio.h>
#pragma warning(disable:4996)

int d[1001][1001], v[1001][1001];

int max(int a, int b, int c) {
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &v[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) d[i][j] = v[i][j];
			else if (i == 0) d[i][j] = d[i][j - 1] + v[i][j];
			else if (j == 0) d[i][j] = d[i - 1][j] + v[i][j];
			else {
				d[i][j] = v[i][j] + max(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
			}
		}
	}

	printf("%d", d[n - 1][m - 1]);

	return 0;
}