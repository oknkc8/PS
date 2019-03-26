#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
pair<int, int> v[100005];
vector<vector<int>> c;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &v[i].first, &v[i].second);

	sort(v, v + n);
	c.resize(n + 1);

	for (int i = 0; i < n; i++)	c[v[i].second].push_back(v[i].first);

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i].size() > 1) {
			for (int j = 0; j < c[i].size(); j++) {
				if (j == 0) ans += c[i][j + 1] - c[i][j];
				else if (j == c[i].size() - 1) ans += c[i][j] - c[i][j - 1];
				else ans += min(c[i][j] - c[i][j - 1], c[i][j + 1] - c[i][j]);
			}
		}
	}

	printf("%lld", ans);

	return 0;
}