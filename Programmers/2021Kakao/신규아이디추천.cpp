#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	string strId = new_id;

	// 1. 1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
	for (int i = 0; i < strId.size(); i++) {
		if (!strId.empty()) {
			if ('A' <= strId[i] && 'Z' >= strId[i]) {
				strId[i] = strId[i] - 'A' + 'a';
			}
		}
		
	}
	string tempStr1 = strId;

	// 2. 2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
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

	// 3. 3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
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

	// 4. 4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
	if ((!strId.empty()) && (strId[0] == '.')) {
		strId = strId.substr(1, strId.size());
	}

	if ((!strId.empty()) && (strId[strId.size() - 1] == '.')) {
		strId.erase(strId.size() - 1);
	}

	// 5. 5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
	if (strId.empty()) {
		strId = "a";
	}

	// 6-1. 6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
	if ((!strId.empty()) && (16 <= strId.size())) {
		strId.erase(15);
	}

	// 6-2. ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
	if ((!strId.empty()) && (strId[strId.size() - 1] == '.')) {
		strId.erase(strId.size() - 1);
	}

	// 7. 7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
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