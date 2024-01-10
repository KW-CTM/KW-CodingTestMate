#include <iostream>

using namespace std;

int main(){
    int num, result = 1, start = 1, end = 1, sum=1;
    cin >> num;

    while(start != num){        
        if(sum < num){
            end += 1;
            sum += end;
        }
        else{
            if(sum == num){
                result += 1;
            }
            sum -= start;
            start += 1;
        }
    }
    
    cout << result << "\n";
}

//구간 합
// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){    
//     int num, result = 1, start = 1, end = 1;
//     cin >> num;
//     vector <int> array(num+1, 0);

//     for(int i=1; i<=num; i++){
//         array[i] = array[i-1] + i;
//     }

//     while(start != num){
//         int sum = array[end] - array[start-1];
//         if(sum == num){
//             result += 1;
//         }
        
//         if(sum < num){
//             end += 1;
//         }
//         else if(sum >= num){
//             start += 1;
//         }
//     }
    
//     cout << result << "\n";
// }