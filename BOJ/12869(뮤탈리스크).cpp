#include<bits/stdc++.h>
using namespace std;

int dp[66][66][66];

int func(int x, int y, int z) {
	if (!x && !y && !z)return 0;
	int &ret = dp[x][y][z];
	if (ret != -1)return ret;
	ret = 9876543;
	ret = min(ret, func(max(0, x - 9), max(0, y - 3), max(0, z - 1)) + 1);
	ret = min(ret, func(max(0, x - 9), max(0, y - 1), max(0, z - 3)) + 1);
	ret = min(ret, func(max(0, x - 3), max(0, y - 9), max(0, z - 1)) + 1);
	ret = min(ret, func(max(0, x - 1), max(0, y - 9), max(0, z - 3)) + 1);
	ret = min(ret, func(max(0, x - 3), max(0, y - 1), max(0, z - 9)) + 1);
	ret = min(ret, func(max(0, x - 1), max(0, y - 3), max(0, z - 9)) + 1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	int n;	cin >> n;
	int a=0, b=0, c=0;	

	scanf("%d%d%d", &a, &b, &c);

	printf("%d", func(a, b, c));

	return 0;
}