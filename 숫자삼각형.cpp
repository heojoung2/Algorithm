#include <iostream>

using namespace std;
int main() {
	int arr[501][501]={0,};
	int dp[501][501]={0,};
	int level;
	cin>>level;
	
	for(int i=0;i<level;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cin>>arr[i][j];	
		}
	}
	
	dp[0][0]=arr[0][0];
	for(int i=1;i<level;i++)
	{
		dp[i][0]=dp[i-1][0]+arr[i][0];
		for(int j=1;j<=i;j++)
		{
			if(dp[i-1][j-1]>=dp[i-1][j])
				dp[i][j]=dp[i-1][j-1]+arr[i][j];
			else if(dp[i-1][j-1]<dp[i-1][j])
				dp[i][j]=dp[i-1][j]+arr[i][j];
		}
	}
	
	int max=dp[level-1][0];
	for(int i=1;i<level;i++)
	{
		if(max<dp[level-1][i])
			max=dp[level-1][i];
	}
	cout<<max<<endl;
	
	return 0;
}
