#include<bits/stdc++.h>
using namespace std;

struct info {
	int x, y;
};

int n, v[55][55], cnt, c[55][55], flag, ct;
int dir[8][2] = { -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1 };
char m[55][55];
info start;
vector<int> s;

void dfs(int x, int y, int p1, int p2) {
	c[x][y] = 1;
	ct -= m[x][y] == 'K';
	if (!ct) {
		flag = 1;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !c[nx][ny] && p1<=v[nx][ny] && v[nx][ny]<=p2) {
			dfs(nx, ny, p1, p2);
			if (flag) return;
		}
	}
}

bool check(int p1, int p2) {
	if (v[start.x][start.y] < p1 || p2 < v[start.x][start.y]) return false;
	memset(c, 0, sizeof(c));
	flag = 0;
	ct = cnt;
	dfs(start.x, start.y, p1, p2);
	if (flag) return true;
	else return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", m[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
			s.push_back(v[i][j]);
			if (m[i][j] == 'P') start.x = i, start.y = j;
			cnt += m[i][j] == 'K';
		}
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	int ans = 1000005;
	for (int i = 0; i < s.size(); i++) {
		int h = i, t = s.size() - 1;
		while (h < t) {
			int m = (h + t) / 2;
			if (check(s[i], s[m])) t = m;
			else h = m + 1;
		}
		if (check(s[i], s[h])) ans = min(ans, s[h] - s[i]);
	}
	
	printf("%d", ans);

	return 0;
}