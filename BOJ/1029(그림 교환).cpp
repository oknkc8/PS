#include<bits/stdc++.h>
using namespace std;

int n, dp[16][1 << 15 + 5][10], v[16][16];

int f(int x, int val, int flag, int d) {
	int &ret = dp[x][flag][val];
	
	if (ret) return ret;

	ret = d;
	for (int i = 0; i < n; i++) {
		if (!(flag&(1 << i)) && val <= v[x][i]) {
			ret = max(ret, f(i, v[x][i], flag | (1 << i), d + 1));
		}
	}
	//ret++;
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%1d", &v[i][j]);

	printf("%d", f(0, 0, 1, 1));

	return 0;
}