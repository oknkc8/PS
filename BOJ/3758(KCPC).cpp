#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		int n, k, t, m;	cin >> n >> k >> t >> m;
		int score[105][105] = { 0 }, info[105][2] = { 0 };

		for (int i = 0; i < m; i++) {
			int id, p, s;	cin >> id >> p >> s;
			score[id][p] = max(score[id][p], s);
			info[id][0]++, info[id][1] = i;
		}

		vector<pair<int, pair<int, pair<int, int>>>> v;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j = 1; j <= k; j++) s += score[i][j];
			v.push_back({ -s,{info[i][0],{info[i][1],i}} });
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i].second.second.second == t) {
				printf("%d\n", i + 1);
				break;
			}
		}
	}

	return 0;
}