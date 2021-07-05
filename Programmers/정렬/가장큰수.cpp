#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;

	for (auto iter : numbers) {
		temp.push_back(to_string(iter));
	}

	sort(temp.begin(), temp.end(), cmp);

	if (temp[0] == "0") { return "0"; }

	for (auto n : temp) {
		answer += n;
	}

	return answer;
}

int main(void)
{
	num = { {6, 10, 2} };

	string result = solution(num);

	cout << "result : " << result << endl;

	return 0;
}