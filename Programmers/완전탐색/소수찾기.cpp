#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string nums;

bool CheckNum(int n) {
	if (n < 2) { return false; }

	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<int> vecN;
	vector<int> allNums;
	
	// string numbers 하나씩 vector에 push
	for (int i = 0; i < numbers.size(); i++) {
		vecN.push_back(numbers[i] - '0');
	}

	// 숫자 정렬
	sort(vecN.begin(), vecN.end());

	// 모든 숫자 만들기
	do {
		for (int i = 0; i <= vecN.size(); i++) {
			int tmp = 0;
			for (int j = 0; j < i; j++) {
				tmp = (tmp * 10) + vecN[j];
				allNums.push_back(tmp);
			}
		}
	} while (next_permutation(vecN.begin(), vecN.end()));

	// sort & 중복 제거
	sort(allNums.begin(), allNums.end());
	allNums.erase(unique(allNums.begin(), allNums.end()), allNums.end());
	
	//int* parr = new int[allNums.size()];
	//// 
	//for (int i = 0; i < allNums.size(); i++) {
	//	parr[i] = allNums[i];
	//}


	// 소수 개수 세기
	for (int i = 0; i < allNums.size(); i++) {
		if (CheckNum(allNums[i])) { answer++; }
	}

	//delete[] parr;
	return answer;
}

int main(void)
{
	nums = "17";

	int result = solution(nums);

	cout << "result : " << result << endl;

	return 0;
}