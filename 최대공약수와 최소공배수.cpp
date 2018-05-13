#include<iostream>
using namespace std;

int GCD(int a, int b)
{
	if (a < b)
		return GCD(b, a);
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	int gcd = GCD(num1, num2);
	cout << gcd << endl;
	cout << num1*num2 / gcd << endl;

	return 0;
}
