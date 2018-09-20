#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int test;	scanf("%d", &test);
	while (test--) {
		int n, m, t;	scanf("%d%d%d", &n, &m, &t);
		int s, g, h, val;	scanf("%d%d%d", &s, &g, &h);
		
		vector<vector<pair<int, int>>> adj(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, d;	scanf("%d%d%d", &a, &b, &d);
			adj[a].push_back({ d,b });
			adj[b].push_back({ d,a });
			if ((a == g && b == h) || (a == h && b == g)) val = d;
		}

		vector<int> x(t), dist(n + 1, INF), dist_h(n + 1, INF), dist_g(n + 1, INF), ans;
		for (int i = 0; i < t; i++) scanf("%d", &x[i]);

		priority_queue<pair<int, int>> pq;
		dist[s] = 0;
		pq.push({ 0,s });
		while (!pq.empty()) {
			int now = pq.top().second;
			int distance = -pq.top().first;
			pq.pop();
			for (auto i : adj[now]) {
				int togo = i.second, togo_dist = distance + i.first;
				if (dist[togo] > togo_dist) {
					dist[togo] = togo_dist;
					pq.push({ -dist[togo], togo });
				}
			}
		}

		dist_g[g] = 0;
		pq.push({ 0,g });
		while (!pq.empty()) {
			int now = pq.top().second;
			int distance = -pq.top().first;
			pq.pop();
			for (auto i : adj[now]) {
				int togo = i.second, togo_dist = distance + i.first;
				if (dist_g[togo] > togo_dist) {
					dist_g[togo] = togo_dist;
					pq.push({ -dist_h[togo], togo });
				}
			}
		}

		dist_h[h] = 0;
		pq.push({ 0,h });
		while (!pq.empty()) {
			int now = pq.top().second;
			int distance = -pq.top().first;
			pq.pop();
			for (auto i : adj[now]) {
				int togo = i.second, togo_dist = distance + i.first;
				if (dist_h[togo] > togo_dist) {
					dist_h[togo] = togo_dist;
					pq.push({ -dist_h[togo], togo });
				}
			}
		}

		for (auto i : x) {
			if (dist[g] + val + dist_h[i] == dist[i] || dist[h] + val + dist_g[i] == dist[i]) ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		for (auto i : ans) printf("%d ", i);
		printf("\n");
	}

	return 0;
}