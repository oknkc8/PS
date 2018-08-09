#include<stdio.h>
#include<algorithm>
using namespace std;

int v[1005][1005], n, m, ans, dp[1005][1005];
char t[1005][1005];

int min(int a, int b) { return (a < b) ? a : b; }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", t[i]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) v[i][j] = t[i - 1][j - 1] - '0';

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j]) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				ans = (ans > dp[i][j]) ? ans : dp[i][j];
			}
		}
	}

	printf("%d", ans*ans);

	return 0;
}