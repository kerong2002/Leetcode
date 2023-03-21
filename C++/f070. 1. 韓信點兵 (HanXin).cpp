#include <iostream>
using namespace std;

int main(){
    int arr[6] = {0};
    for(int x=0;x<6;x++){
        cin >> arr[x];
    }
    int ans = 1;
    while(true){
        if(ans%arr[0]==arr[1] && ans%arr[2]==arr[3] && ans%arr[4] ==arr[5]){
            break;
        }
        ans++;
    }
    cout << ans;
    return 0;
}
