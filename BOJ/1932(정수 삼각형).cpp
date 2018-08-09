#include<stdio.h>
#pragma warning(disable:4996)

int n, v[505][505], d[505][505];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) scanf("%d", &v[i][j]);
	}

	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0)	d[i][j] = v[i][j];
			else if (j == 0) d[i][j] = d[i - 1][j] + v[i][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1] + v[i][j];
			else {
				if (d[i - 1][j - 1] > d[i - 1][j]) d[i][j] = d[i - 1][j - 1] + v[i][j];
				else d[i][j] = d[i - 1][j] + v[i][j];
			}

			if (i == n - 1 && m < d[i][j]) m = d[i][j];
		}
	}
	printf("%d", m);

	return 0;
}