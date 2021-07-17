#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> cl;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> m;
	for (auto cloth : clothes) {
		m[cloth[1]]++;
	}

	for (auto iter : m) {
		answer *= (iter.second + 1);
	}

	return answer - 1;
}

int main(void)
{
	int res = 0;
	cl = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };
	
	res = solution(cl);

	cout << res << endl;

	return 0;
}