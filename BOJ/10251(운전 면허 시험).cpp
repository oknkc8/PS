#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

struct info {
	int l = 0, f = 0;
};

int v1[105][105], v2[105][105];
int dp[105][105][105][2];

int main() {
	int t;	cin >> t;
	while (t--) {
		int n, m, l, g;	cin >> n >> m >> l >> g;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < m; j++) cin >> v1[i][j];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) cin >> v2[i][j];
		}

		memset(dp, 0x3f, sizeof(dp));
		dp[1][1][1][0] = dp[1][1][1][1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k <= 100; k++) {
					int f0 = v1[i][j - 1], f1 = v2[i - 1][j];
					int e0 = min(dp[i][j - 1][k][0], dp[i][j - 1][k - 1][1]);
					int e1 = min(dp[i - 1][j][k][1], dp[i - 1][j][k - 1][0]);
					dp[i][j][k][0] = min(dp[i][j][k][0], f0 + e0);
					dp[i][j][k][1] = min(dp[i][j][k][1], f1 + e1);
				}
			}
		}

		int ans = -1;
		for (int i = 100; i >= 0; i--) {
			if (dp[n][m][i][0] <= g) ans = i;
			if (dp[n][m][i][1] <= g) ans = i;
		}

		if (ans < 0) printf("-1\n");
		else printf("%d\n", (n + m - 2)*l + ans - 1);
	}

	return 0;
}