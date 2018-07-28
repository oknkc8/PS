#include<stdio.h>
#define mod 1000000007
typedef long long ll;

ll dp[100005] = { 0,0,1 };

int main() {
	int n;	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		dp[i] = (i - 1)*(dp[i - 1] + dp[i - 2]);
		dp[i] %= mod;
	}

	ll ans = 1;
	for (ll i = 1; i <= n; i++) ans *= i, ans %= mod;
	ans *= dp[n], ans %= mod;

	printf("%lld", ans);

	return 0;
}