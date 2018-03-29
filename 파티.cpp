#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Floyd(int table[1000][1000],int city, int party);	//모든 최단경로를 구하는 알고리즘 

int table[1000][1000];
int main() {
	
	int city,road,party;
	cin>>city>>road>>party;
	
	int start,end,weight;
	for(int i=0;i<city;i++)
	{
		fill_n(table[i],road,999999);
		table[i][i]=0;
	}
	
	for(int i=0;i<road;i++)
	{
		cin>>start>>end>>weight;
		table[start-1][end-1]=weight;
	}
	
	Floyd(table,city,party);
	
	return 0;	
}

void Floyd(int table[1000][1000],int city,int party)
{
	for(int k=0;k<city;k++)
	{
		for(int i=0;i<city;i++)
		{
			for(int j=0;j<city;j++)
			{
				if(table[i][j] > table[i][k]+table[k][j])
					table[i][j] = table[i][k]+table[k][j];
			}
		}
	}
	
	int max=0;
	for(int i=0;i<city;i++)
	{
		if(max<table[i][party-1] + table[party-1][i])
			max=table[i][party-1] + table[party-1][i];
	}
	
	cout<<max<<endl;
}
	
	
