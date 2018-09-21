#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, v[100], c[101] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		c[v[i]]++;
	}

	int cnt = 0;
	for (int i = 1; i <= 100; i++) cnt += (c[i] == 1);

	int check[100] = { 0 }, ct = 0;
	vector<pair<int, char>> ans;
	for (int i = 1; i <= 100; i++) {
		if (c[i] == 1) {
			ct++;
			for (int j = 0; j < n; j++) {
				if (i == v[j]) {
					if (ct <= cnt / 2) ans.push_back({ j,'A' });
					else ans.push_back({ j,'B' });
					check[j] = 1;	break;
				}
			}
		}
	}
	int flag = cnt % 2 ? 0 : 1;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (cnt % 2) {
				if (c[v[i]] >= 3) {
					if (!flag) {
						flag = 1;
						ans.push_back({ i,'A' });
					}
					else ans.push_back({ i,'B' });
				}
				else ans.push_back({ i,'A' });
			}
			else ans.push_back({ i,'A' });
		}
	}
	if (!flag) cout << "NO";
	else {
		sort(ans.begin(), ans.end());
		cout << "YES\n";
		for (int i = 0; i < ans.size(); i++) cout << ans[i].second;
	}
	return 0;
}