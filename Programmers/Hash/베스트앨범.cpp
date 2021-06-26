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
    // �帣���� ���Ƚ�� ����
    map < string, int> music;
    // �� �帣���� ���� �뷡�� ����� ��������
    map<string, map<int, int>> musiclist;

    for (int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }

    // �帣�� �� ������ ������ �ݺ�
    while (music.size() > 0) {
        string genre;
        int max = 0;
        // �帣 �߿��� ���� ���� ����� �� ã��
        for (auto mu : music) {
            if (max < mu.second) {
                max = mu.second;
                genre = mu.first;
            }
        }

        // 2� ����
        for (int i = 0; i < 2; i++) {
            int val = 0;
            int index = -1;
            // �뷡 �� ���� ���� ����� �� ����
            for (auto ml : musiclist[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    index = ml.first;
                }
            }
            // �뷡�� 0 ~ 1�� �ۿ� ���ٸ�
            if (index == -1) { break; }
            // ���� �� ���� �� �ش� music�� musiclist���� ����
            answer.push_back(index);
            musiclist[genre].erase(index);
        }
        // music���� ����� genre ����
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