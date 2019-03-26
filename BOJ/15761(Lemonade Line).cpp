#include<bits/stdc++.h>
using namespace std;

int n, v[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	sort(v, v + n);

	int ans = 0;
	for (int i = n - 1; i >= 0 && v[i] >= ans; i--) ans++;

	printf("%d", ans);

	return 0;
}