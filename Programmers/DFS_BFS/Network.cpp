// 컴퓨터의 개수 n (1<= n <= 200)
// 연결에 대한 정보가 담긴 2차원 배열 computers
// 네트워크의 개수를 return
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

int n;
int answer = 0;
std::vector<std::vector<int>> computers(3, std::vector<int>(3));

void dfs(int n, std::vector<std::vector<int>>& com, std::vector<bool>& visit, int point) {
	visit[point] = true;

	for (int i = 0; i < n; i++) {
		if (!visit[i] && com[point][i]) {
			dfs(n, com, visit, i);
		}
	}
}

int solution(int n, std::vector<std::vector<int>> computers) {
	std::vector<bool> visit(n, false);

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			dfs(n, computers, visit, i);
		}
	}
	
	return answer;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			computers[i][j] = x;
		}
	}

	solution(n, computers);

	printf("%d", answer);
	return 0;
}

/*
input
3
1 1 0
1 1 0
0 0 1
return : 2

3
1 1 0
1 1 1
0 1 1
return : 1

*/