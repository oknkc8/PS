#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[100005];

int main() {
	int n;	cin >> n;
	for (int i = 1; i*i <= n; i++) v.push_back(i*i);

	for (auto i : v) {
		dp[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (!dp[j]) dp[j] = dp[j - i] + 1;
			else dp[j] = min(dp[j], dp[j - i] + 1);
		}
	}

	cout << dp[n];
	
	return 0;
}