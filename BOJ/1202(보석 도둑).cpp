#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll c[300005];
priority_queue<pair<int, int>> pq;
multiset<int> mp;

int main() {
	int n, k;	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;	cin >> m >> v;
		pq.push({ v,m });
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		mp.insert(a);
	}

	ll ans=0;
	while (!pq.empty()) {
		int now_m = pq.top().second;
		int now_v = pq.top().first;
		pq.pop();
		auto it = mp.lower_bound(now_m);
		if (it == mp.end()) continue;
		mp.erase(it);
		ans += now_v;
	}

	cout << ans;

	return 0;
}