#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;


int main()
{
	stack<pair <char, int> > stack;
	string str;
	cin >> str;

	vector<int> raser;
	vector < pair<int, int>> pipe;

	int cnt = -1;
	for (int i = 0; i < str.length(); i++)
	{
		cnt++;
		if (str[i] == '(')
			stack.push(make_pair('(', cnt));
		else if(str[i]==')')
		{
			int dis = cnt - stack.top().second;
			if (dis == 1)
				raser.push_back(stack.top().second);
			else
				pipe.push_back(make_pair(stack.top().second,cnt));
			stack.pop();		
		}
	}
	
	int result = 0;
	for (int i = 0; i < pipe.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < raser.size(); j++)
		{
			if (pipe[i].first <= raser[j] && raser[j] <= pipe[i].second)
			{
				flag = true;
				result++;
			}
			else if (flag == true)
				break;
		}
		if (flag == true)
			result++;
	}
	cout << result << endl;
	return 0;
}
