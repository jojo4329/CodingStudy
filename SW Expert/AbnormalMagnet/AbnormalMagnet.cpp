// 하나의 자석이 1칸 회전될 때, 붙어 있는 자석은 서로 붙어 있는 날의 자성이 다를 경우에만 인력에 의해 반대 방향으로 1칸 회전
// 1번자석 N : 0, S : 1
// 2번자석 N : 0, S : 2
// 3번자석 N : 0, S : 4
// 4번자석 N : 0, S : 8
// 자석을 1칸 씩 k번 회전시키려고 할 때, K번 자석을 회전시킨 후 획득하는 점수의 총 합을 출력하는 프로그램 작성
// EX1
// 1. 1번 자석 시계방향으로 회전
// 2. 3번 자석을 반시계 방향으로 회전
// 정답 : 10
// 자석 4개, 각 8개의 날
// 1 <= k <= 20
// 시계방향 : 1, 반시계 방향 : -1
// 자성정보는 빨간색 화살표 위치의 날부터 시계방향 순서대로 주어짐
// 1번 자석 : 0 0 1 0 0 1 0 0
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
		if (num == 1) {	// 시계방향
			int temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}
		else {	// num == -1, 반시계 방향
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

		// Rotation부분 구현 필요
		pM->Rotate(iter.second);

		
	}

	// 점수 계산 구현 필요
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
TestCase 개수
회전 개수 (K번)
자성정보
회전시키려는 자석 번호, 회전방향

10
2
0 0 1 0 0 1 0 0
1 0 0 1 1 1 0 1
0 0 1 0 1 1 0 0
0 0 1 0 1 1 0 1
1 1
3 -1
답 : 10
*/