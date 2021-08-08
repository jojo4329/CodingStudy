// 플로이드 와샬 알고리즘 
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector < vector<bool>> map(n + 1, vector<bool>(n + 1, false));
	// map 초기화
	for (auto r : results) {
		map[r[0]][r[1]] = true;
	}

	//     i  k   k  j
	// ex [1, 2] [2, 5]
	// k = 거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		// i = 출발 노드
		for (int i = 1; i <= n; i++) {
			// j = 도착 노드
			for (int j = 1; j <= n; j++) {
				if (map[i][k] && map[k][j]) {
					map[i][j] = true;
				}
			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] || map[j][i]) {
				count++;
			}
		}
		if (count == n - 1) { answer++; }
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> v = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
	int iN = 5;

	int result = solution(iN, v);

	cout << "result : " << result << endl;

	return 0;
}