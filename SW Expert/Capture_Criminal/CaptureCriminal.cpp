#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

enum BLOCK_TYPE { NONE, CROSS, UD, LR, RU, RD, LU, LD };

int N, M, R, C, L;
int answer;
int map[51][51];
int visited[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct Pos {
	int row;
	int col;
	int cnt;

	Pos(int _x, int _y, int _cnt) : row(_x), col(_y), cnt(_cnt) {}
};

void Solution() {
	queue<Pos> q;
	q.push(Pos(R, C, 0));
	visited[R][C] = true;

	while (!q.empty()) {
		int x = q.front().row;
		int y = q.front().col;
		int cnt = q.front().cnt;
		
		// ½Ã°£ÀÌ L¸¸Å­ Èê·¶À» ¶§
		if (cnt > L) { break; }
		if (!visited[x][y]) {
			cnt++;
			visited[x][y] = true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) { break; }

		}
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
	freopen("input_Capture1.txt", "r", stdin);
#endif
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> map[r][c];
			}
		}

		memset(visited, false, sizeof(visited));
		answer = 0;
		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}
}