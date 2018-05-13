#include<iostream>
using namespace std;

/*
int Fibo(int num)
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	return Fibo(num - 2) + Fibo(num - 1);
}
*/

int main()
{
	int num;
	cin >> num;
	//cout<<Fibo(num)<<endl;

	int val1 = 0;
	int val2 = 1;
	int sum = 0;

	if (num == 0 || num==1)
		cout << num << endl;
	else
	{
		for (int i = 2; i <= num; i++)
		{
			sum = val1 + val2;
			val1 = val2;
			val2 = sum;
		}
		cout << sum << endl;
	}
	return 0;
}
