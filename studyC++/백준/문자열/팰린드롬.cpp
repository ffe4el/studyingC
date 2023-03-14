#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    int l,r,temp;
    cin>> word;
    //string메소드에서는 문자열의 길이를 length함수로 쓴다.
    l = word.length();
    // cout << word[1] <<endl;
    // cout << l << endl;
    for(int i=0; i<l/2; i++){
        if(word[i]==word[l-i-1]){
            temp =1;
        }
        else{
            temp=0;
        }

    cout << temp<<endl;
    return 0;
}

