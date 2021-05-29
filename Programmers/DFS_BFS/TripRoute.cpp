// ICN ���׿��� ���
// �װ��� ������ ����ִ� 2���� �迭 tickets
// ���� ��θ� �迭�� ��� return
// ���� �� 3�� �̻� 10,000�� ����
// �־��� �װ����� ��� ����ؾ� �Ѵ�.
// ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<bool> visited;

bool dfs(string route, vector<vector<string>>& ti)
{
	answer.push_back(route);
	if (answer.size() == ti.size() + 1) {
		return true;
	}
	for (int i = 0; i < ti.size(); i++) {
		if ((!visited[i]) && (ti[i][0] == route)) {
			visited[i] = true;
			if (dfs(ti[i][1], ti)) {
				return true;
			}
			visited[i] = false;						
		}
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	answer.clear();
	sort(tickets.begin(), tickets.end());

	(void)dfs("ICN", tickets);

	return answer;
}

int main(void)
{
	vector<string> result;
	//vector<vector<string>> ticketss = { {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} };
	vector<vector<string>> ticketss = { {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} };
	visited.assign(ticketss.size(), false);
	
	result = solution(ticketss);

	for (int i = 0; i < ticketss.size() + 1; i++) {
		cout << result[i] << " ";
	}

	return 0;
}

/*
* EX1
[[ICN, JFK], [HND, IAD], JFK, HND]]
>> [ICN, JFK, HND, IAD]

EX2
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
*/