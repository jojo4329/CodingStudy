#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> op;
vector<string> op2;

vector<int> solution(vector<string> operations) {
	vector<int> answer(2);
	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> pqMin;
	priority_queue<int, vector<int>> pqMax;

	for (auto oper : operations) {
		string tOper = oper.substr(0, 1);
		int num = stoi(oper.substr(2));

		// I�� �� input
		if (tOper == "I") {
			pqMax.push(num);
			pqMin.push(num);
			cnt++;
		}
		// D�� �� pop
		else if (tOper == "D") {
			// ť�� ������� �� ���� ��� ���� ����
			if (!cnt) { continue; }
			if (num == 1) { 
				pqMax.pop();
				cnt--;
			}
			if (num == -1) {
				pqMin.pop();
				cnt--;
			}
		}
	}

	if (cnt) { 
		answer[0] = pqMax.top();
		answer[1] = pqMin.top();
	}

	return answer;
}

int main(void)
{
	op = { {"I 16"}, {"D 1"} };
	op2 = { {"I 7"}, {"I 5"}, {"I -5"}, {"D -1"} };

	vector<int> result = solution(op2);

	for (int i = 0; i < result.size(); i++) {
		cout << "result : " << result[i] << endl;
	}

	return 0;
}