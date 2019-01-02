#include<bits/stdc++.h>
using namespace std;

int r, c;
char mp[100005][501];
int check[10005][501];
int d[3][2] = { -1,1,0,1,1,1 };

int f(int x, int y) {
	check[x][y] = 1;
	if (y == c - 1) {
		return 1;
	}
	int flag = 0;
	for (int i = 0; i < 3; i++) {
		int nx = x + d[i][0], ny = y + d[i][1];
		if (0 <= nx < c && 0 <= ny < r && mp[nx][ny] == '.' && !check[nx][ny]) {
			flag = f(nx, ny);
			if (flag) return 1;
		}
	}
	return 0;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> mp[i];
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		ans += f(i, 0);
	}
	cout << ans;

	return 0;
}