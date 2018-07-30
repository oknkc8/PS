#include<bits/stdc++.h>
using namespace std;

int n, v[105][105];
string dp[105][105];

string add(string aa, string bb) {
	string ret = "", a = "", b = "", c = "0", ret_rev = "";
	for (int i = 0; i < aa.size(); i++) a += aa[aa.size() - i - 1];
	for (int i = 0; i < bb.size(); i++) b += bb[bb.size() - i - 1];
	if (a.size() < b.size()) swap(a, b);

	for (int i = b.size(); i < a.size(); i++) b += '0';

	for (int i = 0; i < a.size(); i++) {
		int x = a[i] - '0', y = b[i] - '0', z = c[i] - '0';
		ret += ((x + y + z) % 10 + '0');
		c += ((x + y + z) / 10 + '0');
	}
	if (c[a.size()] != '0') ret += c[a.size()];

	for (int i = 0; i < ret.size(); i++) ret_rev += ret[ret.size() - i - 1];
	return ret_rev;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &v[i][j]), dp[i][j] = "0";
	
	dp[0][0] = "1";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == "0") continue;
			if (v[i][j] == 0) continue;
			int nx = i + v[i][j], ny = j + v[i][j];
			if (nx < n) dp[nx][j] = add(dp[nx][j], dp[i][j]);
			if (ny < n) dp[i][ny] = add(dp[i][ny], dp[i][j]);
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}