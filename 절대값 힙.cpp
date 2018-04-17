#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
	priority_queue<pair<int,int>> queue;

	int test;
	cin >> test;
	while (test--)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (!queue.empty())
			{
				cout << -queue.top().second << endl;
				queue.pop();
			}
			else
				cout << "0" << endl;
		}
		else
			queue.push(make_pair(-abs(num), -num));
	}
	return 0;
}
