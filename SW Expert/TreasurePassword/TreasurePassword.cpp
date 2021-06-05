// 16진수 숫자(0~F)가 적혀 있는 보물상자
// 뚜껑은 시계방향으로 돌릴 수 있고, 한 번 돌릴 때마다 숫자가 시계 방향으로 한 칸씩 회전
// 각 변에는 동일한 개수의 숫자, 시계방향 순으로 높은 자리 숫자에 해당하며 하나의 수를 나타냄
// ex) [Fig.1] 1A3, B54, 8F9, D66 [Fig.2] 61A, 3B5, 48F, 9D6
// 보물상자에는 자물쇠가 걸려있는데 이 자물쇠의 비밀번호는 보물 상자에 적힌 숫자로 만들 수 있는 모든 수 중, K번째로 큰 수로 10진수로 만든 수
// N개의 숫자가 입력으로 주어졌을 때, 보물상자의 비밀 번호를 출력하는 프로그램
// [제약 사항]
// N은 4의 배수이고, 9이상 28이하의 정수
// N개의 숫자는 각각 0이상 F이하
// K는 생성 가능한 수의 개수보다 크게 주어지지 않는다.
#define _CRT_SECURE_NO_WARNINGS

#define VS_TEST
#ifdef VS_TEST
#include <cstdio>
#endif
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer;
string input;
vector<int> result;


void Rotate()
{
	string temp = input.substr(0, N - 1);
	input = input[N - 1] + temp;
}

void ConvertToDe()
{
	int size = N / 4;
	for (int i = 0; i < N; i += size) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			if ('0' <= input[i + j] && input[i + j] <= '9') {
				sum += (input[i + j] - '0') * pow(16, size - 1 - j);
			}
			else if ('A' <= input[i + j] && input[i + j] <= 'F') {
				int tmp = 10 + (input[i + j] - 'A');
				sum += tmp * pow(16, size - 1 - j);
			}
		}
		result.push_back(sum);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	result.clear();

#ifdef VS_TEST
	freopen("input_TreasurePW.txt", "r", stdin);
#endif
	cin >> T;
	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		cin >> input;
		// 16진수 -> 10진수
		ConvertToDe();

		// Rotate
		for (int i = 0; i < N / 4; i++) {
			Rotate();
			ConvertToDe();
		}
		
		// 중복된 것 삭제(in vector)
		sort(result.begin(), result.end(), greater<int>());
		result.erase(unique(result.begin(), result.end()), result.end());

		answer = result[K - 1];

		printf("#%d %d \n", test_case, answer);
	}
}

/*
5 (T)
12 10 (N, K)
1B3B3B81F75E

*/