#include<bits/stdc++.h>
using namespace std;

int n, p[105];
double adj[105][105];
pair<double, double> xy[105];
priority_queue<pair<double, pair<int, int>>> pq;

double dist(int i, int j) {
	return sqrt((xy[i].first - xy[j].first)*(xy[i].first - xy[j].first)
		+ (xy[i].second - xy[j].second)*(xy[i].second - xy[j].second));
}

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &xy[i].first, &xy[i].second);
		p[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj[i][j] = dist(i, j);
			pq.push({ -adj[i][j],{i,j} });
		}
	}

	int a, b;
	double c, ans = 0;
	while (!pq.empty()) {
		a = pq.top().second.first;
		b = pq.top().second.second;
		c = -pq.top().first;
		pq.pop();

		a = find(a), b = find(b);
		if (a == b) continue;
		ans += c;

		p[a] = b;
	}

	printf("%.2lf", ans);

	return 0;
}