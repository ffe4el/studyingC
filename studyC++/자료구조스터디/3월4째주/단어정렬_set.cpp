#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    
    //단어를 넣을 배열
    char wwt[20001][100];
    for(int i=0; i<tc; i++){
        scanf("%s", wwt[i]);
    }

    set <string>wt;
    for(int i=0; i<tc; i++){
        wt.insert(wwt[i]);
    }

    for(auto i : wt) {
        cout<<i<<endl;
    }

    return 0;
}