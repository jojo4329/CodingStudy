#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000001

int dp1[MAX] = { 0, };
int dp2[MAX] = { 0, };

vector<int> m;

int solution(vector<int> money) {    
    // 첫번째 집부터 텀
    dp1[0] = money[0];
    dp1[1] = money[0];

    for (int i = 2; i < money.size() - 1; i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    // 두번째 집부터 텀
    dp2[0] = 0;
    dp2[1] = money[1];

    for (int i = 2; i < money.size(); i++) {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    return max(dp1[money.size() - 2], dp2[money.size() - 1]);
}

int main(void)
{
    m = { 1, 2, 3, 1 };

    int result = solution(m);

    cout << "result : " << result << endl;

    return 0;
}