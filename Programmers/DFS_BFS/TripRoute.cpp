// ICN 공항에서 출발
// 항공권 정보가 들어있는 2차원 배열 tickets
// 공항 경로를 배열에 담아 return
// 공항 수 3개 이상 10,000개 이하
// 주어진 항공권은 모두 사용해야 한다.
// 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return


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