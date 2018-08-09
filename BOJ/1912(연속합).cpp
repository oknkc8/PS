#include<stdio.h>
#include<algorithm>
using namespace std;

int su[100005];
int dp[100005];

int main()
{
	int n;
	int Max;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &su[i]);
	}

	dp[0] = su[0];
	Max = dp[0];

	for (int i = 1; i <n; i++)
	{
		dp[i] = max(dp[i - 1] + su[i], su[i]);
	}
	for (int i = 1; i < n; i++)
	{
		Max = max(Max, dp[i]);
	}

	printf("%d", Max);
}