#include <iostream>
#include <vector>
using namespace std;

int main() {

    int count, num, max = 0;
    double sum = 0;
    vector<int> score;
    
    cin >> count;
    
    for(int i = 0; i < count; i++) {
        cin >> num;
        score.push_back(num);
        if(num > max)
            max = num;
    }

    for(int i = 0; i < count; i++) 
        sum += score.at(i)/max * 100.0;
    
    printf("%.3f\n", sum/count);
}