#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cnt, start, end, num, result = 0;
    cin >> cnt;
    vector <int> array(cnt);       //음수도 입력으로 들어옴

    for(int i=0; i<cnt; i++){
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    for(int i=0; i<cnt; i++){
        start = 0;
        end = cnt-1;
        num = i;
        
        while(start < end){
            int sum = array[start] + array[end];
            
            if(sum < array[num] || start == num){
                start += 1;
            }
            else if(sum > array[num] || end == num){
                end -= 1;
            }
            else if(sum == array[num]){
                result += 1;
                break;
            }
        }
    }

    cout << result << "\n";
}