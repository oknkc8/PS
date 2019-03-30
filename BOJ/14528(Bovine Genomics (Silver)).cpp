#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string v[1005];
unordered_map<string, int> um;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 2*n; i++) cin >> v[i];

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				um.clear();

				int check = 1;
				for (int l = 0; l < n; l++) {
					string str = "";
					str += v[l][i], str += v[l][j], str += v[l][k];
					um[str] = 1;
				}

				for (int l = n; l < 2 * n; l++) {
					string str = "";
					str += v[l][i], str += v[l][j], str += v[l][k];
					if (um.find(str) != um.end()) {
						check = 0;
						break;
					}
				}

				if (check) ans++;
			}
		}
	}

	printf("%d", ans);

	return 0;
}