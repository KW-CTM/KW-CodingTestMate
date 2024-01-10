#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[1000];
vector <bool> visited;
void DFS(int cur);

int main(){
    int node, edge, start, end, result = 0;
    cin >> node >> edge;

    visited.assign(node+1, false);
    for(int i=0; i<edge; i++){
        cin >> start >> end;
        graph[start].push_back(end);      //방향 없는 그래프라서 양쪽다 저장하기
        graph[end].push_back(start);
    }
    
    for(int i=1; i<=node; i++){
        if(!visited[i]){                  //방문했는지 확인후 재귀함수 실행
            DFS(i);
            result++;
        }
    }
    cout << result <<"\n";
}

void DFS(int cur){
    visited[cur] = true;
    for(int i=0; i<graph[cur].size(); i++){
        int num = graph[cur][i];
        if(!visited[num]){              //방문하지 않았다면 재귀함수 실행
            DFS(num);
        }
    }
}