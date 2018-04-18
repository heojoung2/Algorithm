#include<iostream>
#include<string>
using namespace std;

void LCS(string str1, string str2)
{
	int length1 = str1.size();
	int length2 = str2.size();

	int **dp = new int*[length1+1];
	for (int i = 0; i < length1+1; i++)
		dp[i] = new int[length2+1];


	for (int i = 0; i <= length1; i++)
	{
		for (int j = 0; j <= length2; j++)
		{
			if (i == 0 || j == 0)	//LCS에서 0행,0열은 0으로 채워 편의성을 높인다
			{
				dp[i][j] = 0;
				continue;
			}

			if (str1[i - 1] == str2[j - 1])			//같은 문자면 (왼쪽,위) + 1
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else			//다른 문자면 왼쪽이나 위의 최대값
			{
				if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}

		}
	}
	cout << dp[length1][length2] << endl;

	for (int i = 0; i < length1+1; i++)
		delete[]  dp[i];
	delete[] dp;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		LCS(str1, str2);
	}
	return 0;
}
