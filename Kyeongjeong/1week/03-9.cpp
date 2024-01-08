#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int strLen, passLen, resultCount = 0, temp;
    vector<int> minPass, passCheck;
    string str;

    cin >> strLen >> passLen;
    cin >> str;

    for (int i = 0; i < 4; i++) {
        cin >> temp;
        minPass.push_back(temp);
        passCheck.push_back(0);
    }       

    for (int i = 0; i < strLen; i++) {

        char c = str[i];
        switch (c) {
            case 'A':
                passCheck[0]++;
                break;

            case 'C':
                passCheck[1]++;
                break;

            case 'G':
                passCheck[2]++;
                break;

            case 'T':
                passCheck[3]++;
                break;

            default:
                break;
        }

        if (i >= passLen - 1) {

            int j = i - passLen + 1;
            if((passCheck[0] >= minPass[0]) && (passCheck[1] >= minPass[1]) && (passCheck[2] >= minPass[2]) && (passCheck[3] >= minPass[3]))
                resultCount++;

            char c = str[j];
            switch (c) {
                case 'A':
                    passCheck[0]--;
                    break;

                case 'C':
                    passCheck[1]--;
                    break;

                case 'G':
                    passCheck[2]--;
                    break;

                case 'T':
                    passCheck[3]--;
                    break;

                default:
                    break;
            }
        }
    }
    cout << resultCount << "\n";
}