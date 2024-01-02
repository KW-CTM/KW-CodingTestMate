#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dna_length, password_length, i, j, cnt=0;
    char input;
    vector<char> dnas;

    cin>>dna_length>>password_length;
    for(i=0; i<dna_length; i++) {
        cin>>input;
        dnas.push_back(input);
    }

    int require_a, require_c, require_g, require_t;
    int a_cnt=0, c_cnt=0, g_cnt=0, t_cnt=0;
    cin>>require_a>>require_c>>require_g>>require_t;

    i=0; j=0;
    while(true){
        if(j>=dna_length) break;

        switch (dnas[j])
        {
        case 'G': g_cnt++; break;
        case 'A': a_cnt++; break;
        case 'T': t_cnt++; break;
        case 'C': c_cnt++; break;
        default:
            break;
        }

        if(a_cnt >= require_a && c_cnt >= require_c && g_cnt >= require_g && t_cnt >= require_t) {
            if(j-i+1 == password_length) {
                    cnt++;
                switch (dnas[i])
                {
                case 'G': g_cnt--; break;
                case 'A': a_cnt--; break;
                case 'T': t_cnt--; break;
                case 'C': c_cnt--; break;
                default:
                    break;
                }
                i++;
            }
        } 

        j++;
    }

    printf("%d\n", cnt);
}