#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll a[15], dp[(1 << 15) + 1];

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll val(ll x) {
	ll ret = 1;
	for (int i = 0; (1 << i) <= x; i++) {
		if (x&(1<<i)) {
			ret = lcm(ret, a[i]);
			if (ret > n) return 0;
		}
	}
	return n / ret;
}

ll comb(int d, int c, ll b, int s) {
	if (d == c) {
		return dp[b] = val(b);
	}
	if (dp[b]) return dp[b];

	ll ret = 0;
	for (int i = s; i < k; i++) {
		if (!(b&(1<<i))) {
			b |= (1 << i);
			ret += comb(d, c + 1, b, i + 1);
			b &= ~(1 << i);
		}
	}
	return dp[b] = ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> a[i];

	ll ans = n, m = -1;
	for (int i = 1; i <= k; i++) {
		memset(dp, 0, sizeof(dp));
		ans = ans + m * comb(i, 0, 0, 0);
		m *= -1;
	}

	cout << ans;

	return 0;
}