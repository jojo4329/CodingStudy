// n개의 음이 아닌 정수
// 주어지는 숫자의 개수는 2개 이상 20개 이하
// 각 숫자는 1이상 50이하
// 타겟 넘버는 1 이상 1000 이하인 자연수

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

int n, target;
int result = 0;

void dfs(std::vector<int>& numbers, int target, int sum, int count)
{
	if (count == numbers.size()) {
		if (sum == target) {
			result++;
		}
		return;
	}

	dfs(numbers, target, sum + numbers[count], count + 1);
	dfs(numbers, target, sum - numbers[count], count + 1);
}

int main(void)
{
	std::vector<int> nums;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		nums.push_back(x);
	}

	scanf("%d", &target);

	dfs(nums, target, 0, 0);

	printf("%d", result);
	return 0;
}

/*
input
내가 추가 (5)
1 1 1 1 1
3
output
5

*/