#include<stdio.h>

long long dp[100], sum[100];

int find(long long x) {
	if (x == 0) return 0;
	for (int i = 0;; i++) {
		if (sum[i] < x && x <= sum[i + 1]) return i + 1;
	}
}

int main() {
	dp[1] = dp[2] = 1;
	for (int i = 3;; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 1e18) break;
	}
	sum[1] = dp[1];
	for (int i = 2;; i++) {
		sum[i] = sum[i - 1] + dp[i];
		if (sum[i] > 1e18) break;
	}


	long long k;		scanf("%lld", &k);
	int n = find(k);
	if (n == 1) {
		printf("1");	return 0;
	}
	else if (n == 2) {
		printf("10");	return 0;
	}
	while (1) {
		printf("10"); k -= (dp[n] + dp[n - 1]);
		int f = find(k);
		n -= 2;
		for (int i = n; i > f; i--) printf("0"), n--;
		if (f == 1) {
			printf("1"); break;
		}
		else if (!f) break;
	}

	return 0;
}