#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>> &adjacent_list, vector<bool> &visited_list, int start);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    vector<vector<int>> adjacent_list; //인접 리스트
    vector<bool> visited_list; //방문 배열

	int Node, Edge, input1, input2, cnt = 0;
    cin>>Node>>Edge;

    adjacent_list.resize(Node+1);
    visited_list.resize(Node+1, false);

	for(int i=0; i<Edge; i++){
        cin>>input1>>input2;

        adjacent_list[input1].push_back(input2);
        adjacent_list[input2].push_back(input1);
    }

    for(int i=1; i<=Node; i++) {
        if(visited_list[i] == false) {
            DFS(adjacent_list, visited_list, i);
            cnt++;
        }
    }

    cout<<cnt<<endl;
}

void DFS(vector<vector<int>> &adjacent_list, vector<bool> &visited_list, int start) {
    //현재 노드랑 방문 노드 같은 경우(자기 자신)도 고려해야 하는가?
    
    //현재 노드 방문 기록
    //start의 인접 리스트 돌기
    //인접 리스트가 2, 5라고 치면
    //2가 이미 방문되었는지 확인하고
    //방문안되어있으면 DFS 다시 2를 start로 바꾸고 DFS
    //그 다음, 5로 같은 동작

    visited_list[start] = true;

    vector<int>::iterator it;
    for(it=adjacent_list[start].begin(); it != adjacent_list[start].end(); it++) {
        if(visited_list[*it] == false) {
            DFS(adjacent_list, visited_list, *it);
        }
    }
}