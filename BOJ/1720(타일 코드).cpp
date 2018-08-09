#include<stdio.h>

int dp[33];

int main() {
	int n;	scanf("%d", &n);
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + 2 * dp[i - 2];

	printf("%d", dp[n] - (dp[n] - dp[(n % 2) ? (n - 1) / 2 : (n / 2 + 1)]) / 2);

	return 0;
}