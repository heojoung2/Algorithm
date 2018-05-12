#include<iostream>
#include<cmath>
using namespace std;

void Hanoi(int num, int tower1, int tower2, int tower3)
{
	if (num == 1)
	{
		printf("%d %d\n", tower1, tower3);
		return;
	}
	Hanoi(num-1,tower1,tower3,tower2);
	printf("%d %d\n", tower1, tower3);
	Hanoi(num-1,tower2,tower1,tower3);
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", int(pow(2, num))-1);
	Hanoi(num,1,2,3);

	return 0;
}
