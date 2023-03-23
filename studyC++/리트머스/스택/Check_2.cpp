#include <iostream>
#include <string>
using namespace std;

void checkMatching(string &Str, int cnt){
    string ans;
    int qc = 0;
    int aa=0;
    bool quotes=false;
    int a;
    a = Str.length();
    for(int i=0; i<a; i++){
        if(Str[i]=='\''){
            // \'는 한개의 문자로 판별된다...(tlqkf!)
            // if(i-1>=0 && Str[i-1]=='\\'){ 
            //     continue;
            // }
            if (quotes){    //작은따옴표닫기
                qc++;
                quotes=false;
            }
            else {  //작은따옴표 열기
                quotes = true;
            }
        }
    }
    
    for(int i=0; i<a; i++){
        if (Str[i]=='\''){  //만약 작은따옴표가 한개라도 있었으면 aa=1
            aa = 1;
        }
    }
    if(aa==1){  //만약 aa가 1일때
        if (quotes){    //따옴표가 열려있으면 에러
            ans = "Error";
        }
        else{   //닫혀있으면 성공
            ans="OK";
        }
    }
    else{   //그 외 작은 따옴표가 없었으면 에러
        ans="Error";
    }
    cout << ans <<", Line_count : "<<cnt<<", quotes_count : "<<qc<<endl;
}

int main(){
    string Str,temp;
    int cnt=0;
    while(true){
        getline(cin,temp);
        if(temp=="EOF")break;
        cnt++;
        cout << "\\'";
        Str.append(temp);
        // Str.append("\n");
        // cin.clear();
    }
    checkMatching(Str, cnt);
    return 0;
}