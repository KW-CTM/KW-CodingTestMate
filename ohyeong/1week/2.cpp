#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<double> A;
    // int cnt, num, M = 0;
    // double result = 0;
    // cin >> cnt;

    // for(int i=0; i<cnt; i++){
    //     cin >> num;
    //     A.push_back(num);
    //     if(num > M) M = num;
    // }
    
    // for(int i=0; i<cnt; i++){
    //     result += A[i]/M*100;
    // }
    // result /= cnt;
    // cout << result << endl;

    int cnt, num, M = 0;
    double result = 0;
    cin>>cnt;

    for(int i=0; i<cnt; i++){
        cin >> num;
        if(num > M) M = num;
        result += num;
    }

    result = result * 100.0/M/cnt;
    cout<< result << endl;
}