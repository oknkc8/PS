#include<bits/stdc++.h>
using namespace std;

int v[105][105];

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int n, m;	scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
			if (i == j) v[i][j] = 0;
			else v[i][j] = 1000000000;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;	scanf("%d%d%d", &a, &b, &c);
			v[a][b] = v[b][a] = c;
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (v[i][j] > v[i][k] + v[j][k]) v[i][j] = v[i][k] + v[j][k];
				}
			}
		}

		int k; scanf("%d", &k);
		vector<int> r(k);
		for (int i = 0; i < k; i++) scanf("%d", &r[i]);
		sort(r.begin(), r.end());
		
		int ans, ans_min = 1000000000;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j : r) s += v[i][j];
			if (ans_min > s) {
				ans_min = s;
				ans = i;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}