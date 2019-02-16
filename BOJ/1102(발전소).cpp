#include<bits/stdc++.h>
using namespace std;

int n, v[16][16], p, start;
int dp[(1 << 16) + 1];
int ans = 1e9;

bool check(int state) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (state&(1 << i)) c++;
	}
	if (c >= p) return 1;
	return 0;
}

void f(int state, int val) {
	if (check(state)) {
		ans = min(ans, val);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!(state&(1 << i))) {
			int togo_state = state | (1 << i);
			for (int j = 0; j < n; j++) {
				if (state&(1 << j) && (dp[togo_state]==-1||dp[togo_state]>dp[state]+v[j][i])) {
					dp[togo_state] = dp[state] + v[j][i];
					f(togo_state, dp[togo_state]);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
	string str;	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'Y') start |= (1 << i);
	}
	cin >> p;

	memset(dp, -1, sizeof(dp));
	dp[start] = 0;
	f(start, 0);

	if (ans == 1e9) cout << "-1";
	else cout << ans;

	return 0;
}