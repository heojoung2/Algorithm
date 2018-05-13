#include<iostream>
using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	bool not_prime[10001] = { false, };
	not_prime[1] = true;

	for (int i = 2; i <= num2; i++)
	{
		if (not_prime[i] == false)
		{
			for (int j = i*i; j <= num2; j = j + i)
				not_prime[j] = true;
		}
	}

	int first;
	int sum = 0;
	for (int i = num2; i >= num1; i--)
	{
		if (not_prime[i] == false)
		{
			first = i;
			sum += i;
		}
	}
	if (sum == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << first << endl;
	}
	return 0;
}
