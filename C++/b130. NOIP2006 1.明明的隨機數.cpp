#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int n=0;
    int take = 0;
    cin >> n;
    set<int> myset;
    for(int x=0;x<n;x++){
        cin >> take;
        myset.insert(take);
    }
    cout << myset.size() << endl;
    for(set<int>::iterator it = myset.begin(); it!= myset.end();it++){
        cout << *it << " ";
    }
    return 0;
}
