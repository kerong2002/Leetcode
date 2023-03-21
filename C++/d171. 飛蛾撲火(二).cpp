#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N,M;
    while(cin >> N >> M){
        cout << (int)((M*log10(N))+1) << endl;
    }
    return 0;
}
