#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define VS_TEST
#ifdef VS_TEST
#include<cstdio>
#endif

using namespace std;

struct TOP {
	int row;
	int col;
	int count;

	TOP(int x, int y, int cnt) : row(x), col(y), count(cnt) {}
};

struct POS {
	int row;
	int col;
	int height;

	POS(int x, int y, int h) : row(x), col(y), height(h) {}
};
//			  상,하,좌,우
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int topPoint;
int n, k, answer;
vector<TOP> vecTop;
vector<POS> vecRoad;
int map[9][9];
bool visited[9][9];


void GetTop() {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (topPoint < map[r][c]) {
				topPoint = map[r][c];
			}
		}
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (topPoint == map[r][c]) {
				vecTop.push_back(TOP(r, c, 1));
			}
		}
	}
}

void MakeRoad(TOP _top, bool cut) {
	for (int i = 0; i < 4; i++) {
		int nr = _top.row + dr[i];
		int nc = _top.col + dc[i];

		// 새로 방문한 곳이 map을 벗어나는지 체크
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) { continue; }

		// 재방문인지 체크
		if (visited[nr][nc]) { continue; }

		// 새로 방문하는 곳이 이전에 방문한 곳보다 같거나 높다면
		// + k를 파고 방문
		if (map[_top.row][_top.col] <= map[nr][nc]) {
			if (!cut) {
				for (int depth = 1; depth <= k; depth++) {
					int originLand = map[nr][nc];
					int newLand = map[nr][nc] - depth;

					// 새로 깎은 지형이 현재 지형보다 낮아지면
					if (map[_top.row][_top.col] > newLand) {
						visited[nr][nc] = true;
						map[nr][nc] = newLand;
						cut = true;
						MakeRoad(TOP(nr, nc, _top.count + 1), cut);
						map[nr][nc] = originLand;
						visited[nr][nc] = false;
						cut = false;
					}
				}
			}
		}
		// 새로 방문하는 곳이 이전에 방문한 곳보다 낮다면
		else { // (map[_top.row][_top.col] > map[nr][nc]) {
			visited[nr][nc] = true;
			//TOP tmpTop(nr, nc, _top.count + 1);
			MakeRoad(TOP(nr, nc, _top.count + 1), cut);
			visited[nr][nc] = false;
		}
		// 최대 등산로만 대입(answer)
		answer = max(answer, _top.count);
	}
}

void Solution() {
	// 1. 가장 높은 봉오리 찾기(시작 Point)
	GetTop();

	// 2. 상하좌우 움직이면서 등산로 만들기
	for (auto& iter : vecTop) {
		visited[iter.row][iter.col] = true;
		MakeRoad(iter, false);
		visited[iter.row][iter.col] = false;
	}
	
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
#ifdef VS_TEST
	freopen("input_roadway.txt", "r", stdin);
#endif
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> k;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				cin >> map[r][c];
			}
		}

		answer = 0;
		topPoint = 0;
		memset(visited, false, sizeof(visited));
		vecTop.clear();
		vecRoad.clear();

		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}