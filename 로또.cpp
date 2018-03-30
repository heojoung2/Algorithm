#include <iostream>
using namespace std;

int number[49];
int result[6];
	
void DFS(int start, int size, int depth);

int main() {
	
	int size;
	cin>>size;
	while(size!=0)
	{
		for(int i=0;i<size;i++)
			cin>>number[i];
		DFS(0,size,0);
		cout<<endl;
		
		cin>>size;
	}
	return 0;
}

void DFS(int start, int size, int depth)
{
	if(depth==6)
	{
		for(int i=0;i<6;i++)
			cout<<result[i]<<" ";
		cout<<endl;
		return ;
	}
	
	for(int i=start;i<size;i++)
	{
		result[depth]=number[i];
		DFS(i+1,size,depth+1);
	}	
}
