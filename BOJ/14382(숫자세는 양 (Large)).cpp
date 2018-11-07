#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(ll x, ll y) {
	while (y) {
		x |= (1 << (y % 10));
		y /= 10;
	}
	return x;
}

int main() {
	int t, c = 0;	cin >> t;
	while (t--) {
		ll n;	cin >> n;
		ll ch = 0;
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", ++c);
			continue;
		}

		ll ans;
		for (ll i = 1;; i++) {
			ch = check(ch, i*n);
			if (ch == (1 << 10) - 1) {
				ans = i * n;
				break;
			}
		}
		printf("Case #%d: %lld\n", ++c, ans);
	}

	return 0;
}