#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& nums, vector<bool>& visited, int& cnt) {

    visited[node] = true;
    ++cnt;

    if(cnt == 5) {
        cout << 1;
        exit(0);
    }

    for (int i = 0; i < nums[node].size(); i++) {
        int neighbor = nums[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, nums, visited, cnt);
        }
    }
    visited[node] = false;
    --cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeNum = 0, edgeNum = 0, cnt = 0, fir, sec;
    cin >> nodeNum >>edgeNum;

    vector<vector<int>> nums(nodeNum + 1);
    vector<bool> visited(nodeNum, false);

    for(int i = 0; i < edgeNum; i++) {
        cin >> fir >> sec;
        nums[fir].push_back(sec);
        nums[sec].push_back(fir);
    }

    for (int i = 1; i <= nodeNum; i++) {
        if (!visited[i]) {
            dfs(i, nums, visited, cnt);
        }
    }
    cout << 0;
}