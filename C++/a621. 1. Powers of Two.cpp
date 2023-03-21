#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int n=0;
    cin >> n;
    for(int x=0;x<=n;x++){
        cout << "2^" <<x<<" = " << setprecision(100) << pow(2,x) << endl;
    }
    return 0;
}
