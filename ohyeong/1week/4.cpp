#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, repeat, cnt;
    int array[1025][1025];

    cin >> cnt >> repeat;

    for(int i=1; i<=cnt; i++){
        for(int j=1; j<=cnt; j++){
            cin >> num;

            if(i-1 > 0 && j-1 > 0){
                array[i][j] = num + array[i-1][j] + array[i][j-1] - array[i-1][j-1];
            }
            else if(i-1 > 0){
                array[i][j] = num + array[i-1][j];
            }
            else if(j-1 > 0){
                array[i][j] = num + array[i][j-1];
            }
            else{
                array[i][j] = num;
            }
        }
    }

    for(int i=0; i<repeat; i++){
        int firstx, firsty, endx, endy;
        cin >> firstx >> firsty;
        cin >> endx >> endy;
        
        if(firstx-1 > 0 && firsty-1 > 0){
            cout << array[endx][endy] - array[firstx-1][endy] - array[endx][firsty-1] + array[firstx-1][firsty-1] <<"\n";
        }
        else if(firstx-1 > 0){
            cout << array[endx][endy] - array[firstx-1][firsty]<<"\n";
        }
        else if(firsty-1 > 0){
            cout << array[endx][endy] - array[firstx][firsty-1]<<"\n";
        }
        else{
            cout << array[endx][endy]<<"\n";
        }
    }
}