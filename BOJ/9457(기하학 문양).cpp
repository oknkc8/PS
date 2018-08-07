#include<bits/stdc++.h>
using namespace std;
#define mod 10007

int dp[50005][2];

int main() {
	dp[2][0] = 4, dp[2][1] = 3;
	for (int i = 3; i <= 50000; i++) {
		dp[i][0] = (3 * dp[i - 1][0] + dp[i - 1][1]) % mod;
		dp[i][1] = (2 * dp[i - 1][0] + dp[i - 1][1]) % mod;
	}

	int t;	scanf("%d", &t);
	while (t--) {
		int n;	scanf("%d", &n);
		printf("%d %d\n", dp[n][0], (dp[n][0] + dp[n][1] - 1)*n % mod);
	}

	return 0;
}