#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int answer = 0;
string beginStr, targetStr;
struct Data {
	string str;
	vector<bool> visited;
	int count;
};

bool Compare(string& str1, string& str2) {
	int diff = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i]) {
			diff++;
		}
	}
	return (diff == 1) ? 1 : 0;
}

int solution(string begin, string target, vector<string> words) {
	answer = 0;
	queue<Data> q;
	q.push({ begin, vector<bool>(words.size(), false), 0 });

	while (!q.empty()) {
		auto top = q.front();
		if (top.str == target) {
			break;
		}
		q.pop();
		for (int i = 0; i < words.size(); i++) {
			if ((!top.visited[i]) && (Compare(top.str, words[i]))) {
				top.visited[i] = true;
				q.push({ words[i], top.visited, top.count + 1 });
			}
		}
	}
	answer = (q.empty()) ? 0 : q.front().count;
	return answer;
}

int main(void)
{
	int result;
	cin >> beginStr;
	cin >> targetStr;

	//vector<string> word = {"hot", "dot", "dog", "lot", "log", "cog"};
	vector<string> word = { "hot", "dot", "dog", "lot", "log" };

	result = solution(beginStr, targetStr, word);
	printf("result : %d", result);
	return 0;
}
/*
ex1
hit
cog
hot, dot, dog, lot, log, cog
>> 4

ex2
hit
cog
hot, dot, dog, lot, log
>> 0
*/