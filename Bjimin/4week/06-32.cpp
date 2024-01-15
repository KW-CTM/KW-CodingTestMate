#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, K, input, cnt = 0;
    cin>>N>>K;

    vector<int> prices;

    for(int i=0; i<N; i++){
        cin>>input;
        prices.push_back(input);
    }

    for(int i=prices.size()-1; i>=0; i--) {
        int res = K/prices[i];
        if(res > 0) {
            cnt += res;
            K -= prices[i] * res;
        }
    }

    cout<<cnt<<endl;
}