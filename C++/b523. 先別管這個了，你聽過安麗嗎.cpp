#include <iostream>
using namespace std;

int main(){
    string table[500];
    int max_size = 0;
    string take;
    while(getline(cin, take)){
        bool do_not = false;
        for(int x=0;x<max_size;x++){
            if(take==table[x]){
                do_not = true;
            }
        }
        if(do_not){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
            table[max_size++] = take;
        }
    }
    return 0;
}
