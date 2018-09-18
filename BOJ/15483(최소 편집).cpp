#include<bits/stdc++.h>
using namespace std;

string a, b, s1, s2;
int dp[1005][1005];

int main() {
	cin >> a >> b;
	s1 = " " + b, s2 = " " + a;
	int ls1 = s1.size();
	int ls2 = s2.size();
	for (int i = 0; i < ls1; i++) dp[i][0] = i;
	for (int i = 0; i < ls2; i++) dp[0][i] = i;
	for (int i = 1; i < ls1; i++) {
		for (int j = 1; j < ls2; j++) {
			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
		}
	}	
	printf("%d", dp[ls1-1][ls2-1]);

	return 0;
}