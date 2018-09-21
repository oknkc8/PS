#include<bits/stdc++.h>
using namespace std;
#define mod 998244353

int dp[1005][4][2005];

int main() {
	int n, k;	cin >> n >> k;
	dp[1][0][1] = dp[1][3][1] = 1;
	dp[1][1][2] = dp[1][2][2] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 2000; j++) {
			if (dp[i - 1][0][j]) {
				dp[i][0][j] = (dp[i][0][j] + dp[i - 1][0][j]) % mod;
				dp[i][1][j+1] = (dp[i][1][j+1] + dp[i - 1][0][j]) % mod;
				dp[i][2][j+1] = (dp[i][2][j+1] + dp[i - 1][0][j]) % mod;
				dp[i][3][j + 1] = (dp[i][3][j + 1] + dp[i - 1][0][j]) % mod;
			}
			if (dp[i - 1][1][j]) {
				dp[i][0][j] = (dp[i][0][j] + dp[i - 1][1][j]) % mod;
				dp[i][1][j] = (dp[i][1][j] + dp[i - 1][1][j]) % mod;
				dp[i][2][j + 2] = (dp[i][2][j + 2] + dp[i - 1][1][j]) % mod;
				dp[i][3][j] = (dp[i][3][j] + dp[i - 1][1][j]) % mod;
			}
			if (dp[i - 1][2][j]) {
				dp[i][0][j] = (dp[i][0][j] + dp[i - 1][2][j]) % mod;
				dp[i][1][j + 2] = (dp[i][1][j + 2] + dp[i - 1][2][j]) % mod;
				dp[i][2][j] = (dp[i][2][j] + dp[i - 1][2][j]) % mod;
				dp[i][3][j] = (dp[i][3][j] + dp[i - 1][2][j]) % mod;
			}
			if (dp[i - 1][3][j]) {
				dp[i][0][j + 1] = (dp[i][0][j + 1] + dp[i - 1][3][j] % mod);
				dp[i][1][j+1] = (dp[i][1][j+1] + dp[i - 1][3][j]) % mod;
				dp[i][2][j+1] = (dp[i][2][j+1] + dp[i - 1][3][j]) % mod;
				dp[i][3][j] = (dp[i][3][j] + dp[i - 1][3][j]) % mod;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) ans += dp[n][i][k], ans %= mod;
	cout << ans;

	return 0;
}