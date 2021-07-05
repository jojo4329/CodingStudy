#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> j;

struct cmp {
	bool operator() (vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int idx = 0, time = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	// 시작 시간이 빠른 놈부터 정렬
	sort(jobs.begin(), jobs.end());

	// jobs에 작업해야할 작업이 없고, 우선순위 큐가 빌 때까지 반복
	while ((idx < jobs.size()) || (!pq.empty())) {
		// jobs에 작업해야할 작업이 남아있고, 현재 작업 시작시간이 현재 시간보다 빠르면
		if (jobs.size() > idx && jobs[idx][0] <= time) {
			// 우선순위 큐에 넣고, idx를 +1 해줌(현재 작업을 의미하는 idx를 사용한 것으로 하기위해)
			pq.push(jobs[idx++]);
			// 현재 시간보다 빠른 또 다른 작업이 존재할 수 있으므로
			continue;
		}

		if (!pq.empty()) {
			// 현재 돌아가고 있는 작업의 소요시간을 time에 추가
			time += pq.top()[1];
			// 전체 작업시간(answer)에, 작업의 전체소요시간(대기시간 + 소요시간, 작업 끝난 시간 - 작업 요청시간)을 더해줌
			answer += time - pq.top()[0];			
			// 끝난 작업은 삭제
			pq.pop();
		}
		// pq가 비어있으면
		else {
			time = jobs[idx][0];
		}
	}

	return answer / jobs.size();
}

int main(void)
{
	j = { {0, 3}, {1, 9}, {2, 6} };

	int result = solution(j);

	cout << "result : " << result << endl;

	return 0;
}