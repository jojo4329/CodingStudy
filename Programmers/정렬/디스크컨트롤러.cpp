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
	// ���� �ð��� ���� ����� ����
	sort(jobs.begin(), jobs.end());

	// jobs�� �۾��ؾ��� �۾��� ����, �켱���� ť�� �� ������ �ݺ�
	while ((idx < jobs.size()) || (!pq.empty())) {
		// jobs�� �۾��ؾ��� �۾��� �����ְ�, ���� �۾� ���۽ð��� ���� �ð����� ������
		if (jobs.size() > idx && jobs[idx][0] <= time) {
			// �켱���� ť�� �ְ�, idx�� +1 ����(���� �۾��� �ǹ��ϴ� idx�� ����� ������ �ϱ�����)
			pq.push(jobs[idx++]);
			// ���� �ð����� ���� �� �ٸ� �۾��� ������ �� �����Ƿ�
			continue;
		}

		if (!pq.empty()) {
			// ���� ���ư��� �ִ� �۾��� �ҿ�ð��� time�� �߰�
			time += pq.top()[1];
			// ��ü �۾��ð�(answer)��, �۾��� ��ü�ҿ�ð�(���ð� + �ҿ�ð�, �۾� ���� �ð� - �۾� ��û�ð�)�� ������
			answer += time - pq.top()[0];			
			// ���� �۾��� ����
			pq.pop();
		}
		// pq�� ���������
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