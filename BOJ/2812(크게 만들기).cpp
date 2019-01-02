#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string str;	cin >> str;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		if (s.empty() || s.top() >= str[i] - '0' && s.size() + 1 <= n - k) s.push(str[i] - '0');
		else if (s.top() < str[i] - '0') {
			while (s.size() + (n - 1 - i) >= n - k && s.size() && s.top()<str[i]-'0') 
				s.pop();
			if (s.size() + 1 <= n - k) s.push(str[i] - '0');
		}
	}
	
	vector<int> ans;
	while (s.size()) {
		ans.push_back(s.top());
		s.pop();
	}

	for (int i = ans.size()-1; i >= 0; i--) cout << ans[i];

	return 0;
}