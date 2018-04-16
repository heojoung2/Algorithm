#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
	vector<int> vec[32001];
	int link[32001] = { 0, };

	int student_num,comparison_num;
	cin >> student_num>>comparison_num;
	while (comparison_num--)
	{
		int first, second;
		cin >> first >> second;
		vec[first].push_back(second);
		link[second]++;		//간선이 들어오는 갯수를 새는 것이 중요
	}

	queue<int> q;
	for (int i = 1; i <= student_num; i++)
	{
		if (link[i] == 0)	//들어오는 간선이 없는 것
			q.push(i);
	}

	queue<int> result;
	while (!q.empty())
	{
		int current = q.front();
		result.push(current);
		q.pop();
		cout << current << " ";	//pop하는 것이 먼저 정렬된다.

		for (int i = 0; i < vec[current].size(); i++)
		{
			if (--link[vec[current][i]] == 0)	//pop된 간선을 빼준다
				q.push(vec[current][i]);
		}
	}
	cout << endl;

	return 0;
}
