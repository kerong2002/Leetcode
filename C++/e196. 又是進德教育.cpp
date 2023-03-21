#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N = 0;
    int M = 0;
    int sign = 0;
    while(cin>>N){
        cin>>M;
        vector<int> table(N+1,0);
        for(int x=0;x<M;x++){
            cin >> sign;
            table[sign]+=1;
        }
        int out=0;
        for(int x=1;x<=N;x++){
            if(table[x]<2){
                out += 1;
            }
        }
        cout << out << endl;
    }
    return 0;
}
