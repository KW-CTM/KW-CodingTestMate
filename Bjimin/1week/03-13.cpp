#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input, temp;
    queue<int> que;

    cin>>N;
    
    for(int i=1; i<=N; i++){ //insert cards
        que.push(i);
    }

    int i=0;
    while(que.size() != 1) {
        if(i%2 == 0) {
            que.pop();
        } else {
            temp = que.front();
            que.pop();
            que.push(temp);
        }
        i++;
    }

    printf("%d\n", que.back());   

}