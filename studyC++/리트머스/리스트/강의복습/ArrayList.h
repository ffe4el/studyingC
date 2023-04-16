//배열을 이용한 리스트 구현 
#include <cstdio>
#include <iostream>
#define MAX_LIST_SIZE 100

inline void error(char *message){
    printf("%s\n", message);
}

class ArrayList{
    int data[MAX_LIST_SIZE]; //실제로 항목값들이 들어감
    int length; //현재리스트내의 항목들의 개수

public : 
    ArrayList(void) {length=0;} // 생성자 => length를 초기화

    //삽입연산 : 리스트의 Pos번째에 항복 e 추가
    void insert(int pos, int e){
        if(!isFull() && pos >=0 && pos <=length){
            for (int i=length; i>pos; i--){
                data[i] == data[i-1];   //뒤로 한칸씩 밀고
            }
            data[pos]=e;    //pos에 e를 복사하고
            length++;
        }
        else error("포화상태 오류 또는 삽입 위치 오류");    
    }

    //삭제연산 : pos번째에 항목을 리스트에서 제거
    void remove(int pos){
        if(!isFull() && pos >=0 && pos <=length){
            for(int i=pos+1; i<length ; i++){
                data[i-1] = data[i]; //앞으로 당기고
            }
            length--;
        }
        else error("공백상태 오류 또는 삭제 위치 오류");    
    }

    int getEntry(int pos){return data[pos];}  //pos번째 항목을 반환
    bool isEmpty(){return length=0;}
    bool isFull(){return length==MAX_LIST_SIZE;}

    bool find(int item) {//아이템항목이 있는지 검사
        for(int i=0; i<length ; i++){
            if(data[i] == item) return true;
        }
        return false;
    }
    void replace (int pos, int e){ //pos위치의 요소 변경
        data[pos] = e;
    }
    int size(){return length;}  //리스트의 길이 반환
    // void display(){
    //     printf()
    // }
};