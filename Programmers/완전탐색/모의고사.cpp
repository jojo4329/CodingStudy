#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> an;
int A[5] = { 1, 2, 3, 4, 5 };
int B[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int C[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int score[3] = { 0, };
	int maxScore = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == A[i % 5]) score[0] += 1;
		if (answers[i] == B[i % 8]) score[1] += 1;
		if (answers[i] == C[i % 10]) score[2] += 1;
	}

	for (int i = 0; i < 3; i++) {
		if (maxScore < score[i]) {
			maxScore = score[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		if (maxScore == score[i]) {
			answer.push_back(i + 1);
		}
	}

	return answer;
}

int main(void)
{
	an = { 1, 2, 3, 4, 5 };

	vector<int> result = solution(an);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}