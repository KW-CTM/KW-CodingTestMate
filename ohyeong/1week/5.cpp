#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num, result = 0;
    cin >> N >> M;
    vector<int> array(N+1 ,0);

    for(int i=1; i<=N; i++){
        cin >> num;
        array[i] = array[i-1] + num;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            if((array[i] - array[j-1]) % M == 0){
                result += 1;
            }
        }
    }

    cout << result << "\n";
}