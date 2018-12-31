#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;	cin >> a >> b >> c;
	int ans = 0;
	
	if (b - 1 <= a && b + 1 <= c) ans = max(ans, 3 * b);
	if (a + 1 <= b && a + 2 <= c) ans = max(ans, 3 * a + 3);
	if (c - 2 <= a && c - 1 <= b) ans = max(ans, 3 * c - 3);

	cout << ans;

	return 0;
}