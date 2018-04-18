#include<iostream>
#include<vector>
using namespace std;

//벨만 포드 알고리즘 : 특정 한 점에서 모든 점으로 가는 최단거리, 음의 간선이 있어도 된다. 음의 간선의 사이클 문제를 해결하는데 중점
//O(VE)

#define INF 999999999
vector < pair<int, int> > vec[501];

void Bellman_Ford(int node, int edge)
{
	int distance[501];
	for (int i = 1; i <= 500; i++)
		distance[i] = INF;
	distance[1] = 0;

	bool cycle = false;
	for (int i = 1; i <= node; i++)		//최소 거리의 최대 간선은 n-1개이므로 n-1번 돌아야하지만 싸이클 체크를 위해 n번 돈다.
	{
		for (int j = 1; j <= node; j++)
		{
			for (int k = 0; k < vec[j].size(); k++)
			{
				if (distance[vec[j][k].first] > vec[j][k].second + distance[j])
				{
					distance[vec[j][k].first] = vec[j][k].second + distance[j];
					if (i == node)	//최대 간선을 넘었는데도 갱신이 된다면 싸이클이다
						cycle = true;
				}
			}
		}
	}

	if (cycle)
		cout << -1<<endl;
	else
	{
		for (int i = 2; i <= node; i++)
		{
			if (distance[i] == INF)
				cout << -1 << endl;
			else
				cout << distance[i] << endl;
		}
	}
}

int main()
{
	int city, bus_num;
	cin >> city >> bus_num;
	while (bus_num--)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		vec[start].push_back(make_pair(end,weight));
	}
	
	Bellman_Ford(city,bus_num);
	return 0;
}
