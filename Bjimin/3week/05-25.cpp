#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(vector<vector<int>> &adj_list, vector<bool> &visited_list, int start, int ret);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<vector<int>> adj_list;
    
    int Node, Edge, input1, input2, dep;
    cin >> Node >> Edge;

    adj_list.resize(Node);
    vector<bool> visited_list(Node, false);


    //깊이가 5일 경우, 중단하고 1 출력
    //길이가 5가 되는 경우가 없으면 0 출력

    //1 -> 2 -> 3 -> 4 끝
    //5 -> 6 -> 3(이미 방문했어도 또 가도 됨) -> 2 -> 1

    for(int i=0; i<Edge; i++) {
        cin>>input1>>input2;

        adj_list[input1].push_back(input2);
        adj_list[input2].push_back(input1);
    }

    for(int i=0; i<Node; i++) {
        //vector<bool> visited_list(Node, false);
        bool ret = DFS(adj_list, visited_list, i, 1);

        if(ret) {
            cout<<1<<endl;
            return 0;
        }
    }

    cout<<0<<endl;
}

bool DFS(vector<vector<int>> &adj_list, vector<bool> &visited_list, int start, int ret) {
    visited_list[start] = true;
    
    if(ret >= 5) {
        return true;
    }

    vector<int>::iterator it;
    for(it=adj_list[start].begin(); it != adj_list[start].end(); it++) {
        if(visited_list[*it] == false) {
            if(DFS(adj_list, visited_list, *it, ret+1) == true){
                return true;
            }
        }
    }

    //37line 주석처리하고 이거 추가함
    visited_list[start] = false;

    return false;
}