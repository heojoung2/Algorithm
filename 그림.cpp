#include<iostream>
#include<vector>
using namespace std;

int arr[500][500];
bool visited[500][500] = { false, };
int direction_x[4] = {0,0,-1,1};
int direction_y[4] = {1,-1,0,0};

int cnt=0;
void DFS(int x,int y,int row, int col)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int current_x = x + direction_x[i];
		int current_y = y + direction_y[i];
		if (0 <= current_x && current_x < row && 0 <= current_y && current_y < col && arr[current_x][current_y] == 1 && visited[current_x][current_y] == false)
		{
			cnt++;
			DFS(current_x, current_y, row, col);
		}
	}
}

int main()
{
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	vector<int> vec;
	int picture_num=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 1 && visited[i][j]==false)
			{
				cnt = 1;
				DFS(i, j,row,col);
				picture_num++;
				vec.push_back(cnt);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (max < vec[i])
			max = vec[i];
	}
	cout << picture_num << endl;
	cout << max << endl;

	return 0;
}
