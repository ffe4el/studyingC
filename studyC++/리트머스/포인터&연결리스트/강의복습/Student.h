#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_STRING 100
class Student{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];

    public:
    //기본 생성자를 겸해서 사용할 수  있도록 만든 생성자
    Student(int i=0, char* n="", char* d=""){set(i,n,d);} //set함수를 이용해 데이터 멤버를 초기화함
    void set(int i, char* n, char* d){
        id = i;
        strcpy(name, n); //문자열 복사함수
        strcpy(dept, d); //문자열 복사함수
    }
};