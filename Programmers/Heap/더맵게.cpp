#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> sc;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	int mix, first, second;

	while (pq.top() < K && pq.size() > 1) {
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		mix = first + (second * 2);
		pq.push(mix);
		answer++;
	}
	if (pq.top() < K) { return -1; }
	return answer;
}

int main(void)
{
	int n = 7;
	sc = { 1, 2, 3, 9, 10, 12 };

	int result = solution(sc, n);

	cout << "result : " << result << endl;

	return 0;
}