#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, a, result=0, sum=0;
    cin >> n >> a;
    vector<int> array(n+1);
    for(int i=1; i<=n; i++){
        cin >> array[i];
    }

    for(int i=n; i>0 && a>0; i--){
        int k = a/array[i];
        result += k;
        a -= k*array[i];
    }

    cout << result << "\n";
}