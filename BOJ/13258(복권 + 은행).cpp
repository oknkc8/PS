#include<bits/stdc++.h>
using namespace std;

long double dp[1001][2];

int main() {
	int n, c, j;	scanf("%d", &n);
	scanf("%Lf", &dp[0][0]);
	for (int i = 1; i < n; i++) {
		long double	a;	scanf("%Lf", &a);
		dp[0][1] += a;
	}
	scanf("%d%d", &j, &c);

	for (int i = 1; i <= c; i++) {
		dp[i][0] = dp[i - 1][0] + j * (dp[i - 1][0] / (dp[i - 1][0] + dp[i - 1][1]));
		dp[i][1] = dp[i - 1][1] + j * (dp[i - 1][1] / (dp[i - 1][0] + dp[i - 1][1]));
	}

	printf("%.12Lf", dp[c][0]);

	return 0;
}