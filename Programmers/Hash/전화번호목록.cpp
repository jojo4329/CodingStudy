#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <unordered_map>

using namespace std;

vector<string> phoneB;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
			return false;
		}
	}

	//unordered_map<string, int> map;
	//for (string pn : phone_book) {
	//	map[pn]++;
	//}

	////string 비교
	//for (string pn : phone_book) {
	//	string tmp = pn.substr(0, 2);
	//	for (auto iter : map) {
	//		if (!tmp.compare(iter.first.substr(0, 2))) {	// 같으면 0
	//			map[iter.first]--;
	//		}
	//	}
	//}

	//for (auto it : map) {
	//	if (it.second == 0) {
	//		answer = false;
	//	}
	//}

	return answer;
}

int main(void)
{
	bool bCheck = false;
	phoneB = { "119", "97674223", "1195524421", "123", "456" };

	bCheck = solution(phoneB);

	cout << bCheck << endl;

	return 0;
}