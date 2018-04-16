#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//최소 스패닝 트리 문제는 사이클이 없어야하기때문에 union-find(disjoint set)를 사용한다.

int parent[1001];
vector<pair<int, pair<int, int>>> vec;

int Find(int num)
{
	if (parent[num] == num)
		return num;

	return parent[num] = Find(parent[num]);
}

bool Union(int first, int second)
{
	int first_parent = Find(first);
	int second_parent = Find(second);

	if (first_parent != second_parent)
	{
		parent[second_parent] = first_parent;
		return true;
	}
	return false;
}

int main()
{
	int computer_num, line_num;
	cin >> computer_num >> line_num;

	for (int i = 0; i < line_num; i++)
	{
		int a, b, weight;
		cin >> a >> b >> weight;
		vec.push_back(make_pair(weight, make_pair(a, b)));
	}

	for (int i = 1; i <= computer_num; i++)
		parent[i] = i;

	sort(vec.begin(), vec.end());

	int result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (Union(vec[i].second.first, vec[i].second.second))
			result += vec[i].first;
	}
	cout << result << endl;
	return 0;
}
