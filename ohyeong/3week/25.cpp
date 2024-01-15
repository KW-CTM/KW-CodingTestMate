#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[2000];
vector <bool> visited;
int a;
void DFS(int cur);

int main(){
    int node, edge, start, end;
    a=0;
    cin >> node >> edge;

    visited.assign(node, false);
    for(int i=0; i<edge; i++){
        cin >> start >> end;
        graph[start].push_back(end);   //양방향 그래프
        graph[end].push_back(start);
    }
    
    for(int i=0; i<node; i++){
        visited.assign(node, false);  //기록 초기화
        if(!visited[i]){
            a=0;                      //깊이 초기화
            DFS(i);
        }
    }

    cout<< 0 << "\n";    
}

void DFS(int cur){
    a++;                     //노드에 들어가면 깊이 증가
    visited[cur] = true;     //방문 기록함

    if(a>=5){                //깊이가 5면 출력후 프로그램 종료
        cout<<1<<"\n";
        exit(0);
    }
    
    for(int i=0; i<graph[cur].size(); i++){
        int num = graph[cur][i];
        if(!visited[num]){ 
            DFS(num);
            a--;             //노드 나오면 깊이 감소
            visited[num] = false;    //방문 취소함
        }
    }
}