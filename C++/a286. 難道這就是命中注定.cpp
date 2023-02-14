#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    int girl=0;
    int n=0;
    string g_temp;
    string b_temp;
    int small=INT_MAX;
    while(getline(cin, g_temp)){
        girl=0;
        small=INT_MAX;
        for(int x=0;x<g_temp.length();x++){
            if(g_temp[x]!=' '){
                girl += g_temp[x] - '0';
            }
        }
        girl = girl%9==0 ? 9 :  girl%9;
        cin >> n;
        getchar();
        vector<int> boy(n,0);
        for(int y=0;y<n;y++){
            getline(cin, b_temp);
            for(int x=0;x<b_temp.length();x++){
                if(b_temp[x]!=' '){
                    boy[y] += b_temp[x] - '0';
                }
            }
            boy[y] = boy[y]%9==0 ? 9 :  boy[y]%9;
            small = min(abs(boy[y]-girl),small);
        }

        for(int x=0;x<n;x++){
            if(small == abs(boy[x]-girl)){
                cout << x+1 << endl;
                break;
            }
        }
    }
    return 0;
}
