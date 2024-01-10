#include <iostream>
#include <vector>

using namespace std;

void quickSort(int start, int end, vector<int> &array){
    if(start >= end) return;
    int i = start;
    int j = end-1;
    int pivot = end;

    while(i <= j){
        while(array[i] <= array[pivot]){
            i++;
            cout<<i<<" ";
        }
        cout<<endl;
        while(array[j] >= array[pivot]){
            j--;
            cout<<j<<" ";
        }
        cout<<endl;
        if(i > j){
            int num = array[j];
            array[j] = array[pivot];
            array[pivot] = num;
        }
        else{
            int num = array[i];
            array[i] = array[j];
            array[j] = num;
        }
    }

    quickSort(start, j-1, array);
    quickSort(j+1, end, array);
}

int main(){
    int cnt, num;
    cin >> cnt >> num;

    vector <int> array(cnt+1);
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    quickSort(1, cnt, array);

    cout<<array[num]<<"\n";
}