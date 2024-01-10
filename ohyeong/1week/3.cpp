#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt, repeat, num;
    int array[100001];
    array[0] = 0;
    
    cin >> cnt >> repeat;
    
    for(int i=1; i<=cnt; i++){
        cin >> num;
        array[i] = array[i-1] + num;
    }

    for(int i=0; i<repeat; i++){
        int k, j;
        cin >> k >> j;
        cout << array[j] - array[k-1]<< "\n";
    }
}