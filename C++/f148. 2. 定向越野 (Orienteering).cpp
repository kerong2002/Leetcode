#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    vector<pair<int,int>> english(26, {0,0});
    vector<int> check(26, 0);
    int row = 0;
    int col = 0;
    cin >> row >> col;
    char take;
    int cnt = 0;
    int find = 0;
    cin >> find;
    for(int y=0;y<row;y++){
        for(int x=0;x<col;x++){
            cin >> take;
            if(take >='a' && take <= 'z'){
                english[take-'a'] = {y,x};
                check[take-'a'] = 1;
                cnt += 1;
            }
        }
    }
    if(find>cnt){
        cout << "Mission fail." << endl;
    }
    else{
        int check_run = 0;
        for(int x=0;x<26;x++){
            if(check_run == find){
                break;
            }
            if(check[x]){
                cout << english[x].first << " " << english[x].second << endl;
                check_run +=1;
            }
        }
    }
    return 0;
}
