#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
pair<ll, ll> v[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld%lld", &v[i].second, &v[i].first);

	sort(v, v + n);

	int h = 0, t = n - 1;
	ll ans = 0;
	while (h<=t) {
		ans = max(ans, v[h].first + v[t].first);
		if (v[h].second == v[t].second) {
			v[h].second = v[t].second = 0;
			h++, t--;
		}
		else if (v[h].second > v[t].second) {
			v[h].second -= v[t].second;
			v[t].second = 0;
			t--;
		}
		else {
			v[t].second -= v[h].second;
			v[h].second = 0;
			h++;
		}
	}

	printf("%lld", ans);

	return 0;
}