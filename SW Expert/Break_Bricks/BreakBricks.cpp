// queue가 너무 많아짐... 5번째 테스트 케이스

#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };
int N, W, H, answer = INT_MAX;
vector<vector<int>> vecPm;
vector<int> tmp;
queue<pair<int, int>> q;	// x, y
int arrMap[15][12];
int arrMap2[15][12];

void CopyMap() {
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			arrMap2[row][col] = arrMap[row][col];
		}
	}
}

void DuplicatePermutation(int depth) {	// wPn
	if (depth == N) {
		vecPm.push_back(tmp);
		depth -= 1;
		return;
	}

	for (int i = 0; i < W; i++) {
		tmp.push_back(i);
		DuplicatePermutation(depth + 1);
		tmp.pop_back();
	}
}

int GetBricksCount() {
	int cnt = 0;
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			if (arrMap2[row][col] != 0) { cnt++; }
		}
	}

	return cnt;
}

void ArrangeMap() {
	for (int col = 0; col < W; col++) {
		queue<int> tmpQ;

		for (int row = H - 1; row >= 0; row--) {
			if (arrMap2[row][col] == 0) { tmpQ.push(row); }
			else {
				if (!tmpQ.empty()) {
					swap(arrMap2[tmpQ.front()][col], arrMap2[row][col]);
					tmpQ.pop();
					tmpQ.push(row);
				}
			}
		}
	}
}

void BreakBricks() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		int power = arrMap2[r][c];

		for (int d = 0; d < 4; d++) {
			int nr = r;
			int nc = c;

			for (int j = 1; j < power; j++) {
				nr += dr[d];
				nc += dc[d];
				if (nr < 0 || nc < 0 || nr > H - 1 || nc > W - 1) { break; }
				if (arrMap2[nr][nc] != 0) {
					q.push(make_pair(nr, nc));
				}
			}
		}
		arrMap2[r][c] = 0;
	}

	// 중력
	ArrangeMap();
}

int GetY(int c) {
	for (int r = 0; r < H; r++) {
		if (arrMap2[r][c] > 0) { return r; }
	}
	return 0;
}

void Solution() {
	// 순열
	DuplicatePermutation(0);
	
	for (int i = 0; i < vecPm.size(); i++) {
		CopyMap();
		auto col = vecPm[i];

		for (int k = 0; k < N; k++) {
			int row = GetY(col[k]);
			if (arrMap2[row][col[k]] != 0) {
				q.push(make_pair(row, col[k]));
				BreakBricks();
			}
		}
		// 계산
		int temp = GetBricksCount();
		if (answer > temp) { answer = temp; }
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

#ifdef VS_TEST
	freopen("input_BreakBricks2.txt", "r", stdin);
#endif
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = INT_MAX;
		cin >> N >> W >> H;
		vecPm.clear();

		for (int r = 0; r < H; r++) {
			for (int c = 0; c < W; c++) {
				cin >> arrMap[r][c];
			}
		}

		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}