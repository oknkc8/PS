#include<bits/stdc++.h>
using namespace std;

int n, m, adj[205][205], p[205], t[205];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
			if (adj[i][j]) {
				uni(i, j);
			}
		}
	}
	scanf("%d", &t[0]);
	int first_des = find(t[0]);
	for (int i = 1; i < m; i++) {
		scanf("%d", &t[i]);
		int td = find(t[i]);
		if (first_des != td && first_des != -1) {
			printf("NO\n");
			first_des = -1;
		}
	}
	if(first_des>=0)
		printf("YES\n");

	return 0;
}