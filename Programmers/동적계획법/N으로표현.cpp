#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int getNN(int N, int index) {
	int result = N;
	for (int i = 0; i < index; i++) {
		result = result * 10 + N;
	}
	return result;
}

int solution(int N, int number) {
	// N이랑 number가 같을 때
	if (N == number) { return 1; }

	vector<set<int>> DP(8);
	DP[0].insert(N);

	for (int k = 1; k < 8; k++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i + j + 1 != k) { continue; }
				for (int itI : DP[i]) {
					for (int itJ : DP[j]) {
						DP[k].insert(itI + itJ);
						if (itI - itJ > 0) { DP[k].insert(itI - itJ); }
						DP[k].insert(itI * itJ);
						if (itI / itJ > 0) { DP[k].insert(itI / itJ); }
					}
				}
			}
		}
		DP[k].insert(getNN(N, k));

		if (DP[k].count(number)) { return k + 1; }
	}
	return -1;
}

int main(void)
{
	int n = 5;
	int number = 12;

	int result = solution(n, number);

	cout << "result : " << result << endl;

	return 0;
}