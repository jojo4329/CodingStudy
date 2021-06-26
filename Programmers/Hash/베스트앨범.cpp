#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> genre;
vector<int> play;
vector<int> answer;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 장르별로 재생횟수 저장
    map < string, int> music;
    // 각 장르별로 무슨 노래가 몇번씩 저장됬는지
    map<string, map<int, int>> musiclist;

    for (int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }

    // 장르가 다 없어질 때까지 반복
    while (music.size() > 0) {
        string genre;
        int max = 0;
        // 장르 중에서 가장 많이 재생된 것 찾기
        for (auto mu : music) {
            if (max < mu.second) {
                max = mu.second;
                genre = mu.first;
            }
        }

        // 2곡씩 수록
        for (int i = 0; i < 2; i++) {
            int val = 0;
            int index = -1;
            // 노래 중 가장 많이 재생된 것 착기
            for (auto ml : musiclist[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    index = ml.first;
                }
            }
            // 노래가 0 ~ 1곡 밖에 없다면
            if (index == -1) { break; }
            // 리턴 값 저장 후 해당 music을 musiclist에서 삭제
            answer.push_back(index);
            musiclist[genre].erase(index);
        }
        // music에서 사용한 genre 삭제
        music.erase(genre);
    }
    return answer;
}

int main(void)
{
    genre = { "classic", "pop", "classic", "classic", "pop" };
    play = { 500, 600, 150, 800, 2500 };
    
    solution(genre, play);

    for (int i = 0; i < answer.size(); i++) {
        cout << "result : " << answer[i] << endl;
    }

    return 0;
}