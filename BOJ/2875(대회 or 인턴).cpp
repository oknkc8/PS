#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;	cin >> n >> m >> k;
	int a, b, c, ans;

	if (n >= 2 * m) a = n - 2 * m, b = 0, ans = m;
	else a = n % 2, b = m - n / 2, ans = n / 2;

	c = k - (a + b);
	if (c < 0) c = 0;

	cout << ans - (c + 2) / 3;

	return 0;
}