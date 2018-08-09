#include<stdio.h>
#define mod 1000000000

int n, k, dp[205][205];

int main() {
	for (int i = 0; i <= 200; i++) dp[0][i] = 1;
	for (int i = 1; i <= 200; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= 200; j++) {
			for (int k = 0; k <= i; k++) {
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % mod;
			}
		}
	}

	scanf("%d%d", &n, &k);
	printf("%d", dp[n][k]);

	return 0;
}