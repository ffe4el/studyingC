#include <iostream>
#include <string>
 
#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100
 
using namespace std;
 
inline void error(const char* message) {
    printf("%s\n", message);
    exit(1);
}
 
class ArrayStack { // Stack 클래스 구현
private:
    int top;
    int data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }
 
    void push(int e) {
        if (isFull()) error("스택 포화 에러");
        data[++top] = e;
    }
 
    int pop() {
        if (isEmpty()) error("스택 공백 에러");
        return data[top--];
    }
 
    int peek() {
        if (isEmpty()) return -1;
        return data[top];
    }
};
 
 
class CircularQueue {
protected:
    int front; // 첫 번째 요소 앞의 위치
    int rear; // 마지막 요소 위치
    int data[MAX_QUEUE_SIZE]; // (정수)요소의 배열
public:
    CircularQueue() { front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
 
    void enqueue(int val) { // 큐에 삽입
        if (isFull())
            error(" error: 큐가 포화상태입니다\n");
        else {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    int dequeue() { // 첫 항목을 큐에서 빼서 반환
        if (isEmpty()) error(" Error: 큐가 공백상태입니다\n");
        else {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    int peek() { // 첫 항목을 큐에서 빼지 않고 반환
        if (isEmpty()) error(" Error: 큐가 공백상태입니다\n");
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }
    void display() { // 큐의 모든 내용을 순서대로 출력
        printf("큐 내용 : ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }
};
 
class CircularDeque : public CircularQueue {
public:
    CircularDeque() { }
    void addRear(int val) { enqueue(val); } // enqueue() 호출
    int deleteFront() { return dequeue(); } // dequeue() 호출
    int getFront() { return peek(); } // peek() 호출
    void display() { // CircularQueue::display()를 재정의
        printf("덱의 내용 : "); // 이 부분만 다름
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }
    int getRear() { // 후단에서 peek
        if (isEmpty())
            error(" Error: 덱이 공백상태입니다\n");
        else return data[rear];
    }
 
    void addFront(int val) { // 전단에 삽입
        if (isFull()) error(" error: 덱이 포화상태입니다\n");
        else {
            data[front] = val;
            front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }
    int deleteRear() { // 후단에서 삭제
        if (isEmpty()) error(" Error: 덱이 공백상태입니다\n");
        else {
            int ret = data[rear];
            rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
};
 
int main() {
    CircularQueue q, pq; //입력큐와 출력큐
    ArrayStack s;
    int n;
    int num;
    char type;
 
    cin >> n >> type; //입력 받을 숫자
    for (int i = 0; i < n; i++) {  //입력큐에 넣기
        cin >> num;
        q.enqueue(num);
    }

    // 오름차순
    if (type == 'a') { 
        int a_n = 1;  //오름차순이니 a_n을 1로 설정
        while (!q.isEmpty()) {  //입력큐가 비어있지 않을동안
            int k = q.dequeue(); //입력큐에서 뺀 수를 k로 설정
            if (k == a_n) { //k와 a_n이 같다면
                pq.enqueue(k);  //k를 출력큐에 바로 넣기
                a_n++;  //k를 넣었으니 비교할 a_n숫자 1 늘리기
 
                if (!s.isEmpty()) {
                    while (a_n == s.peek()) { //스택의 peek이 n과 같을때 동안
                        pq.enqueue(s.pop()); //스택을 pop하고 출력큐에 넣기
                        a_n++; //k를 넣었으니 비교할 a_n숫자 1 늘리기
                    }
                }
            }
            else {  //k와 a_n이 다르다면 k는 대기조(스택)에 넣기
                s.push(k);
            }
        }
        if (a_n == n + 1) cout << "Yes" << endl; //n이 n+1까지 늘어났으면 성공
        else cout << "No" << endl;
    }

    // 내림차순
    else if (type == 'd') { 
        while (!q.isEmpty()) {  //입력큐가 비어있지 않을동안
            int k = q.dequeue();  //입력큐에서 뺀 수를 k로 설정
            if (k == n) {   //k와 n이 같다면
                pq.enqueue(k);  //k를 출력큐에 바로 넣기
                n--; //k를 넣었으니 비교할 n숫자 1 줄이기
 
                if (!s.isEmpty()) { 
                    while (n == s.peek()) { //스택의 peek이 n과 같을때 동안
                        pq.enqueue(s.pop()); //스택을 pop하고 출력큐에 넣기
                        n--; //비교할 n숫자 1줄이기
                    }
                }
            }
            else {  //k와 n이 다르다면 k는 스택에 넣기
                s.push(k);
            }
        }
        if (n == 0) cout << "Yes" << endl;  //n이 0까지 줄어들었으면 성공
        else cout << "No" << endl;
    }
}