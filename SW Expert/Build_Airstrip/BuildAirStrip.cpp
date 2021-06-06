#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
int answer;
int map[21][21];
int visited[2][21][21];

void CheckRow() {
	for (int col = 0; col < N; col++) {
		bool possible = true;

		for (int row = 0; row < N - 1; row++) {
			int previous = map[row][col];
			int next = map[row + 1][col];
			int diff = abs(previous - next);

			if (diff == 0) { continue; }

			if (diff > 1) {
				possible = false;
				break;
			}

			if (previous > next) {
				// 경사로 설치 가능 확인
				for (int k = row + 1; k <= row + X; k++) {
					if (k >= N || visited[0][k][col] || map[k][col] != next) {
						possible = false;
						break;
					}
				}
				// 경사로 설치
				if (possible) {
					for (int k = row + 1; k <= row + X; k++) {
						visited[0][k][col] = true;
					}
				}
			}
			// 위쪽에 설치
			else if (previous < next) {
				// 경사로 설치 가능 확인
				for (int k = row; k > row - X; k--) {
					if (k < 0 || visited[0][k][col] || map[k][col] != previous) {
						possible = false;
						break;
					}
				}
				// 경사로 설치
				if (possible) {
					for (int k = row; k > row - X; k--) {
						visited[0][k][col] = true;
					}
				}
			}
		}
		if (possible) { answer++; }
	}
}

void CheckCol() {
	for (int row = 0; row < N; row++) {
		bool possible = true;

		for (int col = 0; col < N - 1; col++) {
			int left = map[row][col];
			int right = map[row][col + 1];
			int diff = abs(left - right);

			if (diff == 0) { continue; }

			if (diff > 1) {
				possible = false;
				break;
			}
			// 오른쪽에 설치
			if (left > right) {
				// 경사로 설치 가능 확인
				for (int k = col + 1; k <= col + X; k++) {
					if (k >= N || visited[1][row][k] || map[row][k] != right) {
						possible = false;
						break;
					}
				}
				// 경사로 설치
				if (possible) {
					for (int k = col + 1; k <= col + X; k++) {
						visited[1][row][k] = true;
					}
				}
			}
			// 왼쪽에 설치
			else if (left < right) {
				// 경사로 설치 가능 확인
				for (int k = col; k > col - X; k--) {
					if (k < 0 || visited[1][row][k] || map[row][k] != left) {
						possible = false;
						break;
					}
				}
				// 경사로 설치
				if (possible) {
					for (int k = col; k > col - X; k--) {
						visited[1][row][k] = true;
					}
				}
			}
		}
		if (possible) { answer++; }
	}
}

void Solution() {
	CheckRow();
	CheckCol();
}

int  main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

#ifdef VS_TEST
	freopen("input_Build_AirStrip.txt", "r", stdin);
#endif
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> map[r][c];
			}
		}

		memset(visited, false, sizeof(visited));
		answer = 0;
		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}