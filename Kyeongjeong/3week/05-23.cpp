#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& nums, vector<bool>& visited) {

    visited[node] = true;
    for (int i = 0; i < nums[node].size(); i++) {
        int neighbor = nums[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, nums, visited);
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeNum, edgeNum, fir, sec, cnt = 0;
    cin >> nodeNum >> edgeNum;

    vector<vector<int>> nums(nodeNum + 1);
    vector<bool> visited(nodeNum + 1, false);

    for (int i = 0; i < edgeNum; i++) {
        cin >> fir >> sec;
        nums[fir].push_back(sec);
        nums[sec].push_back(fir);
    }

    for (int i = 1; i <= nodeNum; i++) {
        if (!visited[i]) {
            ++cnt;
            dfs(i, nums, visited);
        }
    }
    cout << cnt;
}