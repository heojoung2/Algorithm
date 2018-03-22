#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
//vector, pair, sort

using namespace std;
int main() {
	
	vector< pair < int , int > > v;
	
	int size;
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(pair<int,int>(a,b));
	}
	
	sort(v.begin(),v.end());
	for(int i=0;i<size;i++)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}
