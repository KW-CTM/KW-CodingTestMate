#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0;
    char num;

    cin >> N >> M;
    vector<vector<int>> nums(N + 1, vector<int>(M + 1, 0));
    bool visited[N+1][M+1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> num;
            if(num == '1')
                nums[i][j] = 1;
        }
    }

    queue<pair<int, int>> bfs;
    bfs.push({1, 1});
    visited[1][1] = true;

    while(!bfs.empty()) {

        bool flag = false;
        int fir = bfs.front().first;
        int sec = bfs.front().second;
        bfs.pop();
        cnt++;

        if((fir == N) && (sec == M))
            break;
        
        if((fir-1 != 0) && (nums[fir-1][sec] == 1) && (!visited[fir-1][sec])) {
            bfs.push({fir-1, sec});
            visited[fir-1][sec] = true;
            flag = true;
        }
        if((fir+1 <= N) && (nums[fir+1][sec] == 1) && (!visited[fir+1][sec])) {
            bfs.push({fir+1, sec});
            visited[fir+1][sec] = true;
            flag = true;
        }
        if((sec-1 != 0) && (nums[fir][sec-1] == 1) && (!visited[fir][sec-1])) {
            bfs.push({fir, sec-1});
            visited[fir][sec-1] = true;
            flag = true;
        }
        if((sec+1 <= M) && (nums[fir][sec+1] == 1) && (!visited[fir][sec+1])) {
            bfs.push({fir, sec+1});
            visited[fir][sec+1] = true;
            flag = true;
        }

        if(!flag)
            cnt--;
    }
    cout << cnt;
}