#include <iostream>
#include <map>
using namespace std;
map<string, char> mp = {
    {".-",'A'}      ,   {"-...",'B'}    ,   {"-.-.",'C'}    ,   {"-..",'D'}     ,
    {".",'E'}       ,   {"..-.",'F'}    ,   {"--.",'G'}     ,   {"....",'H'}    ,
    {"..",'I'}      ,   {".---",'J'}    ,   {"-.-",'K'}     ,   {".-..",'L'}    ,
    {"--",'M'}      ,   {"-.",'N'}      ,   {"---",'O'}     ,   {".--.",'P'}    ,
    {"--.-",'Q'}    ,   {".-.",'R'}     ,   {"...",'S'}     ,   {"-",'T'}       ,
    {"..-",'U'}     ,   {"...-",'V'}    ,   {".--",'W'}     ,   {"-..-",'X'}    ,
    {"-.--",'Y'}    ,   {"--..",'Z'}
};
int main(){
    int n = 0;
    cin >> n;
    string take, buffer;
    cin.clear();
    cin.ignore();
    for(int x=0;x<n;x++){
        getline(cin, take);
        while(true){
            buffer = take.substr(0, take.find(" "));
            cout << mp[buffer];
            if(take.find(" ")==-1){
                break;
            }
            take = take.substr(take.find(" ")+1, take.size());

        }
        cout << endl;
    }
    return 0;
}
