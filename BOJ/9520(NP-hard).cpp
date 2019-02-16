#include<bits/stdc++.h>
using namespace std;

int n, dp[1500][1500], v[1500][1500];

int f(int x, int y) {
	int next = max(x, y) + 1;
	if (next == n || dp[x][y]) return dp[x][y];
	return dp[x][y] = min(f(x, next) + v[y][next], f(y, next) + v[x][next]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &v[i][j]);
	
	printf("%d", f(0, 1) + v[0][1]);

	return 0;
}