#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll v[500005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
	sort(v, v + n);

	ll ans = 0;
	for (int i = 0; i < n; i++) ans += abs(v[i] - i - 1);

	printf("%lld", ans);

	return 0;
}