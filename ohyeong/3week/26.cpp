#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> graph[1001];
vector <bool> visited;
void DFS(int cur);

int main(){
    int node, edge, start, s, e;
    cin >> node >> edge >> start;

    visited.assign(node+1, false);
    for(int i=0; i<edge; i++){
        cin >> s >> e;
        graph[s].push_back(e);            //방향 없는 그래프라서 양쪽다 저장하기
        graph[e].push_back(s);
    }
    
    for(int i=1; i<=node; i++){
        sort(graph[i].begin(), graph[i].end());     //오름차순으로 정렬
    }
    DFS(start);
    cout<<"\n";

    //BFS
    visited.assign(node+1, false);
    queue <int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int i = q.front();
        for(int j=0; j<graph[i].size(); j++){
            int num = graph[i][j];
            if(!visited[num]){             //방문하지 않았다면 큐에 집어넣기
                q.push(num);
                visited[num] = true;
            }
        }
        cout << i<<" ";
        q.pop();
    }
    cout<<"\n";
}

void DFS(int cur){                        //DFS
    visited[cur] = true;
    cout << cur <<" ";
    for(int i=0; i<graph[cur].size(); i++){
        int num = graph[cur][i];
        if(!visited[num]){              //방문하지 않았다면 재귀함수 실행
            DFS(num);
        }
    }
}