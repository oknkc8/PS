#include<bits/stdc++.h>
using namespace std;

int dp[11][250][250];	// [i][j][k] : i���� ������ ���� k�� ��
						//			   ������ ù��° ���� j�� �� ����� ��

int main() {
	int n, m, k;	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) dp[1][i][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m / i; j++) {
			for (int t = i * j; t <= m; t++) {
				for (int l = j; l <= t / (i - 1); l++) {
					dp[i][j][t] += dp[i - 1][l][t - j];
				}
			}
		}
	}

	int sum = 0, s=1;
	vector<int> ans;
	while(n){
		for (int i = s; i <= m / n; i++) {
			//if (sum + dp[n][i][m] >= k) {
			if (dp[n][i][m] >= k) {
				ans.push_back(i);
				s = i;
				m -= i;
				n--;
				break;
			}
			//sum += dp[n][i][m];
			k -= dp[n][i][m];
		}
	}

	for (auto i : ans) cout << i << " ";

	return 0;
}