#include<iostream>
using namespace std;

int LIS(int arr[1000], int size)
{
	int result_num=1;
	int result[1000];

	result[0] = arr[0];
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < result_num; j++)
		{
			if (arr[i] <= result[j])	//lower_bound성질 이용
			{
				result[j] = arr[i];
				break;
			}
			else if (j == result_num - 1)	//끝까지 갔는데도 안바꼈다는건 제일 큰 값이라는 뜻
			{
				result[j + 1] = arr[i];
				result_num++;
				break;
			}
		}
	}
	return result_num;
}

int main()
{
	int num;
	int arr[1000];

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	cout<<LIS(arr,num)<<endl;
	return 0;
}
