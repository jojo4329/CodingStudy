#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int y, b;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int carpet = brown + yellow;

	int width = 0;
	int height = 0;

	for (int i = carpet / 2; i > 0 ; i--) {
		width = i;
		height = carpet / width;

		if (((width - 2) * (height - 2) == yellow)) {
			answer.push_back(width);
			answer.push_back(height);
			break;
		}
	}

	return answer;
}

int main(void)
{
	y = 1;
	b = 9;

	vector<int> result = solution(b, y);
	cout << "[" << result[0] << ", " << result[1] << "]" << endl;

	return 0;

}