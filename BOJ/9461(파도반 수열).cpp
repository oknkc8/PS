#include<stdio.h>
#pragma  warning(disable:4996)

long long dp[1005];

int main() {
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = 2;

	for (int i = 5; i <= 100; i++) dp[i] = dp[i - 5] + dp[i - 1];

	int t;	scanf("%d", &t);
	while (t-- > 0) {
		int n;	scanf("%d", &n);	printf("%lld\n", dp[n]);
	}

	return 0;
}