#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, 1, 0, 1, 1, 1, 0, -1 };

int solution(vector<int> arrows) {
    int answer = 0;
    int x = 0;
    int y = 0;
    map<pair<int, int>, bool> node_visited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;

    node_visited[make_pair(0, 0)] = true;

    for (int i = 0; i < arrows.size(); i++) {
        int dir = arrows[i];

        // arrows 방향으로 움직일 때 2배로 움직임.
        for (int j = 0; j < 2; j++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (node_visited[make_pair(nx, ny)] == true && edge_visited[make_pair(make_pair(x, y), make_pair(nx, ny))] == false) {
                answer++;
            }

            node_visited[{nx, ny}] = true;
            edge_visited[{ {x, y}, { nx, ny }}] = true;
            edge_visited[{ {nx, ny}, { x, y }}] = true;
            x = nx;
            y = ny;
        }
    }

    return answer;
}

int main(void)
{
    vector<int> arr = { 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 };

    int result = solution(arr);

    cout << "result : " << result << endl;

    return 0;
}

// 이전에 있던 위치로 돌아가면 방이 생김.
// 다만 이전에 있던 간선을 또 그으면서 가면 안됨.