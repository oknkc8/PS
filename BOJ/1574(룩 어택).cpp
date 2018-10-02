#include<bits/stdc++.h>
using namespace std;

int mp[305][305];
vector<vector<int>> adj;
vector<bool> visit;
vector<int> match;

int BM(int x) {
	if (visit[x]) return 0;
	visit[x] = 1;
	for (auto i : adj[x]) {
		if (match[i] == -1 || BM(match[i])) {
			match[i] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	int n, m, k;	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b;	cin >> a >> b;
		mp[a - 1][b - 1] = 1;
	}

	adj.resize(n), match.resize(m, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!mp[i][j]) adj[i].push_back(j);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		visit = vector<bool>(n, false);
		ans += BM(i);
	}

	cout << ans;

	return 0;
}