#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq1, pq2;
int n, m, p[1005], s1, s2;

void init() {
	for (int i = 0; i <= n; i++) p[i] = i;
}

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; i++) {
		int a, b, w;	scanf("%d%d%d", &a, &b, &w);
		w = !w;
		pq1.push({ -w,{a,b} });
		pq2.push({ w,{a,b} });
	}

	init();
	while (!pq1.empty()) {
		int x, y, w;
		x = pq1.top().second.first;
		y = pq1.top().second.second;
		w = -pq1.top().first;
		pq1.pop();
		
		int px = find(x), py = find(y);
		if (px != py) p[px] = py, s1 += w;
	}
	
	init();
	while (!pq2.empty()) {
		int x, y, w;
		x = pq2.top().second.first;
		y = pq2.top().second.second;
		w = pq2.top().first;
		pq2.pop();

		int px = find(x), py = find(y);
		if (px != py) p[px] = py, s2 += w;
	}

	printf("%d", s2*s2 - s1*s1);

	return 0;
}