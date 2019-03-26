#include<bits/stdc++.h>
using namespace std;
#define cal(x) (x&(-x))
typedef long long ll;

ll n, q, tree[4000006];

void update(int x, ll v) {
	while (x <= n) {
		tree[x] += v;
		x += cal(x);
	}
}

ll sum(int x) {
	ll ret = 0;
	while (x > 0) {
		ret += tree[x];
		x -= cal(x);
	}
	return ret;
}

int main() {
	scanf("%lld%lld", &n, &q);
	while (q--) {
		int a;	scanf("%d", &a);
		if (a == 1) {
			ll p, x;	scanf("%lld%lld", &p, &x);
			update(p, x);
		}
		else {
			ll p, q;	scanf("%lld%lld", &p, &q);
			printf("%lld\n", sum(q) - sum(p - 1));
		}
	}

	return 0;
}