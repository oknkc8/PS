#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll comb[55][55], dp[55][55], s[55];

void init() {
	comb[1][0] = comb[1][1] = 1;
	for (int i = 2; i <= 51; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	}
}

ll p(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a % mod;
	ll ret = p(a, b / 2);
	if (b & 1) return a * ((ret*ret) % mod) % mod;
	return (ret*ret) % mod;
}

int main() {
	init();
	int n, k;	scanf("%d%d", &n, &k);
	s[0] = n % mod;
	for (int i = 1; i <= k + 1; i++) dp[0][i] = (s[0] * comb[i][0]) % mod;
	for (int i = 1; i <= k; i++) {
		ll a = n + 1;
		for (int j = 2; j <= i + 1; j++) a = (a*(n + 1)) % mod;
		a--;

		if (a < 0) a += mod;
		for (int j = 0; j < i; j++) a = (a - dp[j][i + 1] + mod) % mod;
		s[i] = (a*p(comb[i + 1][i], mod - 2)) % mod;
		for (int j = i; j <= k + 1; j++) dp[i][j] = (s[i] * comb[j][i]) % mod;
	}

	printf("%lld", s[k]);

	return 0;
}