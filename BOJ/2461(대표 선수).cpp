#include<bits/stdc++.h>
using namespace std;

int n, m, cnt[1005];
vector<pair<int, int>> v;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;	scanf("%d", &a);
			v.push_back({ a,i });
		}
	}

	sort(v.begin(), v.end());

	int c = 0, s = 0, t = 0, ans=2*(1e9);
	int flag = 0;
	while (t < n*m) {
		if (!cnt[v[t].second]) c++;
		cnt[v[t].second]++;
		t++;
		while (c == n) {
			ans = min(ans, v[t - 1].first - v[s].first);
			cnt[v[s].second]--;
			if (!cnt[v[s].second]) c--;
			s++;
		}
	}
	
	printf("%d", ans);

	return 0;
}