#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> number;
int op[4],depth=0;
int max_val = -1000000000;
int min_val = 1000000000;

void DFS(int index, int sum)
{
	if (index == depth)
	{
		if (sum > max_val)
			max_val = sum;
		if (sum < min_val)
			min_val = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] != 0)
		{
			op[i]--;
			if (i == 0)
				DFS(index+1,sum+number[index+1]);
			else if (i == 1)
				DFS(index + 1, sum - number[index + 1]);
			else if (i == 2)
				DFS(index + 1, sum * number[index + 1]);
			else if (i == 3)
				DFS(index + 1, sum / number[index + 1]);
			op[i]++;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		number.push_back(num);
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
		if (op[i] != 0)
			depth += op[i];
	}

	DFS(0,number[0]);
	cout << max_val << endl;
	cout << min_val << endl;
	
	return 0;
}
