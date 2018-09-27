#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
typedef long long ll;

ll gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (!y) return x;
	return gcd(y, x%y);
}

int main() {
	while (1) {
		ll n, m;	cin >> n >> m;
		if (!n && !m) break;

//		ll e = 2;
		while (1) {
			ll g = gcd(n, m);
			n /= g, m /= g;
			int flag = 0, a;
			for (ll i = m/n; i <= INF; i++) {
				ll g2 = gcd(m, i), l = m * i / g2;
				ll nt = n * i / g2, it = m / g2;
				ll c = nt - it;
				if (c < 0) continue;
				if (!c) {
					a = i;
					flag = 1;	break;
				}
				ll g3 = gcd(c, l);
				c /= g3, l /= g3;
				if (l <= INF) {
					n = c, m = l, a = i;
					flag = 2;	break;
				}
			}
			if (flag == 2) {
				printf("%d ", a);
	//			e = a;
				continue;
			}
			else if (flag == 1) {
				printf("%d ", a);
				break;
			}
		}
		printf("\n");
	}

	return 0;
}