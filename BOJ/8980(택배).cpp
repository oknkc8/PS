#include<bits/stdc++.h>
using namespace std;

pair<pair<int, int>, int> v[10005];
vector<vector<pair<int, int>>> adj;
int t[2005];

int main() {
	int n, c, m;	cin >> n >> c >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;

	sort(v, v + m);
	for (int i = 0; i < m; i++) {
		adj[v[i].first.first].push_back({ v[i].first.second,v[i].second });
	}

	int ans = 0, cp = 0;
	for (int i = 1; i <= n; i++) {
		ans += t[i], cp -= t[i];
		t[i] = 0;
		for (int j = 0; j < adj[i].size(); j++) {
			cp += adj[i][j].second;
			t[adj[i][j].first] += adj[i][j].second;
		}

		if (cp > c) {
			for (int j = n; j > 0; j--) {
				if (t[j] != 0) {
					cp -= t[j];
					if (cp == c) {
						t[j] = 0;
						break;
					}
					else if (cp < c) {
						int d = c - cp;
						cp = c;
						t[j] = d;
						break;
					}
					t[j] = 0;
				}
			}
		}
	}

	cout << ans;
	
	return 0;
}