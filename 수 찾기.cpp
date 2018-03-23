#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool Binary(int *arr, int target, int left, int right)
{
	if(left>right)
		return false;
	
	int mid = (left+right)/2;
	
	if(arr[mid]==target)
		return true;
	else if(arr[mid]>target)
		Binary(arr, target, left, mid-1);
	else
		Binary(arr, target, mid+1, right);
	
}

int main() {
	int arr1_size, arr2_size;
	
	int arr1[100000];
	int arr2[100000];
	
	scanf("%d",&arr1_size);
	for(int i=0;i<arr1_size;i++)
		scanf("%d",&arr1[i]);
	sort(arr1,arr1+arr1_size);
	
	scanf("%d",&arr2_size);
	for(int i=0;i<arr2_size;i++)
		scanf("%d",&arr2[i]);
	
	for(int i=0;i<arr2_size;i++)
	{
		if(Binary(arr1,arr2[i],0,arr1_size))
			printf("1\n");
		else
			printf("0\n");
	}
	
	
	return 0;
}
