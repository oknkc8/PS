#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> xy[1005], ab[1005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> xy[i].first >> xy[i].second;
	for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
	
	sort(xy, xy + n);
	sort(ab, ab + n);

	cout << xy[0].first + ab[n - 1].first << " " << xy[n - 1].second + ab[0].second;

	return 0;
}