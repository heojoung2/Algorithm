#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int arr[20][20] = { 0, };
int N;
int depth=0;
bool visit[20] = { false,};
vector<int> vec;
int result = 9999999;

int Result(vector<int> vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec.size(); j++)
			sum += arr[vec.at(i)][vec.at(j)];
	return sum;
}

void Team()
{
	vector<int> start;
	vector<int> link;
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 1)
			start.push_back(i);
		else
			link.push_back(i);
	}

	int start_sum = Result(start);
	int link_sum = Result(link);

	if (abs(start_sum - link_sum) < result)
		result = abs(start_sum - link_sum);
}

void DFS(int index) {
	depth++;
	visit[index] = true;

	if (depth == N / 2) {
		Team();
	}
	else {
		for (int i = index + 1; i < N; i++) {
			if (!visit[i]) {
				DFS(i);
			}
		}
	}
	depth--;
	visit[index] = false;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	DFS(0);
	cout << result << endl;

	return 0;
}
