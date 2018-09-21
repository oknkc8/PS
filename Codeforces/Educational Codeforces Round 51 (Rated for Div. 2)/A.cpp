#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		string str;	cin >> str;
		vector<pair<int, char>> v1, v2, v3, ans;
		for (int i = 0; i < str.size(); i++) {
			if ('a' <= str[i] && str[i] <= 'z') v1.push_back({ i,str[i] });
			else if ('A' <= str[i] && str[i] <= 'Z') v2.push_back({ i,str[i] });
			else v3.push_back({ i,str[i] });
		}

		if (v1.size() && v2.size() && v3.size()) cout << str << endl;
		else {
			int s1 = v1.size(), s2 = v2.size(), s3 = v3.size();
			if (s1 && !s2 && !s3) v1[s1 - 1].second = 'A', v1[s1 - 2].second = '1';
			else if (!s1 && s2 && !s3) v2[s2 - 1].second = 'a', v2[s2 - 2].second = '1';
			else if (!s1 && !s2 && s3) v3[s3 - 1].second = 'A', v3[s3 - 2].second = 'a';
			else {
				if (!s1) {
					if (s2 > s3) v2[s2 - 1].second = 'a';
					else v3[s3 - 1].second = 'a';
				}
				else if (!s2) {
					if (s1 > s3) v1[s1 - 1].second = 'A';
					else v3[s3 - 1].second = 'A';
				}
				else {
					if (s1 > s2) v1[s1 - 1].second = '1';
					else v2[s2 - 1].second = '1';
				}
			}

			for (int i = 0; i < s1; i++) ans.push_back(v1[i]);
			for (int i = 0; i < s2; i++) ans.push_back(v2[i]);
			for (int i = 0; i < s3; i++) ans.push_back(v3[i]);

			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) cout << ans[i].second;
			cout << endl;
		}
	}

	return 0;
}