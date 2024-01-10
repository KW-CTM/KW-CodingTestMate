#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int num, data;
    cin >> num;

    vector <int> result(num);
    vector <int > array(num);
    for(int i=0; i<num; i++){
        cin >> data;
        result[i] = data;
        array[i] = data;
    }

    queue<int> q[10];
    queue<int> aq[10];
    for(int i=0; i<5; i++){
        for(int j=0; j<num; j++){
            int a;
            a = array[j]%10;
            array[j] /= 10;
            
            q[a].push(result[j]);
            aq[a].push(array[j]);
        }

        int size=0;
        for(int k=0; k<10; k++){
            while(!q[k].empty()){
                result[size] = q[k].front();
                array[size++] = aq[k].front();
                q[k].pop();
                aq[k].pop();
            }
        }
    }

    for(int i=0; i<num; i++){
        cout<< result[i]<<"\n";
    }
}