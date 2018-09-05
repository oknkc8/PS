#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

int main() {
	int t;	cin >> t;
	while (t--) {
		int n, m, l, g;	cin >> n >> m >> l >> g;
		vector<vector<int>> v1(n), v2(n - 1);
		vector<vector<pair<int, int>>> dp(n);
		for (int i = 0; i < n; i++) {
			v1[i].resize(m - 1), dp[i].resize(m, { INF,0 });
			for (int j = 0; j < m - 1; j++) cin >> v1[i][j];
		}
		for (int i = 0; i < n - 1; i++) {
			v2[i].resize(m);
			for (int j = 0; j < m; j++) cin >> v2[i][j];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!i) {
					if (!j) dp[i][j].first = 0;
					else {
						if (dp[i][j - 1].first != INF) {
							if (dp[i][j - 1].second + v1[i][j - 1] <= g) {
								dp[i][j].second = dp[i][j - 1].second + v1[i][j - 1];
								dp[i][j].first = dp[i][j - 1].first + l;
							}
						}
					}
				}
				else {
					if (!j) {
						if (dp[i - 1][j].first != INF) {

						}
					}
				}
			}
		}
	}

	return 0;
}