#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cnt, sum=0;
    cin >> cnt;

    vector<int> array(cnt+1, 0);
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    for(int i=2; i<=cnt; i++){
        int num;
        for(int j=1; j<=i; j++){
            if(array[i] < array[j]){
                num = array[i];
                for(int k=i-1; k>=j; k--){
                    array[k+1] = array[k];
                }
                array[j] = num;
                break;
            }
        }
    }

    vector<int> result(cnt+1, 0);
    for(int i=1;i<=cnt;i++){
        result[i] = result[i-1]+array[i];
    }
    for(int i=1; i<=cnt; i++){
        sum += result[i];
    }
    cout<<sum<<"\n";
}