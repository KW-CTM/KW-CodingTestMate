#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(vector<vector<int>> &adj_list, vector<bool> &visited_DFS, int start);
void BFS(vector<vector<int>> &adj_list, vector<bool> &visited_BFS, int start);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<vector<int>> adj_list;
    vector<bool> visited_DFS;
    vector<bool> visited_BFS;
    
    int Node, Edge, input1, input2, start;
    cin >> Node >> Edge >> start;

    adj_list.resize(Node+1);
    visited_DFS.resize(Node+1, false);
    visited_BFS.resize(Node+1, false);

    for(int i=0; i<Edge; i++) {
        cin>>input1>>input2;
        adj_list[input1].push_back(input2);
        adj_list[input2].push_back(input1);
    }

    for(int i=1; i<=Node; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    
    // for(int i=1; i<=Node; i++) {
    //     if(visited_DFS[i] == false) {
    //         DFS(adj_list, visited_DFS, i);
    //     }
    // }
    DFS(adj_list, visited_DFS, start);
    cout<<endl;

    BFS(adj_list, visited_BFS, start);
    cout<<endl;
}

void DFS(vector<vector<int>> &adj_list, vector<bool> &visited_DFS, int start) {
    visited_DFS[start] = true;
    cout<<start<<" ";

    for(int i : adj_list[start]) {
        if(visited_DFS[i] == false) {
            DFS(adj_list, visited_DFS, i);
        }
    }
}

void BFS(vector<vector<int>> &adj_list, vector<bool> &visited_BFS, int start) {
    queue<int> queue_list;
    queue_list.push(start);
    visited_BFS[start] = true;

    // 1 -> 234
    // 2 -> 356
    // 이라면 

    // queue가 비어있을 때 까지
    // 1 빼고, 1에 연결된 234 넣기(넣을때 이미 방문하지 않은 것들만 넣기)
    // 넣을 때 방문 체크하기
    // 2 빼고, 2에 연결된 356 넣기... 반복

    while(!queue_list.empty()) {
        int node = queue_list.front();
        cout<<node<<" ";
        queue_list.pop();

        for(int i : adj_list[node]){
            if(visited_BFS[i] == false) {
                queue_list.push(i);
                visited_BFS[i] = true;
            }
        }
    }


}