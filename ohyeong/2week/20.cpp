#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int left, int right);
void divide(vector<int> &array, int left, int right);

int main(){
    int cnt;
    cin >> cnt;

    vector<int> array(cnt+1,0);
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    divide(array, 1, cnt);

    for(int i=1; i<=cnt; i++){
        cout<<array[i]<<"\n";
    }
}

void merge(vector<int> &array, int left, int right){
    int size = right-left+1;
    int mid = size/2;
    vector<int> a1(size);
    for(int i=left; i<=right; i++){
        a1[i-left] = array[i];
    }

    int index1=0, index2=right-left;
    for(int i=left; i<=right; i++){
        if(a1[index1] > a1[index2] && index2<size){
            array[i] = a1[index2++];
        }
        else{
            array[i] = a1[index1++];
        }
    }
}

void divide(vector<int> &array, int left, int right){
    int mid;
    if(left < right){
        mid = (left+right)/2;
        divide(array, left, mid);
        divide(array, mid+1, right);
        merge(array, left, right);
    }    
}