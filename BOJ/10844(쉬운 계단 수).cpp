#include<stdio.h>
#define mod 1000000000

int dp[104][10];

int main() {
	int n;	scanf("%d", &n);
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1], dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
	}
	int s = 0;
	for (int i = 0; i < 10; i++) s = (s + dp[n][i]) % mod;
	printf("%d", s);
}