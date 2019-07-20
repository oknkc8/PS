#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, mp[1001][1001];
int d[2][1001][1001];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
queue<pair<int, pair<int, int>>> q;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		scanf("%1d", &mp[i][j]);
		d[0][i][j] = d[1][i][j] = INF;
	}

	d[0][0][0] = 1;
	q.push({ 0,{0,0} });
	while (!q.empty()) {
		int flag = q.front().first;
		int x = q.front().second.first, y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!flag) {
					if (!mp[nx][ny] && d[0][nx][ny] > d[0][x][y] + 1) {
						d[0][nx][ny] = d[0][x][y] + 1;
						q.push({ 0,{nx,ny} });
					}
					else if (mp[nx][ny] && d[1][nx][ny] > d[0][x][y] + 1) {
						d[1][nx][ny] = d[0][x][y] + 1;
						q.push({ 1,{nx,ny} });
					}
				}
				else {
					if (!mp[nx][ny] && d[1][nx][ny] > d[1][x][y] + 1) {
						d[1][nx][ny] = d[1][x][y] + 1;
						q.push({ 1,{ nx,ny } });
					}
				}
			}
		}
	}

	if (d[0][n - 1][m - 1] == INF && d[1][n - 1][m - 1] == INF) printf("-1");
	else printf("%d", min(d[0][n - 1][m - 1], d[1][n - 1][m - 1]));


	return 0;
}