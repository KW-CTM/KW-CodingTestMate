#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>>& nums, vector<bool>& dfs_visited) {

    dfs_visited[node] = true;
    cout << node << " ";
    
    for(int i = 0; i < nums[node].size(); i++) {
        int neighbor = nums[node][i];
        if(!dfs_visited[neighbor])
            dfs(neighbor, nums, dfs_visited);
    }
}

void bfs(int start, vector<vector<int>>& nums, vector<bool>& bfs_visited, queue<int>& que) {
    
    que.push(start);
    bfs_visited[start] = true;

    while(!que.empty()) {

        int node = que.front();
        cout << node << " ";
        que.pop();
        
        for(int i = 0; i < nums[node].size(); i++) {

            int neighbor = nums[node][i];
            if(!bfs_visited[neighbor]) {
                bfs_visited[neighbor] = true;
                que.push(neighbor);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeNum, edgeNum, startNode, fir, sec;
    cin >> nodeNum >> edgeNum >> startNode;

    vector<vector<int>> nums(nodeNum + 1);
    for(int i = 0; i < edgeNum; i++) {
        cin >> fir >> sec;
        nums[fir].push_back(sec);
        nums[sec].push_back(fir);
    }

    for(int i = 1; i <= nodeNum; i++) 
        sort(nums[i].begin(), nums[i].end());

    vector<bool> dfs_visited(nodeNum + 1, false);
    dfs(startNode, nums, dfs_visited);
    cout << "\n";

    vector<bool> bfs_visited(nodeNum + 1, false);
    queue<int> que;
    bfs(startNode, nums, bfs_visited, que);
}