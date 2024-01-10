#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;
    vector<int> array;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>input;
        array.push_back(input);
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<=N; j++) {
            if(j == N) {printf("%d ", -1);}

            if(array[j] > array[i]) {
                printf("%d ", array[j]);
                break;
            }
        }
    }

}