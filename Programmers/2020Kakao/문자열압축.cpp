#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for (int i = 1; i <= s.length() / 2; i++) {
        string convert, temp;

        int cnt = 1;
        temp = s.substr(0, i);

        for (int j = i; j < s.length(); j += i) {
            if (temp == s.substr(j, i)) { cnt++; }
            else {
                if (cnt > 1) { convert += to_string(cnt); }
                convert += temp;
                temp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) { convert += to_string(cnt); }

        convert += temp;
        int tcnt = convert.size();
        answer = min(answer, tcnt);
    }

    return answer;
}

int main(void)
{
    string str = "aabbaccc";

    int result = solution(str);

    cout << "result : " << result << endl;

    return 0;
}
