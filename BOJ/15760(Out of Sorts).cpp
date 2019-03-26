#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i].first), v[i].second = i;

	sort(v, v + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i].second - i);
	}
	
	printf("%d", ans + 1);

	return 0;
}