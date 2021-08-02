#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int node;
vector<vector<int>> ver;
int dist[20001] = { 0, };
bool map[20001][20001] = { false, };
bool visited[20001] = { false, };

int solution(int n, vector<vector<int>> edge) {
	int answer = 0, max = 0;
	queue<int> q;

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		map[edge[i][0]][edge[i][1]] = true;
		map[edge[i][1]][edge[i][0]] = true;
	}

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 2; i <= n; i++) {
			if (map[tmp][i] == true && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				dist[i] = dist[tmp] + 1;
			}

			if (max < dist[i]) {
				max = dist[i];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		if (max == dist[i]) {
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	node = 6;
	ver = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };

	int result = solution(node, ver);

	cout << "result : " << result << endl;

	return 0;
}