#include<bits/stdc++.h>
using namespace std;

int n, m, dist[505];
vector<pair<pair<int, int>, int>> edge;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;	cin >> a >> b >> c;
		edge.push_back({ {a,b},c });
	}

	fill(dist+1, dist + n+1, 1e9);

	dist[1] = 0;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < m; i++) {
			if (dist[edge[i].first.second] > dist[edge[i].first.first] + edge[i].second && dist[edge[i].first.first] != 1e9) {
				dist[edge[i].first.second] = dist[edge[i].first.first] + edge[i].second;
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < m; i++) {
		if (dist[edge[i].first.second] > dist[edge[i].first.first] + edge[i].second && dist[edge[i].first.first]!=1e9) {
			flag = 1;	break;
		}
	}

	if (flag) {
		printf("-1");
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == 1e9) printf("-1\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}