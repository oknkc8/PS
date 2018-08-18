#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> adj;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;	scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> visit(n + 1);
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		
		queue<int> q;
		int cnt = 0;
		q.push(i), visit[i] = true;
		while (!q.empty()) {
			int now = q.front();
			cnt++, q.pop();
			for (auto i : adj[now]) {
				if (!visit[i]) {
					visit[i] = true;
					q.push(i);
				}
			}
		}
		v.push_back(cnt);
	}
	
	vector<bool> dp(k + 1);
	dp[0] = true;
	for (int i = 0; i < v.size(); i++) {
		for (int j = k; j >= v[i]; j--) {
			if (dp[j - v[i]]) dp[j] = true;
		}
	}

	if (dp[k]) printf("SAFE");
	else printf("DOOMED");

	return 0;
}