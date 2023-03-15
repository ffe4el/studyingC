#include <iostream>
#include <string>
using namespace std;

void checkMatching(string Str, int cnt){
    // ArrayStack stack;
    string ans;
    int qc = 0;
    bool quotes=false;
    int a;
    a = Str.length();
    for(int i=0; i<a; i++){
        if(Str[i]=='\''){
            if(i-1>0 && Str[i-1]=='\\'){
                i++;
                continue;
            }   
            if (quotes){    //작은따옴표닫기
                qc++;
                quotes=false;
            }
            else {  //작은따옴표 열기
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
    // if(tt%2==1){ //작은따옴표가 홀수개면
    //     ans = "Error";
    // }
    // qc = tt/2;

    cout << ans <<", Line_count : "<<cnt<<", quotes_count : "<<qc<<endl;

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
        cin.clear();
    }
    checkMatching(Str, cnt);

    return 0;
}