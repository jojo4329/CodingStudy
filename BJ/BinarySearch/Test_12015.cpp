// 12015 가장 긴 증가하는 부분 수열 2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vecN;
vector<int> vecResult;

void solution()
{
	vecResult.push_back(0);

	for (auto iter : vecN) {
		if (vecResult.back() < iter) {
			vecResult.push_back(iter);
		}
		else {
			*lower_bound(vecResult.begin(), vecResult.end(), iter) = iter;
			
		}
	}
	printf("%d", static_cast<int>(vecResult.size() - 1));
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		vecN.push_back(x);
	}

	solution();

	return 0;
}

/*
* Input
* 6
* 10 20 10 30 20 50
* output
* 4
*/