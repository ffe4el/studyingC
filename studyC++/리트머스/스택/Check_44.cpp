#include <iostream>
#include <string>

using namespace std;

int main(){
    string a = "/* {{}} */";
    int j = 0;
    for(int i=0; i<a.length(); i++){
        if(j==1){
            if(a[i]=='/'){
                if(i-1>0 && a[i-1]=='*'){
                    j=0;
                    cout<< "닫음 " << j << endl;
                }
            }
        }
        else if(j==0){
            if(a[i]=='*'){
                cout<< a[i-1] <<endl;
                if(i-1>=0 && a[i-1]=='/'){
                    j=1;
                    cout<< "열음 " << j << endl;
                }
            }
        }
    }
    


}