// ¿¹»ê
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M, sum, maxMoney;
vector<long long> vecN;

void solution() {
	long long start = 0;
	long long end = vecN[N - 1];
	long long mid = 0;

	if (M >= sum) {
		printf("%lld", maxMoney);
		return;
	}
	else {
		while (start <= end) {
			mid = (start + end) / 2;
			long long tmpSum = 0;
			for (int i = 0; i < N; i++) {
				tmpSum += (vecN[i] > mid) ? mid : vecN[i];
			}

			if (tmpSum > M) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		printf("%lld", start - 1);
	}
}


int main(void)
{
	long long result;

	scanf("%lld", &N);

	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%lld", &x);
		vecN.push_back(x);
		sum += vecN[i];
		maxMoney = (vecN[i] > maxMoney) ? vecN[i] : maxMoney;
	}

	scanf("%lld", &M);

	sort(vecN.begin(), vecN.end());

	solution();

	return 0;
}
/*
* 5
* 120 110 140 150 170
* 620
* 
*/