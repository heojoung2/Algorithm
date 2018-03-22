#include <iostream>

using namespace std;
int main() {
	int num, number;
	int count=0;
	
	cin>>num>>number;
	int *arr = new int[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	
	for(int i=num-1;i>=0;i--)
	{
		while(number-arr[i]>=0)
		{
			number-=arr[i];
			count++;
		}
		if(number==0)
			break;
	}
	cout<<count<<endl;
	delete[] arr;
	
	return 0;
}
