#include<bits/stdc++.h>
using namespace std;

struct info {
	int s, i, p;
};
int n, dp[1005][1005];
bool visit[105];
info v[105];

int f(int x, int y) {
	int &ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 0;
	vector<int> t;
	int cnt = 0, point=0;
	for (int i = 0; i < n; i++) {
		if (v[i].s <= x || v[i].i <= y) {
			if (!visit[i]) {
				t.push_back(i);
				point += v[i].p;
				visit[i] = true;
			}
			cnt++;
		}
	}
	ret = cnt;

	for (int i = x; i <= min(1000, x + point); i++) {
		int j = min(1000, point - (i - x) + y);
		ret = max(ret, f(i, j));
	}
	//ret += cnt;
	for (auto i : t) visit[i] = false;

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &v[i].s, &v[i].i, &v[i].p);

	memset(dp, -1, sizeof(dp));
	printf("%d", f(1, 1));

	return 0;
}