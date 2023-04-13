#include "Node.h" //Node클래스 포함
class LinkedStack{
    Node* top; //헤드 포인터
public :
    LinkedStack() {top=NULL;}                           // 생성자
    //현재의 연결 리스트에 동적으로 할당한 노드가ㅣ 하나라도 있으면 모두 동적으로 해제해야 함.
    ~LinkedStack() {while(!isEmpty()) delete pop();}    // 소멸자
    bool isEmpty(){return top == NULL;}
    void push(Node *p){
        if(isEmpty()) top = p;
        else{
            p -> setLink(top);
            top = p;
        }
    }

    Node* pop(){
        if(isEmpty()) return NULL;
        // 공백상태가 아니면 현재의 top을 p 다음으로 연결하고 포인터 top을 새로 들어온 노드인 p로 변경함.
        Node *p = top;
        top = top -> getLink();
        return p;
    }

    Node* peek(){return top;}
    
    void display(){
        printf("[LinkedStack]\n");
        
        // 임시 포인터 변수 p를 선언하고 top을 복사한 후 루프가 반복될 때 마다 p가 연결 리스트의 다음 노드를 가리키도록 해서 
        // 모든 노드를 한 번 씩 방문할 수 있도록 함. 
        for(Node *p = top; p!=NULL; p=p->getLink())
            // p->display(); ? 이거 왜 오류?
        printf( "\n");
    }

};