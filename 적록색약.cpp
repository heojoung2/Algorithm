#include <iostream>
#include <cstring>

using namespace std;

char arr[100][100];
bool visit[100][100]={0,};
int direction_x[4]={0,0,-1,1};
int direction_y[4]={-1,1,0,0};

void DFS(int x, int y, int size)
{
	visit[x][y]=true;
	char color=arr[x][y];
	for(int i=0;i<4;i++)
	{
		int x2=x+direction_x[i];
		int y2=y+direction_y[i];
		
		if(x2>=0 && x2<size && y2>=0 && y2<size && visit[x2][y2]==false && arr[x2][y2]==color)
			DFS(x2,y2,size);
	}
}

int main()
{
	int size;
	cin>>size;
	
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			cin>>arr[i][j];
	
	int count=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(!visit[i][j])
			{
				DFS(i,j,size);
				count++;
			}
		}
	}
	cout<<count<<" ";
	
	count=0;
	memset(visit,0,sizeof(visit));
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(arr[i][j]=='R')
				arr[i][j]='G';
		}
	}
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(!visit[i][j])
			{
				DFS(i,j,size);
				count++;
			}
		}
	}
	cout<<count<<endl;	
	return 0;
}
