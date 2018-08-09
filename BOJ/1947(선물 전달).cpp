#include<stdio.h>
#pragma warning(disable:4996)
#define N 1000000000

long long dp[1000005];

int main() {
	int n;	scanf("%d", &n);
	dp[1] = 0, dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = (((dp[i - 1] + dp[i - 2]) % N)*(i - 1)) % N;
	}

	printf("%lld", dp[n]);

	return 0;
}