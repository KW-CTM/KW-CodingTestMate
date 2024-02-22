#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector <tuple<int, int, int>> graph[10];
vector <bool> visited(10, false);  //방문했는지 확인
vector <long> result(10);          //결과 저장
long lcm;
long gcd(long a, long b);         //최대공약수 구하는 함수
void DFS(int cur);                //깊이 탐색

int main(){
    int n, a,b,p,q;
    cin >> n;

    lcm=1;
    for(int i=0; i<n-1; i++){
        cin >> a >> b >> p >> q;
        graph[b].push_back(make_tuple(a, q, p));  //각 배열에 비율에 맞게 저장함
        graph[a].push_back(make_tuple(b, p, q)); 
        lcm *= p * q / (gcd(p, q));     //모든 비율의 최소공배수를 찾음
    }

    result[0] = lcm;    //임의로 0번째에 최소공배수 넣음
    DFS(0);             //배열 0부터 깊이 우선 탐색 시작

    //모든 수의 최대공약수를 찾음.
    long n_gcd = result[0];
    for(int i=1; i<n; i++){
        n_gcd = gcd(n_gcd, result[i]);    //반복문 돌리면서 모든 수의 최대공약수 찾음.
    }

    for(int i=0; i<n; i++){
        cout << result[i]/n_gcd << " ";  //결과에서 최대공약수를 나눈 값을 출력
    }
}


long gcd(long a, long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void DFS(int cur){
    visited[cur] = true;
    for(int i=0; i<graph[cur].size(); i++){
        int num = get<0>(graph[cur][i]);
        if(!visited[num]){
            //최소공배수를 비율에 맞게 계산후 배열에 저장함
            result[num] = result[cur]*get<2>(graph[cur][i])/get<1>(graph[cur][i]);
            DFS(num);
        }
    }
}