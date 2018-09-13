#include<bits/stdc++.h>
using namespace std;
#define INF 10000

int v1[105][105], v2[105][105];

int main() {
	int n, m;	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) v1[i][j] = v2[i][j] = INF;
		v1[i][i] = v2[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;	scanf("%d%d", &a, &b);
		v1[a][b] = v2[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v1[i][j] > v1[i][k] + v1[k][j]) v1[i][j] = v1[i][k] + v1[k][j];
				if (v2[i][j] > v2[i][k] + v2[k][j]) v2[i][j] = v2[i][k] + v2[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int c1 = 0, c2 = 0;
		for (int j = 1; j <= n; j++) c1 += (v1[i][j] != INF), c2 += (v2[i][j] != INF);
		printf("%d\n", n - c1 - c2 + 1);
	}

	return 0;
}