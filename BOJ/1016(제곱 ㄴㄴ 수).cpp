#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000001

bool check[INF], p[INF];

int main() {
	ll a, b;	scanf("%lld%lld", &a, &b);

	int ans = b - a + 1;
	for (ll i = 2; i*i <= b; i++) {
		if (p[i]) continue;
		for (ll j = i; j*j <= b; j += i) p[j] = 1;
		for (ll j = ((a - 1) / (i*i) + 1)*(i*i); j <= b; j += i * i) if (!check[j - a]) check[j - a] = 1, ans--;
	}
	printf("%d", ans);

	return 0;
}