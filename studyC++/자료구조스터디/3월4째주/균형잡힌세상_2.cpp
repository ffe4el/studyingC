#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(){
    stack <int> st;
    string ans = "yes";
    string str;
    while(true){
        getline(cin, str);
        for(int i=0; i<str.length(); i++){
            if(str[i]=='(' || str[i]=='['){
                st.push(str[i]);
            }
            else if(str[i]==')' || str[i]==']'){
                if(st.empty()){
                    ans = "no";
                }
                else{
                    char prev = st.top();
                    if((str[i] == ']'&& prev !='[')||(str[i] == ')'&& prev !='(')){
                        ans = "no";
                        continue;
                    }
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            ans = "no";
        }
        
    }
    

    cout<<ans<<endl;
    

    return 0;
}