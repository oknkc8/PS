#include<bits/stdc++.h>
using namespace std;

int arr[301][301], n, m;
int dp[301][301];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);

	dp[1][1] = arr[1][1];
	for (int i = 2; i <= m; i++)
		dp[1][i] = dp[1][i - 1] + arr[1][i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	int t;	scanf("%d", &t);
	while (t--) {
		int i, j, x, y;
		scanf("%d%d%d%d", &i, &j, &x, &y);
		printf("%d\n", dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1]);
	}

	return 0;
}