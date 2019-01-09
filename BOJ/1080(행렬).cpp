#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[50][50], b[50][50], ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &b[i][j]);

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] == b[i][j]) continue;
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					if (a[x][y]) a[x][y] = 0;
					else a[x][y] = 1;
				}
			}
			ans++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", ans);


	return 0;
}