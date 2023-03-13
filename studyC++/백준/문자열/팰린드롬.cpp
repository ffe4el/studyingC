#include <iostream>
using namespace std;

int main(){
    string word;
    int l,r;
    cin>> word;
    l = sizeof(word)/4-1;
    // cout << sizeof(word)/4-1 << endl;
    for(int i=0; i<l/2; i++){
        if(l %2 ==1){
            if(word[i]==word[l-i]){
                cout<<1<<endl;
            }
        }
        else {
            if(word[i]==word[l-i]){
                cout<<1<<endl;
            }
        }
    }
}

