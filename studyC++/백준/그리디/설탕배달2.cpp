#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    int a,b;
    a = k/5;
    while(1)
    {
        if(a < 0){
            cout << "-1";
            return 0;
        }
        else if((k-(5*a))%3 == 0){
            b = (k-(5*a))/3;
            break;
        }
        a--;
    }
    cout << a+b<<endl;
    return 0;
}