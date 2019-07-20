
#include<bits/stdc++.h>
using namespace std;

int dp[4][10001], t[4][10001];
int v[4] = { 1,5,10,25 }, c[4];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < 4; i++) cin >> c[i];

	for (int i = 1; i <= c[0]; i++) dp[0][i] = i, t[0][i] = i;

	for (int i = 1; i < 4; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= c[i]; k++) {
				if (j < k*v[i]) {
					if (dp[i][j] < dp[i - 1][j]) {
						dp[i][j] = dp[i - 1][j];
						t[i][j] = 0;
					}
				}
				else {
					if (!dp[i][j]) {
						if (dp[i - 1][j] < dp[i-1][j - k * v[i]] + k && (dp[i - 1][j - k * v[i]] !=0 || j-k*v[i] ==0)) {
							dp[i][j] = dp[i-1][j - k * v[i]] + k;
							t[i][j] = k;
						}
						else {
							dp[i][j] = dp[i - 1][j];
							t[i][j] = 0;
						}
					}
					else {
						if (dp[i][j] < dp[i-1][j - k * v[i]] + k && (dp[i - 1][j - k * v[i]] != 0 || j - k * v[i] == 0)) {
							dp[i][j] = dp[i-1][j - k * v[i]] + k;
							t[i][j] = k;
						}
					}
				}
			}
		}
	}

	int x = n;
	vector<int> ans;
	for (int i = 3; i >= 0; i--) {
		ans.push_back(t[i][x]);
		x -= t[i][x] * v[i];
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans) cout << i << " ";

	return 0;
}