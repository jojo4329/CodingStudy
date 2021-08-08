#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> map;
vector<vector<string>> question;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    bool bCheck = false;

    // map에 info 내용 넣기
    for (int i = 0; i < info.size(); i++) {
        istringstream ss(info[i]);
        string strBuf;
        vector<string> tmp;

        while (getline(ss, strBuf, ' ')) {
            tmp.push_back(strBuf);
        }
        map.push_back(tmp);
    }

    // question에 query(질문 기준) 넣기
    for (int i = 0; i < query.size(); i++) {
        istringstream ss(query[i]);
        string strBuf;
        vector<string> tmp;

        while (getline(ss, strBuf, ' ')) {
            if (strBuf == "and") { continue; }
            else {
                tmp.push_back(strBuf);
            }
        }
        question.push_back(tmp);
    }

    // answer 구하기
    for (int i = 0; i < question.size(); i++) {
        //  첫번째 기준 : java and backend and junior and pizza 100
        for (auto m : map) {
            for (int j = 0; j < 5; j++) {  // question[i].size() = 8
                if (j < 4) {
                    if ((question[i][j] == "-") || (question[i][j] == m[j])) { bCheck = true; }
                    else {
                        bCheck = false;
                        break;
                    }
                }
                else {
                    if (stoi(question[i][j]) <= stoi(m[j])) { bCheck = true; }
                    else { 
                        bCheck = false;
                        break;
                    }
                }
                
            }
            if (bCheck == true) { answer[i]++; }
        }
    }

    return answer;
}

int main(void)
{
    vector<string> infomation = { "java backend junior pizza 150", "python frontend senior chicken 210",
        "python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> qu = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<int> result = solution(infomation, qu);

    for (int i = 0; i < result.size(); i++) {
        cout << "Result : " << result[i] << endl;
    }
    

    return 0;
}