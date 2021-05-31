// �ϳ��� �ڼ��� 1ĭ ȸ���� ��, �پ� �ִ� �ڼ��� ���� �پ� �ִ� ���� �ڼ��� �ٸ� ��쿡�� �η¿� ���� �ݴ� �������� 1ĭ ȸ��
// 1���ڼ� N : 0, S : 1
// 2���ڼ� N : 0, S : 2
// 3���ڼ� N : 0, S : 4
// 4���ڼ� N : 0, S : 8
// �ڼ��� 1ĭ �� k�� ȸ����Ű���� �� ��, K�� �ڼ��� ȸ����Ų �� ȹ���ϴ� ������ �� ���� ����ϴ� ���α׷� �ۼ�
// EX1
// 1. 1�� �ڼ� �ð�������� ȸ��
// 2. 3�� �ڼ��� �ݽð� �������� ȸ��
// ���� : 10
// �ڼ� 4��, �� 8���� ��
// 1 <= k <= 20
// �ð���� : 1, �ݽð� ���� : -1
// �ڼ������� ������ ȭ��ǥ ��ġ�� ������ �ð���� ������� �־���
// 1�� �ڼ� : 0 0 1 0 0 1 0 0
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Magnet {
public:
	Magnet(int _sc) : score(_sc), dq(), rFlag(0) {}

	void PushBack(int num) {
		dq.push_back(num);
	}
	void SetRFlag(int _f) {
		rFlag = _f;
	}
	void Rotate(int num) {
		if (num == 1) {	// �ð����
			int temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}
		else {	// num == -1, �ݽð� ����
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
	}
private:
	int score;
	deque<int> dq;
	int rFlag;
};

int K;

int Solution(vector<Magnet>& vMag, vector<pair<int, int>>& rotation)
{
	int answer = 0;

	for (auto iter : rotation) {
		Magnet* pM = &vMag[iter.first - 1];
		pM->SetRFlag(1);

		// Rotation�κ� ���� �ʿ�
		pM->Rotate(iter.second);

		
	}

	// ���� ��� ���� �ʿ�
	int sum = 0;


	return answer;
}

int main(void)
{
	int test_case;
	int T;
	scanf("%d", &T);

	vector<Magnet> vMag = { {1}, {2}, {4}, {8} };
	
	for (int test_case = 0; test_case < T; test_case++) {
		scanf("%d", &K);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				int temp;
				scanf("%d", temp);
				vMag[i].PushBack(temp);
			}
		}

		vector<pair<int, int>> rotation;
		int numOfMagnet, rollDirection;
		for (int i = 0; i < K; i++) {
			scanf("%d, %d", &numOfMagnet, &rollDirection);
			rotation.push_back(make_pair(numOfMagnet, rollDirection));
		}

		printf("#%d %d\n", test_case, Solution(vMag, rotation));
	}
	return 0;
}
/*
ex1
TestCase ����
ȸ�� ���� (K��)
�ڼ�����
ȸ����Ű���� �ڼ� ��ȣ, ȸ������

10
2
0 0 1 0 0 1 0 0
1 0 0 1 1 1 0 1
0 0 1 0 1 1 0 0
0 0 1 0 1 1 0 1
1 1
3 -1
�� : 10
*/