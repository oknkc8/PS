#include<bits/stdc++.h>
using namespace std;

int f(int n, int m, vector<string> v, int x, int y) {
	int ret = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < m; j++) if (v[i][j] != 'W') ret++;
	}
	for (int i = x + 1; i <= y; i++) {
		for (int j = 0; j < m; j++) if (v[i][j] != 'B') ret++;
	}
	for (int i = y + 1; i < n; i++) {
		for (int j = 0; j < m; j++) if (v[i][j] != 'R') ret++;
	}

	return ret;
}

int main() {
	int t, c = 0;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<string> v(n);
		for (int i = 0; i < n; i++)	cin >> v[i];

		int ans = 1000000000;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				ans = min(f(n, m, v, i, j), ans);
			}
		}

		printf("#%d %d\n", ++c, ans);
	}

	return 0;
}