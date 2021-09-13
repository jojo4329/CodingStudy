#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ��� ������ �Ѹ�
// ���� ������ ����(��տ� ����) Ȥ�� ����(��տ� ����) Ȥ�� �� ��(���� ����)

int gi_map[101][101] = {};
int bo_map[101][101] = {};

bool check_gi(int x, int y, int n) {
	if (y == 0)	// �ٴ��� ��
		return true;
	if (gi_map[x][y - 1] == 1)	// �ؿ� ����� ���� ��
		return true;
	if (x > 0 && bo_map[x - 1][y])	// ���� �ؿ��� ������ ���� ���� �� (����� �� �����ʿ� ������)
		return true;
	if (x < n && bo_map[x][y])	// �ؿ� �ش� �������� ������ ���� ���� �� (����� �� ���ʿ� ������)
		return true;

	return false;
}

bool check_bo(int x, int y, int n) {
	if (gi_map[x][y - 1] == 1)	// �ؿ� ����� ���� �� (���� ��տ��� ����)
		return true;
	if (x < n && gi_map[x + 1][y - 1])	// �ؿ� ����� ���� �� (�� �������� ��տ��� ����)
		return true;
	if (x > 0 && x < n && bo_map[x - 1][y] && bo_map[x + 1][y])	// �� �� �ʿ� ���� ���� ��
		return true;

	return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++) {
		int x, y, a, b;
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];

		// ��� ��ġ
		if (a == 0 && b == 1) {
			if (check_gi(x, y, n)) {
				gi_map[x][y] = 1;
			}
		}
		// �� ��ġ
		if (a == 1 && b == 1) {
			if (check_bo(x, y, n)) {
				bo_map[x][y] = 1;
			}
		}
		// ��� ����
		if (a == 0 && b == 0) {
			bool doJob = true;
			gi_map[x][y] = 0;

			if (y < n && gi_map[x][y + 1] && !check_gi(x, y + 1, n))	// ���� ����� ���� ��
				doJob = false;
			else if (y < n && bo_map[x][y + 1] && !check_bo(x, y + 1, n))	// ���� ��� ���� ���� �� (�� ������ ����� ����)
				doJob = false;
			else if (x > 0 && y < n && bo_map[x - 1][y + 1] && !check_bo(x - 1, y + 1, n))	// ���� ��� ���� ���� �� (�� ������ ����� ����)
				doJob = false;

			if (!doJob) gi_map[x][y] = 1;
		}
		// �� ����
		if (a == 1 && b == 0) {
			bool doJob = true;
			bo_map[x][y] = 0;

			if (gi_map[x][y] && !check_gi(x, y, n))	// �� ������ ����� ���� ��
				doJob = false;
			else if (x < n && gi_map[x + 1][y] && !check_gi(x + 1, y, n))	// �� ������ ����� ���� ��
				doJob = false;
			else if (x > 0 && bo_map[x - 1][y] && !check_bo(x - 1, y, n))	// �� ������ ���� �پ� ���� ��
				doJob = false;
			else if (x < n && bo_map[x + 1][y] && !check_bo(x + 1, y, n))	// �� ������ ���� �پ����� ��
				doJob = false;

			if (!doJob) bo_map[x][y] = 1;
		}
	}

	// answer ������Ʈ
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (gi_map[i][j]) {
				answer.push_back({ i, j, 0 });
			}
			if (bo_map[i][j]) {
				answer.push_back({ i, j, 1 });
			}
		}
	}

	return answer;
}

int main(void)
{
	int nSize = 5;
	vector<vector<int>> bf = { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };

	vector<vector<int>> res = solution(nSize, bf);

	for (int i = 0; i < res.size(); i++) {
		cout << "result[" << i << "] : [" << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << "]" << endl;
	}


	return 0;
}