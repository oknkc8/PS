#include<bits/stdc++.h>
using namespace std;

int dp[305];

int main() {
	int arr[3], n;	cin >> arr[0] >> arr[1] >> arr[2] >> n;

	dp[0] = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = arr[i]; j <= n; j++) {
			if (dp[j - arr[i]]) dp[j] = 1;
		}
	}

	cout << dp[n];

	return 0;
}