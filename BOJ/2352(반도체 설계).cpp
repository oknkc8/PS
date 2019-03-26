#include<bits/stdc++.h>
using namespace std;

int n, v[40005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	vector<int> ans;
	ans.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
		if (idx == ans.size()) ans.push_back(v[i]);
		else ans[idx] = v[i];
	}

	printf("%d", ans.size());

	return 0;
}