#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int cnt, result = 0, start=1;
    cin >> cnt;

    vector<pair<int, int>> graph[cnt+1];

    for(int i=1; i<=cnt; i++){
        int s,e,v;
        cin >> s;
        while(1){
            cin >> e;
            if(e == -1) break;

            cin >> v;
            graph[s].push_back(make_pair(e, v));
        }
    }

    queue <int> q;
    for(int t=0; t<2; t++){        //처음에는 임의로 1를 넣어서 실행, 그 다음에는 제일 멀리 있는 노드부터 실행
        vector<bool> visited(cnt+1, 0);
        vector <int> sum(cnt+1, 0);
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()){
            int i = q.front();
            for(int j=0; j<graph[i].size(); j++){
                int num = graph[i][j].first;
                if(!visited[num]){             //방문하지 않았다면 큐에 집어넣기
                    q.push(num);
                    visited[num] = true;
                    sum[num] = sum[i] + graph[i][j].second;      //거리 합 배열에 저장하기
                }
            }
            q.pop();
        }
        start = max_element(sum.begin(), sum.end()) - sum.begin();   //최댓값 배열번호 저장
        int k = *max_element(sum.begin(), sum.end());   
        if(k > result) result = k;                         //현재 합의 최댓값이 결과값보다 크다면 결과값 업데이트
    }

    cout << result <<"\n";
}

//임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나다.