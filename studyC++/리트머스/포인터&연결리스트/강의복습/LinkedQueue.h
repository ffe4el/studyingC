#include "Node_que.h"
class LinkedQueue{
    Node* front; //가장 먼저 삽인된 노드의 포인터
    Node* rear; //가장 마지막에 삽입된 노드의 포인터
    
public:
    //생성자에서 반드시 프론트와 리어를 널로 초기화해야함. -> 멤버 초기화 리스트 사용.
    LinkedQueue():front(NULL), rear(NULL){ }
    ~LinkedQueue() {while(!isEmpty()) delete dequeue();}
    bool isEmpty(){ return front == NULL;}

    //삽입연산 : 연결된 큐의 맨 뒤에 노드 삽입
    void enqueue(Node* p){
        if(isEmpty()) front= rear = p;
        else{
            rear -> setLink(p);
            rear = p;
        }
    }

    Node* dequeue(){
        if(isEmpty()) return NULL;
        Node* p = front;
        front = front->getLink();
        if(front == NULL) rear = NULL;
        return p;
    }

    Node* peek(){return front;}
    
    void display(){
        for(Node* p=front; p!=NULL; p=p->getLink())
            p->display();
    }


};