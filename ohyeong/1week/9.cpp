#include <iostream>

using namespace std;

int main(){
    string str;
    int size, cnt, A, C, G, T, result=0;
    cin >> size >> cnt;
    cin >> str;
    cin >> A >> C >> G >> T;

    int start=0, end=cnt-1;
    int Acnt=0, Ccnt=0, Gcnt=0, Tcnt=0;
    for(int i=start; i<=end; i++){
        if(str[i] == 'A'){
            Acnt++;
        }
        else if(str[i] == 'C'){
            Ccnt++;
        }
        else if(str[i] == 'G'){
            Gcnt++;
        }
        else if(str[i] == 'T'){
            Tcnt++;
        }
    }

    while(end != size){
        if(Acnt >= A && Ccnt >= C && Gcnt >= G && Tcnt >= T){
            result++;
        }

        if(str[start] == 'A'){
            Acnt--;
        }
        else if(str[start] == 'C'){
            Ccnt--;
        }
        else if(str[start] == 'G'){
            Gcnt--;
        }
        else if(str[start] == 'T'){
            Tcnt--;
        }

        start++;
        end++;

        if(str[end] == 'A'){
            Acnt++;
        }
        else if(str[end] == 'C'){
            Ccnt++;
        }
        else if(str[end] == 'G'){
            Gcnt++;
        }
        else if(str[end] == 'T'){
            Tcnt++;
        }
    }

    cout << result << "\n";
}