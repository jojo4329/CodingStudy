#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cnt[27];                     // cnt[i] = n : 길이가 i인 조합 중 최대 주문 횟수는 n번
map<string, int> m;             // m[str] = n : 조합 str의 주문 횟수는 n번
vector<string> menu[27][21];    // menu[i][j] : 길이가 i이고 j번 주문된 조합들의 목록

void Combination(string s, int index, string str) {
    if (str.size() > 1) {
        m[str]++;
        cnt[str.size()] = max(cnt[str.size()], m[str]);
        menu[str.size()][m[str]].push_back(str);
    }

    for (int i = index + 1; i < s.size(); i++) {
        str.push_back(s[i]);
        Combination(s, i, str);
        str.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // orders 조합만 구함.
    for (auto o : orders) {
        sort(o.begin(), o.end());
        Combination(o, -1, "");
    }

    // answer 구하기
    for (auto c : course) {
        if (cnt[c] > 1) {   // 길이가 c인 조합의 최대 주문 숫자가 1 이상일 때
            for (string s : menu[c][cnt[c]]) {
                answer.push_back(s);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    vector<string> ord = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> cou = { 2, 3, 4 };

    vector<string> result = solution(ord, cou);

    for (int i = 0; i < result.size(); i++) {
        cout << "Result : " << result[i] << endl;
    }
        
    return 0;
}