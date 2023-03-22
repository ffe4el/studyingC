#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(){
    stack <int> st;
    string word;
    while (word != "."){
        
        string word;
        string ans="yes";
        getline(cin, word);
        if (word=="."){
            exit(0);
        }
        for(int i=0; i<word.length(); i++){
            if(word[i]=='('){
                st.push(word[i]);
                // cout<<word[i]<<endl;
            }
            else if(word[i]=='['){
                st.push(word[i]);
                // cout<<word[i]<<endl;
            }
            else if(word[i]==')' || word[i]==']'){
                if(st.empty()){
                    ans = "no";
                    break;
                }
                else{
                    if(word[i]==')'){
                        if(st.top()=='('){
                            cout << st.top()<<endl;
                            st.pop();
                        }
                        else{
                            ans = "no";
                            break;
                        }
                    }
                    else if(word[i]==']'){
                        if(st.top()=='['){
                            cout << st.top()<<endl;
                            st.pop();
                        }
                        else{
                            ans = "no";
                            break;
                        }
                    }
                }
                
            }
            if (word[i]=='.'){
                continue;
            }
        }

        if(!st.empty()){
            ans="no";
        }

        cout << ans << endl;
    }
    

    return 0;
}