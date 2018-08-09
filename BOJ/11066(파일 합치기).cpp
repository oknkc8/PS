#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int dp[505][505];

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int n, v[505], s[505] = { 0, }, ans = 0;	scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]), s[i] = s[i - 1] + v[i];

		for (int j = 2; j <= n; j++) {
			for (int i = j - 1; i > 0; i--) {
				dp[i][j] = 210000000;
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				dp[i][j] += (s[j] - s[i - 1]);
			}
		}
		printf("%d\n", dp[1][n]);
	}

	return 0;
}