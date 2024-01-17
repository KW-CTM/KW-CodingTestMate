#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, result=0, num;
    cin >> n;

    priority_queue <int, vector<int>, greater<int>> pq;    //오름차순 우선순위 큐
    for(int i=0; i<n; i++){
        cin >> num;
        pq.push(num);
    }

    for(int i=0; i<n-1; i++){     //맨위 두개 빼서 더한 후 다시 넣음
        int n1, n2;
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();
        pq.push(n1+n2);
        result += n1+n2;
    }

    cout << result << "\n";
}