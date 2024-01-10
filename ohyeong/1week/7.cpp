#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cnt, need, result = 0;
    cin >> cnt >> need;
    vector <int> array(cnt);
    int start = 0, end = cnt-1;

    for(int i=0; i<cnt; i++){
        cin >> array[i];
    }

    sort(array.begin(), array.end());  
    
    while(start < end){
        int sum = array[start] + array[end];
        if(sum < need){
            start += 1;
        }
        else{
            if(sum == need){
                result += 1;
            }
            end -= 1;
        }
    }
    cout << result << "\n";
}