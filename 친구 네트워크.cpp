#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

int parent[200000];
int having_num[200000];

int Find(int num)
{
	if (parent[num] == num)
		return num;

	return parent[num] = Find(parent[num]);
}

int Union(int first, int second)
{
	int first_parent = Find(first);	
	int second_parent = Find(second);

	if (first_parent != second_parent)
	{
		parent[second_parent] = first_parent;
		having_num[first_parent] += having_num[second_parent];
	}
	return having_num[first_parent];
}

int main()
{
	vector<int> result;

	int test_case;
	scanf("%d", &test_case);
	while (test_case--)
	{
		int num;
		scanf("%d", &num);

		for (int i = 0; i < 2 * num; i++)
		{
			parent[i] = i;
			having_num[i] = 1;
		}
		
		map<string, int> m;
		int cnt = 0;
		while (num--)
		{
			char first[20], second[20];
			scanf("%s %s", first, second);
			
			if (m.find(first)==m.end())	//map에서 못찾았을 때
				m[first] = cnt++;
			if (m.find(second) == m.end())
				m[second] = cnt++;

			result.push_back(Union(m[first], m[second]));
		}
	}

	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);
	return 0;
}
