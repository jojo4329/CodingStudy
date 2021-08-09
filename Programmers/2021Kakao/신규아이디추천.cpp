#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	string strId = new_id;

	// 1. 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
	for (int i = 0; i < strId.size(); i++) {
		if (!strId.empty()) {
			if ('A' <= strId[i] && 'Z' >= strId[i]) {
				strId[i] = strId[i] - 'A' + 'a';
			}
		}
		
	}
	string tempStr1 = strId;

	// 2. 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
	for (int i = 0; i < strId.size(); i++) {
		if (!strId.empty()) {
			if (('a' <= strId[i] && 'z' >= strId[i]) ||
				('1' <= strId[i] && '9' >= strId[i]) ||
				('.' == strId[i] || ('-' == strId[i]) || ('_' == strId[i]))) {
			}
			else {
				string tempStr2;
				tempStr1.erase(i);
				tempStr2 = strId.substr(i + 1, strId.size());
				tempStr1.append(tempStr2);
				strId = tempStr1;
				i--;
			}
		}
	}
	tempStr1 = strId;

	// 3. 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
	for (int i = 0; i < strId.size() - 1; i++) {
		if (!strId.empty()) {
			if ((strId[i] == '.') && (strId[i + 1] == '.')) {
				string tempStr2;
				tempStr1.erase(i);
				tempStr2 = strId.substr(i + 1, strId.size());
				tempStr1.append(tempStr2);
				strId = tempStr1;
				i--;
			}
		}
	}
	tempStr1 = strId;

	// 4. 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
	if ((!strId.empty()) && (strId[0] == '.')) {
		strId = strId.substr(1, strId.size());
	}

	if ((!strId.empty()) && (strId[strId.size() - 1] == '.')) {
		strId.erase(strId.size() - 1);
	}

	// 5. 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
	if (strId.empty()) {
		strId = "a";
	}

	// 6-1. 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	if ((!strId.empty()) && (16 <= strId.size())) {
		strId.erase(15);
	}

	// 6-2. 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
	if ((!strId.empty()) && (strId[strId.size() - 1] == '.')) {
		strId.erase(strId.size() - 1);
	}

	// 7. 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
	while (2 >= strId.size()) {
		string tmp = strId.substr(strId.size() - 1, 1);
		strId.append(tmp);
	}
	answer = strId;

	return answer;
}

int main(void)
{
	string strId = "...!@BaT#*..y.abcdefghijklm.";
	//string strId = "=.=";

	string result = solution(strId);

	cout << "Result : " << result << endl;

	return 0;
}