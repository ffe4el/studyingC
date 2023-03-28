#include <iostream>
using namespace std;

int main(){
    int n;
    int ans=0;
    // int total;
    cin >> n;
    //만약 정확하게 n킬로그램을 만들 수 없다면 -1 출력
    if(n%5 != 0 && n%3 != 0){
        ans = -1;
    }
    else{
        while(n!=0){
            if(n%5==0 && n%3==0){
                n = n/5;
                ans+=1;
            }
            else if(n%5==0 && n%3!=0){
                n = n/5;
                ans+=1;
            }
            else if(n%5!=0 && n%3==0){
                n = n/3;
                ans+=1;
            }
        }
    }
    cout << ans << endl;

    
    return 0;
}