#include<bits/stdc++.h>
using namespace std;

int n, m, v[9][9],visit[9][9];
int ans, cnt, c, dir[4][2] = { -1,0,1,0,0,-1,0,1 };

void dfs(int x, int y) {
	c++;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == 0 && (v[nx][ny] == 0 || v[nx][ny] == 2)) {
			dfs(nx, ny);
		}
	}
}

void func() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visit[i][j] = 0;

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 2 && visit[i][j] == 0) {
				c = 0;
				dfs(i, j);
				cnt += c;
			}
		}
	}
}

int main() {
	int cnt1 = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
			if (v[i][j] == 1) cnt1++;
		}
	}

	for (int a = 0; a < n * m-2; a++) {
		int ax = a / m, ay = a % m;
		if (v[ax][ay] != 0) continue;
		v[ax][ay] = 1;
		for (int b = a + 1; b < n * m - 1; b++) {
			int bx = b / m, by = b % m;
			if (v[bx][by] != 0) continue;
			v[bx][by] = 1;
			for (int c = b + 1; c < n * m; c++) {
				int cx = c / m, cy = c % m;
				if (v[cx][cy] != 0) continue;
				v[cx][cy] = 1;
				cnt = 0;
				func();
				ans = (ans < (n*m-cnt-cnt1-3)) ? (n*m - cnt - cnt1 - 3) : ans;
				v[cx][cy] = 0;
			}
			v[bx][by] = 0;
		}
		v[ax][ay] = 0;
	}

	printf("%d", ans);

	return 0;
}