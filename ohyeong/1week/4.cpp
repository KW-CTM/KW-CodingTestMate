#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, repeat, cnt;
    int array[1025][1025];

    cin >> cnt >> repeat;

    for(int i=0; i<=cnt; i++){
        array[i][0] = 0;
        array[0][i] = 0;
    }

    for(int i=1; i<=cnt; i++){
        for(int j=1; j<=cnt; j++){
            cin >> num;
            array[i][j] = num + array[i-1][j] + array[i][j-1] - array[i-1][j-1];
        }
    }

    for(int i=0; i<repeat; i++){
        int firstx, firsty, endx, endy;
        cin >> firstx >> firsty;
        cin >> endx >> endy;
        cout << array[endx][endy] - array[firstx-1][endy] - array[endx][firsty-1] + array[firstx-1][firsty-1] <<"\n";
    }
}