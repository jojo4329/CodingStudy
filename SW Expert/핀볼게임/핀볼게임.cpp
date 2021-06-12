#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum BLOCK_TYPE { 
	BH = -1,
	LD = 1,
	LU = 2,
	RU = 3,
	RD = 4,
	SQ = 5,
	WH1 = 6,
	WH2 = 7,
	WH3 = 8,
	WH4 = 9,
	WH5 = 10
};
enum DIRECTION {
	NONE = -1,
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };
int n, answer;
int map[100][100];

struct POS {
	int row;
	int col;
	DIRECTION direction;

	POS(int r, int c, DIRECTION d) : row(r), col(c), direction(d) {}
};
vector<POS> vPos;

//struct WORMHOLE {
//	int row;
//	int col;
//	int num;
//
//	WORMHOLE(int r, int c, int n) : row(r), col(c), num(n) {}
//};
//vector<WORMHOLE> vWh;

void GetSPoint() {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (map[r][c] == 0) {
				vPos.emplace_back(POS(r, c, NONE));
			}
		}
	}
}

//void GetWh() {
//	for (int r = 0; r < n; r++) {
//		for (int c = 0; c < n; c++) {
//			if (map[r][c] >= 5 && map[r][c] <= 10) {
//				vWh.emplace_back(WORMHOLE(r, c, map[r][c]));
//				sort(vWh.begin(), vWh.end());
//			}
//		}
//	}
//}

void GetDirwithBlock(BLOCK_TYPE bt, DIRECTION& d) {
	// 1. 위쪽 방향
	if (d == UP) {
		if (bt == SQ || bt == LD || bt == RD) {
			d = DOWN;
		}
		else if (bt == LU) {
			d = RIGHT;
		}
		else if (bt == RU) {
			d = LEFT;
		}
	}
	// 2. 아래 방향
	else if (d == DOWN) {
		if (bt == SQ || bt == LU || bt == RU) {
			d = UP;
		}
		else if (bt == LD) {
			d = RIGHT;
		}
		else if (bt == RD) {
			d = LEFT;
		}
	}
	// 3. 오른쪽 방향
	else if (d == RIGHT) {
		if (bt == SQ || bt == LD || bt == LU) {
			d = LEFT;
		}
		else if (bt == RU) {
			d = DOWN;
		}
		else if (bt == RD) {
			d = UP;
		}
	}
	// 4. 왼쪽 방향
	else if (d == LEFT) {
		if (bt == SQ || bt == RU || bt == RD) {
			d = RIGHT;
		}
		else if (bt == LD) {
			d = UP;
		}
		else if (bt == LU) {
			d = DOWN;
		}
	}
}

void GameStart(POS& iter, int d) {
	// 점수
	int score = 0;

	int nr = iter.row;
	int nc = iter.col;
	iter.direction = DIRECTION(d);
	DIRECTION nd = DIRECTION(d);

	while (true) {
		nr += dr[nd];
		nc += dc[nd];
		// 1. 벽을 만났을 때
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
			// 1-1. 왼쪽 벽 & 왼쪽 방향
			if (nc < 0 && nd == LEFT) {
				//vPos[i].direction = RIGHT;
				nd = RIGHT;
			}
			// 1-2. 오른쪽 벽 & 오른쪽 방향
			else if (nc >= 0 && nd == RIGHT) {
				//vPos[i].direction = LEFT;
				nd = LEFT;
			}
			// 1-3. 윗쪽 벽 & 윗쪽 방향
			else if (nr < 0 && nd == UP) {
				//vPos[i].direction = DOWN;
				nd = DOWN;
			}
			// 1-4. 아랫쪽 벽 & 아래쪽 방향
			else if (nr >= n && nd == DOWN) {
				//vPos[i].direction = UP;
				nd = UP;
			}
			score++;
		}
		// 2. 블럭을 만났을 때
		else if (map[nr][nc] >= LD && map[nr][nc] <= SQ) {
			//GetDirwithBlock(BLOCK_TYPE(map[nr][nc]), vPos[i].direction);
			GetDirwithBlock(BLOCK_TYPE(map[nr][nc]), nd);
			score++;
		}
		// 3. 웜홀을 만났을 때
		else if (map[nr][nc] >= WH1 && map[nr][nc] <= WH5) {
			bool isChanged = false;
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if (map[nr][nc] == map[r][c] && !(nr == r && nc == c)) {
						nr = r;
						nc = c;
						isChanged = true;
						break;
					}
				}
				if (isChanged) { break; }
			}
		}
		// 4. 블랙홀을 만났을 때
		else if (map[nr][nc] == BH) {
			//answer = score;
			answer = max(answer, score);
			return;
		}
		// 5. 빈 공간일 때
		else if (map[nr][nc] == 0) {
			// 5-1. 출발 위치로 왔을 때
			if (nr == iter.row && nc == iter.col) {
				//answer = score;
				answer = max(answer, score);
				return;
			}
		}
	}
}

void Solution() {
	// 1. 시작 위치 Get
	GetSPoint();

	// 2. 웜홀 위치 Get
	//GetWh();

	// 3. 시작위치 돌면서 시작
	for (auto& iter : vPos) {
		// 4. 4방향으로 찾아보기
		for (int i = 0; i < 4; i++) {
			GameStart(iter, i);
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
	freopen("input_PinBall.txt", "r", stdin);
#endif
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				cin >> map[r][c];
			}
		}

		answer = 0;
		vPos.clear();
		
		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}
}