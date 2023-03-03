#include <iostream>
#include <string>
using namespace std;


void SUM(int x, int y);
void SUM(double x, double y);
void SUM(string a, string b);
void SUB(int x, int y);
void SUB(double x, double y);
void MULT(int x, int y);
void MULT(double x, double y);
void DIV(int x, int y);
void DIV(double x, double y);
void MOD(int x, int y);


int main(){
    int type;
    cin >> type;
    if(type==1){
        cout<<"정수"<<endl;
        int a;
        string k;
        int b;
        cin>>a;
        cin>>k;
        cin>>b;
        if(k.compare("+")==0){
        SUM(a,b);
        }
        else if(k.compare("-")==0){
            SUB(a,b);
        }
        else if(k.compare("*")==0){
            MULT(a,b);
        }
        else if(k.compare("/")==0){
            DIV(a,b);
        }
        else if(k.compare("%")==0){
            MOD(a,b);
        }
        else{
            cout<<"incorrect"<<endl;
        }
    }
    else if(type==2){
        double a;
        string k;
        double b;
        cin>>a;
        cin>>k;
        cin>>b;
        if(k.compare("+")==0){
            SUM(a,b);
        }
        else if(k.compare("-")==0){
            SUB(a,b);
        }
        else if(k.compare("*")==0){
            MULT(a,b);
        }
        else if(k.compare("/")==0){
            DIV(a,b);
        }
        else {
            cout<<"incorrect"<<endl;
        }
    }
    else{
        string a;
        string b;
        string k;
        cin>>a;
        cin>>k;
        cin>>b;
        if(k.compare("+")==0){
            SUM(a,b);
        }
        else {
            cout<<"incorrect"<<endl;
        }
        
    }
    return 0;
}

void SUM(int x, int y){
    cout<<x+y<<endl;
}

void SUM(double x, double y){
    // 소수 2번째 숫자까지 출력
    cout << fixed;
    cout.precision(2);
    cout<<x+y<<endl;
}

void SUM(string a, string b){
    cout<<a+b<<endl;
}

void SUB(int x, int y){
    cout<<x-y<<endl;
}

void SUB(double x, double y){
    cout << fixed;
    cout.precision(2);
    cout<<x-y<<endl;
}

void MULT(int x, int y){
    cout<<x*y<<endl;
}

void MULT(double x, double y){
    cout << fixed;
    cout.precision(2);
    cout<<x*y<<endl;
}

void DIV(int x, int y){
    cout<<x/y<<endl;
}

void DIV(double x, double y){
    cout << fixed;
    cout.precision(2);
    cout<<x/y<<endl;
}

void MOD(int x, int y){
    cout<<x%y<<endl;
}