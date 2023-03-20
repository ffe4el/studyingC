#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int tc;
    
    cin >> tc;
    while(tc>0){
        tc--;
        string w;
        stack<char> s;
        string ans="YES";
        cin >> w;
        for(int j=0; j<w.length(); j++){
            if (w[j]=='('){
                s.push(w[j]);
            }
            else if(!s.empty() && w[j]==')' && s.top()=='('){
                s.pop();
            }
            else{
                ans = "NO";
                break;
            }
        }
        if(!s.empty()){
            ans ="NO";
        }
        cout << ans<< endl;
    }
    return 0;
}