#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100][100]={0,};
int direction_x[4]={0,0,1,-1};
int direction_y[4]={-1,1,0,0};
vector<int> area_vector;

void BFS(int i, int j,int x_size, int y_size)
{
	queue< pair<int,int> > queue;
	queue.push(make_pair(i,j));
	arr[i][j]=1;
	int area=0;
	
	while(!queue.empty())
	{
		int x=queue.front().first;
		int y=queue.front().second;
		queue.pop();
		area++;
		
		for(int a=0;a<4;a++)
		{
			int x2=x+direction_x[a];
			int y2=y+direction_y[a];
			
			if(x2>=0 && x2<y_size && y2>=0 && y2<x_size && arr[x2][y2]==0)
			{
				arr[x2][y2]=1;
				queue.push(make_pair(x2,y2));
			}
		}
	}
	area_vector.push_back(area);
}

int main()
{
	int y_size,x_size,num;
   	cin>>y_size>>x_size>>num;
   	
	while(num--)
	{
		int x1,y1,x2,y2;
	  	cin>>x1>>y1>>x2>>y2;
	  	for(int i=y1;i<y2;i++)
	     	for(int j=x1;j<x2;j++)
	        	arr[i][j]=1;
	}
	
	int area_num=0;	
	for(int i=0;i<y_size;i++)
	{
	  	for(int j=0;j<x_size;j++)
	  	{
	  		if(arr[i][j]==0)
	  		{
	  			BFS(i,j,x_size,y_size);
	  			area_num++;
			}
	  	}
	}
	
	cout<<area_num<<endl;
	sort(area_vector.begin(),area_vector.end());
	for(int i=0;i<area_vector.size();i++)
		cout<<area_vector[i]<<" ";
	cout<<endl;
	
	return 0;
}
