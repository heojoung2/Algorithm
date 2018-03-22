#include <iostream>
#include <algorithm>

using namespace std;

void Display(int *arr)
{	
	for(int i=2;i<9;i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main() {
	
	int arr[9];
	int num=9;
	int sum=0;
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	
	for(int i=0;i<num;i++)
	{
		sum-=arr[i];
		for(int j=i+1;j<num;j++)
		{
			sum-=arr[j];
			if(sum==100)
			{
				arr[i]=0;
				arr[j]=0;
				sort(arr,arr+num);
				Display(arr);
				return 0;
			}
			sum+=arr[j];
		}
		sum+=arr[i];
	}
	
	return 0;
}
