#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000000

ll dp[110][11][1 << 11];

ll f(int n, int x, int s) {
	if (x < 0 || x>9) return 0;
	if (n == 1) {
		if ((s | (1 << x)) == (1 << 10) - 1) return 1;
		else return 0;
	}

	ll &ret = dp[n][x][s];
	if (ret != -1) return dp[n][x][s];
	s |= (1 << x);
	return ret = (f(n - 1, x - 1, s) + f(n - 1, x + 1, s)) % mod;
}

int main() {
	int n;	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i < 10; i++) ans = (ans + f(n, i, 0)) % mod;

	printf("%lld", ans);

	return 0;
}