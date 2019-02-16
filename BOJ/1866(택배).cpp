#include<bits/stdc++.h>
using namespace std;

int a, b, v[3005], dp[3005];

int f(int idx) {
	if (idx == 0) return 0;
	if (dp[idx]) return dp[idx];

	int &ret = dp[idx];
	int t = b;
	ret = v[idx] * a + f(idx - 1);
	for (int i = idx; i > 0; i--) {
		t += (v[(idx + i + 1) / 2] - v[i])*a;
		ret = min(ret, f(i- 1) + t);
	}

	return ret;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	cin >> a >> b;

	sort(v + 1, v + n + 1);
	cout << f(n);

	return 0;
}