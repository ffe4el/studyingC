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
    CircularDeque input, output;
    ArrayStack stack;
    int cnt;
    int num;
    char how;
 
    cin >> cnt >> how; // 조건 입력 받기
    for (int i = 0; i < cnt; i++) { // 일단 큐로 넣기
        cin >> num;
        input.enqueue(num);
    }
    if (how == 'd') { // 내림차순일때
        while (!input.isEmpty()) {
            int k = input.dequeue();
            if (k == cnt) {
                output.enqueue(k);
                cnt--;
 
                if (!stack.isEmpty()) {
                    while (cnt == stack.peek()) {
                        output.enqueue(stack.pop());
                        cnt--;
                    }
                }
            }
            else {
                stack.push(k);
            }
        }
        if (cnt == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
 
    else if (how == 'a') { // 오름차순일때
        int a_cnt = 1;
        while (!input.isEmpty()) {
            int k = input.dequeue();
            if (k == a_cnt) {
                output.enqueue(k);
                a_cnt++;
 
                if (!stack.isEmpty()) {
                    while (a_cnt == stack.peek()) {
                        output.enqueue(stack.pop());
                        a_cnt++;
                    }
                }
            }
            else {
                stack.push(k);
            }
        }
        if (a_cnt == cnt + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}