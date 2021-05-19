// 2470 µÎ¿ë¾×
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int N;
long long left, right, mid, differ, resA, resB, sum;
std::vector<long long> vecN;

void Solution() {
	differ = 0LL;
	left = 0;
	right = N - 1;
	sum = std::abs(vecN[left] + vecN[right]);
	resA = vecN[left];
	resB = vecN[right];

	while (left < right) {
		long long tmpSum = vecN[left] + vecN[right];
		if (std::abs(tmpSum) < sum) {
			sum = std::abs(tmpSum);
			resA = vecN[left];
			resB = vecN[right];
		}

		if (tmpSum < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	printf("%lld %lld", resA, resB);
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%lld", &x);
		vecN.push_back(x);
	}

	std::sort(vecN.begin(), vecN.end());

	Solution();

	return 0;
}

/*
input
5
-2 4 -99 -1 98
output
-99 98
*/