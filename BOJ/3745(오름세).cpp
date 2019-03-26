#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> v(n), dp;
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);

		dp.push_back(v[0]);
		for (int i = 1; i < n; i++) {
			int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			if (idx == dp.size()) dp.push_back(v[i]);
			else dp[idx] = v[i];
		}
		printf("%d\n", dp.size());
	}

	return 0;
}