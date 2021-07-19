#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
	int map[101][101];
	// map 만들기 [n][m], [j][i]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			map[j][i] = 1;
		}
	}
	// [n][m], [j][i], [x][y]
	for (int i = 0; i < puddles.size(); i++) {
		// 잠긴 지역
		map[puddles[i][1]][puddles[i][0]] = 0;

		// y좌표가 1일 때
		if (puddles[i][0] == 1) {
			for (int k = puddles[i][1]; k <= n; k++) {
				map[k][1] = 0;
			}
		}
		// x좌표가 1일 때
		if (puddles[i][1] == 1) {
			for (int k = puddles[i][0]; k <= m; k++) {
				map[1][k] = 0;
			}
		}
	}

	// count
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (map[j][i] != 0) {
				map[j][i] = (map[j - 1][i] + map[j][i - 1]) % 1000000007;
			}
		}
	}

	return map[n][m];
}

int main(void)
{
	int m = 4;
	int n = 3;
	vector<vector<int>> pu = { {2, 2} };

	int result = solution(m, n, pu);

	cout << "result : " << result << endl;

	return 0;
}