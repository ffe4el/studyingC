#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    do{
        char c;
        cin >> c;
        cout << c << " ";
        // scanf("%c", getc(stdin));
        // printf("%c", fgetc(stdin));
    }while(getc(stdin) == ' ');



    return 0;
}
