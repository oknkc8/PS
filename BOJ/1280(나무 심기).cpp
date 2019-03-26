#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define cal(x) (x&(-x))
#define MAX 200201
typedef long long ll;

ll d[300000], t[300000];

void update_d(int x, ll a) {
	while (x <= MAX) {
		d[x] += a;
		x += cal(x);
	}
}

ll sum_d(int x) {
	ll ret = 0;
	while (x > 0) {
		ret += d[x];
		x -= cal(x);
	}
	return ret;
}

void update_t(int x, ll a) {
	while (x <= MAX) {
		t[x] += a;
		x += cal(x);
	}
}

ll sum_t(int x) {
	ll ret = 0;
	while (x > 0) {
		ret += t[x];
		x -= cal(x);
	}
	return ret;
}

int main() {
	int n;	scanf("%d", &n);
	ll ans = 1;
	for (int k = 0; k < n; k++) {
		int x;	scanf("%d", &x);
		if (k) {
			ll r = (sum_d(MAX) - sum_d(x + 1)) - x * (sum_t(MAX) - sum_t(x + 1));
			r += x * sum_t(x + 1) - sum_d(x + 1);
			r %= mod;
			ans *= r;
			ans %= mod;
		}
		update_t(x+1, 1);
		update_d(x+1, x);
	}

	printf("%lld", ans);

	return 0;
}
