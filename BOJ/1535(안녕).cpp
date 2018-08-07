#include<bits/stdc++.h>
using namespace std;

int n, a[22], b[22], dp[22][101];

int f(int x, int l) {
	if (dp[x][l]) return dp[x][l];
	
	int &ret = dp[x][l];
	if (x > n) return 0;
	if (l - a[x] > 0) ret = f(x + 1, l - a[x]) + b[x];

	int t = f(x + 1, l);
	ret = ret > t ? ret : t;
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

	printf("%d", f(1, 100));

	return 0;
}