#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair <int,int> > vec[1001];

void Dijkstra(int start_city,int end_city);	//하나의 정점에서 다른 모든 정점까지의 최단경로, 음수는 불가능

int main() {
	
	int city,bus;
	cin>>city>>bus;
	
	int start,end,weight;
	for(int i=0;i<bus;i++)
	{
		cin>>start>>end>>weight;
		vec[start].push_back(make_pair(end,weight));		
	}
	
	int start_city,end_city;
	cin>>start_city>>end_city;
	
	Dijkstra(start_city,end_city);
	
	return 0;
}

void Dijkstra(int start_city,int end_city)
{
	priority_queue<pair <int,int> > pq;	//앞의 원소가 기준이고 max_heap이기 때문에 -를 신경써줘야 한다 
	int result[1001];
	fill_n(result,1001,99999999);
	
	result[start_city]=0;
	pq.push(make_pair(0,start_city));
	
	while(!pq.empty())
	{
		int current_city = pq.top().second;
		int current_weight = -pq.top().first;
		pq.pop();
		
		for(int i=0;i<vec[current_city].size();i++)
		{
			int next_city = vec[current_city][i].first;
			int next_weight = vec[current_city][i].second;
			
			if(result[next_city]>current_weight+next_weight)
			{
				result[next_city] = current_weight+next_weight;
				pq.push(make_pair(-result[next_city],next_city));
			}
		}
	}
	
	cout<<result[end_city]<<endl;
	return 0;
}
