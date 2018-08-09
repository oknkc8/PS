#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	while (1) {
		int n, m;
		vector<vector<int>> v, dp;
		vector<int> max_col, max_raw;

		scanf("%d%d", &n, &m);
		if (!n && !m) return 0;
		v.resize(n + 1);		dp.resize(n + 1);	max_col.resize(n + 1);		max_raw.resize(n + 1);		max_raw[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i].resize(m + 1);
			v[i].resize(m + 1);
			for (int j = 1; j <= m; j++) scanf("%d", &v[i][j]);
		}

		int ans = 0;
		// 1,2¹øÂ° ÁÙ
		for (int i = 1; i <= 2 && i <= n; i++) {
			int t = 0, tt = 0;
			for (int j = 1; j <= m; j++) {
				if (j - 2 <= 0) dp[i][j] = v[i][j];
				else {
					t = (t > dp[i][j - 2]) ? t : dp[i][j - 2];
					dp[i][j] = t + v[i][j];
				}
				tt = (tt > dp[i][j]) ? tt : dp[i][j];
			}
			max_col[i] = tt;
			max_raw[i] = (max_raw[i - 1] > max_col[i]) ? max_raw[i - 1] : max_col[i];
			ans = (ans > max_raw[i]) ? ans : max_raw[i];
		}

		for (int i = 3; i <= n; i++) {
			int t = 0, tt = 0;
			for (int j = 1; j <= m; j++) {
				if (j - 2 <= 0) dp[i][j] = max_raw[i - 2] + v[i][j];
				else {
					t = (t > dp[i][j - 2]) ? t : dp[i][j - 2];
					dp[i][j] = ((max_raw[i - 2] > t) ? max_raw[i - 2] : t) + v[i][j];
				}
				tt = (tt > dp[i][j]) ? tt : dp[i][j];
			}
			max_col[i] = tt;
			max_raw[i] = (max_raw[i - 1] > max_col[i]) ? max_raw[i - 1] : max_col[i];
			ans = (ans > max_raw[i]) ? ans : max_raw[i];
		}

		printf("%d\n", ans);
	}

	return 0;
}