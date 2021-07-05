#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> _participant;
vector<string> _completion;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> temp;
	for (string name : participant) {
		temp[name]++;
	}

	for (string name : completion) {
		temp[name]--;
	}

	for (auto iter : temp) {
		if (iter.second > 0) {
			answer = iter.first;
			break;
		}
	}
	return answer;
}

int main()
{
	_participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
	_completion = { "josipa", "filipa", "marina", "nikola" };
	
	string result = solution(_participant, _completion);

	cout << result << endl;

	return 0;
}