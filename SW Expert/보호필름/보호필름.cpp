#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, w, k, answer;
int map[13][20];
int tMap[13][20];
bool select[13];

bool IsPass() {
	for (int c = 0; c < w; c++) {
		int aCnt = 0;
		int bCnt = 0;
		bool flag = false;

		for (int r = 0; r < d; r++) {
			if (tMap[r][c] == 0) {
				aCnt++;
				bCnt = 0;
			}
			else if (tMap[r][c] == 1) {
				aCnt = 0;
				bCnt++;
			}

			if (aCnt == k || bCnt == k) {
				flag = true;
				break;
			}
		}
		if (flag == false) { return false; }
	}
	return true;
}

void Inject(int _r, int value, bool tf) {
	if (tf == true) {
		for (int c = 0; c < w; c++) {
			tMap[_r][c] = value;
		}
	}
	else {
		for (int c = 0; c < w; c++) {
			tMap[_r][c] = map[_r][c];
		}
	}
}

void Dfs(int _r, int cnt) {
	// k 개수보다 cnt가 클때 return
	if (cnt >= k || cnt >= answer) { 
		answer = cnt;
		return;
	}
	if (IsPass() == true) {
		answer = min(answer, cnt);
		return;
	}

	// 조합
	for (int r = _r; r < d; r++) {
		if (select[r] == true) { continue; }
		select[r] = true;

		for (int val = 0; val < 2; val++) {
			Inject(r, val, true);
			Dfs(r, cnt + 1);
			Inject(r, val, false);
		}
		select[r] = false;		
	}
}

void Solution() {
	if (IsPass() == true || k == 1) {
		answer = 0;
		return;
	}
	Dfs(0, 0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

#ifdef VS_TEST
	freopen("input_ProtectFilm.txt", "r", stdin);
#endif
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> d >> w >> k;

		for (int r = 0; r < d; r++) {
			for (int c = 0; c < w; c++) {
				cin >> map[r][c];
				tMap[r][c] = map[r][c];
			}
		}

		answer = INT_MAX;
		memset(select, false, sizeof(select));
		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}
}