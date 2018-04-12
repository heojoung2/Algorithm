#include<iostream>
#include<cmath>
using namespace std;

int r, c, cnt;
void Search(int N, int x, int y)
{
	if (x == r && y == c)
	{
		cout << cnt << endl;
		return;
	}
	if (x <= r && r<x + N && y <= c && c<y + N)
	{
		Search(N / 2, x, y);
		Search(N / 2, x, y + N / 2);
		Search(N / 2, x + N / 2, y);
		Search(N / 2, x + N / 2, y + N / 2);
	}
	else
		cnt += (N*N);
}

int main()
{
	int cnt = 0;
	int N;
	cin >> N >> r >> c;
	Search(pow(2, N), 0, 0);

	return 0;
}
