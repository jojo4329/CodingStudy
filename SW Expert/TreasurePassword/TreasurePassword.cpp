// 16���� ����(0~F)�� ���� �ִ� ��������
// �Ѳ��� �ð�������� ���� �� �ְ�, �� �� ���� ������ ���ڰ� �ð� �������� �� ĭ�� ȸ��
// �� ������ ������ ������ ����, �ð���� ������ ���� �ڸ� ���ڿ� �ش��ϸ� �ϳ��� ���� ��Ÿ��
// ex) [Fig.1] 1A3, B54, 8F9, D66 [Fig.2] 61A, 3B5, 48F, 9D6
// �������ڿ��� �ڹ��谡 �ɷ��ִµ� �� �ڹ����� ��й�ȣ�� ���� ���ڿ� ���� ���ڷ� ���� �� �ִ� ��� �� ��, K��°�� ū ���� 10������ ���� ��
// N���� ���ڰ� �Է����� �־����� ��, ���������� ��� ��ȣ�� ����ϴ� ���α׷�
// [���� ����]
// N�� 4�� ����̰�, 9�̻� 28������ ����
// N���� ���ڴ� ���� 0�̻� F����
// K�� ���� ������ ���� �������� ũ�� �־����� �ʴ´�.
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
		// 16���� -> 10����
		ConvertToDe();

		// Rotate
		for (int i = 0; i < N / 4; i++) {
			Rotate();
			ConvertToDe();
		}
		
		// �ߺ��� �� ����(in vector)
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