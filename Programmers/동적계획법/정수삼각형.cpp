#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	dp[0][0] = triangle[0][0];
	int size = triangle.size();

	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			// 가장 좌측일 때
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + triangle[i][j];
			}
			// 가장 우측일 때
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			// 가운데 일 때
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	// 가장 큰 값 구하기
	for (int i = 0; i < size; i++) {
		if (answer < dp[size - 1][i]) {
			answer = dp[size - 1][i];
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> tri = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

	int result = solution(tri);

	cout << "result : " << result << endl;

	return 0; 
}