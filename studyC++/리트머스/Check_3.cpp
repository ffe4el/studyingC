#include <iostream>
#include <string>
using namespace std;

void checkMatching(string Str, int cnt){
    string ans;
    int bc = 0;
    bool quotes=false;
    int a;
    a = Str.length();
    // cout << a<<endl;
    for(int i=0; i<a; i++){
        if(Str[i]=='\''){
            //그전에 \가 있었으면, 그 뒤에 '가 나오는걸 인정X
            if(i-1>=0 && Str[i-1]=='\\'){ 
                cout<<"zzing"<<endl;
                continue;
            }
            if (quotes){    //작은따옴표닫기
                bc++;
                cout<<"close"<<endl;
                quotes=false;
            }
            else {  //작은따옴표 열기
                cout<<"open"<<endl;
                quotes = true;
            }
        }
    }

    if (quotes){
        ans = "Error";
    }
    else{
        ans="OK";
    }

    cout << ans <<", Line_count : "<<cnt<<", bracket_count : "<<bc<<endl;

}

int main(){
    string Str,temp;
    int cnt;
    while(true){
        getline(cin,temp);
        if(temp=="EOF")break;
        cnt++;
        Str.append(temp);
        // Str.append("\n");
        // cin.clear();
    }
    checkMatching(Str, cnt);
    return 0;
}