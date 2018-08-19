#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[25][25];

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

ll solve(ll n, ll m) {
	if (n == 0) return 1;
	if (m == 0) return 0;

	ll &ret = dp[n][m];
	if (ret) return dp[n][m];

	return dp[n][m] = solve(n - 1, m - 1) + (n - 1)*solve(n - 1, m);
}

int main() {
	int n, m;	scanf("%d%d", &n, &m);
	ll a = solve(n, m), b = solve(n, n);
	ll g = gcd(a, b);

	printf("%lld/%lld", a / g, b / g);

	return 0;
}