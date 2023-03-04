#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int SUM(int x, int y);
double SUM(double x, double y);
string SUM(string a, string b);
int SUB(int x, int y);
double SUB(double x, double y);
int MULT(int x, int y);
double MULT(double x, double y);
int DIV(int x, int y);
double DIV(double x, double y);
int MOD(int x, int y);


int main(){
    int type;
    cin >> type;
    if(type==1){
        int a,b ;
        char k;
        cin>>a>>k>>b;
        if(k=='+'){
            cout << SUM(a,b) << endl;
        }
        else if(k=='-'){
            cout << SUB(a,b) << endl;
        }
        else if(k=='*'){
            cout << MULT(a,b) << endl;
        }
        else if(k=='/'){
            cout << DIV(a,b) << endl;
        }
        else if(k=='%'){
            cout << MOD(a,b) << endl;
        }
        else{
            cout<<"incorrect"<<endl;
        }
    }
    else if(type==2){
        double a;
        char k;
        double b;
        cin>>a>>k>>b;
        if(k=='+'){
            cout << fixed << setprecision(2) << SUM(a,b) << endl;
        }
        else if(k=='-'){
            cout << fixed << setprecision(2) << SUB(a,b) << endl;
        }
        else if(k=='*'){
            cout << fixed << setprecision(2) << MULT(a,b) << endl;
        }
        else if(k=='/'){
            cout << fixed << setprecision(2) << DIV(a,b) << endl;
        }
        else {
            cout<<"incorrect"<<endl;
        }
    }
    else{
        string a, b;
        char k;
        cin>>a>>k>>b;
        if(k=='+'){
            cout<<SUM(a,b)<<endl;
        }
        else {
            cout<<"incorrect"<<endl;
        }
        
    }
    return 0;
}

int SUM(int x, int y){
    return x+y;
}

double SUM(double x, double y){
    // 소수 2번째 숫자까지 출력
    return x+y;
}

string SUM(string a, string b){
    return a+b;
}

int SUB(int x, int y){
    return x-y;
}

double SUB(double x, double y){
    return x-y;
}

int MULT(int x, int y){
    return x*y;
}

double MULT(double x, double y){
    return x*y;
}

int DIV(int x, int y){
    return x/y;
}

double DIV(double x, double y){
    return x/y;
}

int MOD(int x, int y){
    return x%y;
}