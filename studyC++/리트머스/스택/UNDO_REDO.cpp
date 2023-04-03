#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack <char> un;
    stack <char> re;
    int n=11;
    int comp=0;   //n과 비교할 숫자
    string s;
    char c;

    // cin >> n;
    // cin >> s;
    int array[10000];

    // do {
    //     cin >> c;
    //     un.push(c);
    // } while (getc(stdin) == ' ');

    for(int i=0; i<n-1; i++){
        cin >> c;
        un.push(c);
    }
    
    // if(!un.empty()){
    //     if(s.length()<11){
    //         while(!un.empty()){
    //             cout << un.top();
    //             un.pop();
    //         }
    //     }
    //     else{
    //         while(n>1){
    //             cout << un.top();
    //             un.pop();
    //             n--;
    //         }
    //     }
    // }
    // else if(un.empty()){
    //     cout << "EMPTY"<<endl;
    // }

    
    
    // cout<<endl;
    

    // cout << un.size()<<endl;
    

    return 0;
}
