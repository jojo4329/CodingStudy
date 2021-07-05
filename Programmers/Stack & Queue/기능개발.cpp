#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> pr;
vector<int> sp;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;
	queue<int> q;

	// 기능 개발 기간
	for (int i = 0; i < progresses.size(); i++) {
		int d = (100 - progresses[i]) / speeds[i];
		if (progresses[i] + (d * speeds[i]) != 100) { d++; }
		days.push_back(d);
	}

	q.push(days[0]);
	for (int i = 1; i < days.size(); i++) {
		if (q.front() >= days[i]) {
			q.push(days[i]);
		}
		else {
			answer.push_back(q.size());
			while (!q.empty()) { q.pop(); }
			q.push(days[i]);
		}
	}

	if (!q.empty()) { answer.push_back(q.size()); }

	return answer;
}

int main(void)
{
	pr = { 93, 30, 55 };
	sp = { 1, 30, 5 };

	vector<int> result = solution(pr, sp);

	for (int i = 0; i < result.size(); i++) {
		cout << "result : " << result[i] << endl;
	}

	return 0;
}