#include<bits/stdc++.h>
using namespace std;
#define mod 10007

string str;
int dp[1005][1005];

int f(int a, int b) {
	if (a > b) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	
	ret = 0;
	if (a == b) return ret = 1;
	if (b - a == 1) return ret = (str[a] == str[b]) + 2;

	ret = f(a + 1, b) + f(a, b - 1) - f(a + 1, b - 1);
	if (str[a] == str[b]) ret += f(a + 1, b - 1) + 1;

	return ret %= mod;
}

int main() {
	cin >> str;
	int n = str.size();
	memset(dp, -1, sizeof(dp));

	printf("%d", f(0, n - 1));

	return 0;
}