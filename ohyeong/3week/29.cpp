#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    vector<int> array(num);
    for(int i=0; i<num; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    int cnt, search;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> search;
        int start=0, end=array.size()-1, mid;

        while(start <= end){
            mid=(start+end)/2;
            if(array[mid] == search){
                break;
            }
            else if(array[mid] > search){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        if(array[mid] == search){
            cout << 1 <<"\n";
        }
        else{
            cout << 0 <<"\n";
        }
    }
}