#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    //06장 우선순위 큐 학습 이후 풀이
    //97p

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;

    cin>>N;
    
    for(int i=1; i<=N; i++){
        cin>>input;

        if(input == 0) {
            if(배열이 비어 있으면) {
                0 출력
            } else {
                배열에서 절대값이 가장 작은 값 출력
                (여러개면 그 중 가장 작은 수 출력)
                그 값을 배열에서 제거
            }
        } else {
            배열에 INPUT 추가
        }
    }

}