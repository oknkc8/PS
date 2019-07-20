#include<bits/stdc++.h>
using namespace std;

int v[100005];

int main() {
	int n, ans = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int a;
		scanf("%d", &a);
		if (v[a] == 0) cnt++;
		else if (v[a] == 1) cnt--;
		v[a]++;
		ans = max(ans, cnt);
	}

	printf("%d", ans);

	return 0;
}