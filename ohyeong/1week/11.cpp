#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int cnt, current = 1, num = 1;
    cin >> cnt;
    vector <int> array(cnt+1, 0);
    vector <char> result;
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    stack <int> s;

    while(current != cnt+1){       //현재 가리키는 배열이 총 수가 되기 전까지 반복
        if(num > cnt+1){           //넣는 숫자가 총 수보다 커지면 NO 출력
            cout<<"NO\n";
            return 0;
        }

        if(s.empty()){             //스택이 비어 있으면 추가함
            s.push(num);
            num++;
            result.push_back('+');
        }
        else{
            if(array[current] == s.top()){     //현재 가리키는 배열이 같으면 스택에서 빼고 -출력
                s.pop();
                current++;
                result.push_back('-');
            }
            else{                            //같지 않으면 스택에 넣고 +출력
                s.push(num);
                num++;
                result.push_back('+');
            }
        }
    }

    for(int i=0; result[i] != 0; i++){
        cout<<result[i]<<"\n";
    }

}