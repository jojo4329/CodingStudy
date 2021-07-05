#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ci;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= i + 1) {
			answer++;
		}
		else { break; }
	}

	return answer;
}

int main(void)
{
	//ci = { 3, 0, 6, 1, 5 };
	ci = { 3, 0, 6, 1, 5, 7, 2, 10, 8 };

	int result = solution(ci);

	cout << "result : " << result << endl;

	return 0;
}