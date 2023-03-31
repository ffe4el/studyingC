#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 20;
const int MAX_QUEUE_SIZE = 20;

inline void error(const char* msg) {
    printf("Error : %s!!\n\n", msg);
    exit(0);
}

class ArrayStack {
private:
    int top;
    int data[MAX_STACK_SIZE];

public:
    ArrayStack() : top(-1) { }
    ~ArrayStack() { }


    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void push(int item) {
        if (isFull())
            error("Stack Overflow");
        top++;
        data[top] = item;
    }

    int pop() {
        if (isEmpty())
            error("Stack Underflow");
        int item = data[top];
        top--;
        return item;
    }
    int peek()
    {
        if (isEmpty())
            error("Stack Underflow");
        return data[top];
    }


    void display() {
        printf("스택의 항목 수 = %d : ", top + 1);
        for (int i = 0; i <= top; i++)
            printf("<%2d> ", data[i]);
        printf("\n");
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
            // return data[front];
        }
        return data[front];
    }
    int peek() { // 첫 항목을 큐에서 빼지 않고 반환
        if (isEmpty()) error(" Error: 큐가 공백상태입니다\n");
        // else
            // return data[(front + 1) % MAX_QUEUE_SIZE];
        return data[(front + 1) % MAX_QUEUE_SIZE];
    }
    void display() { // 큐의 모든 내용을 순서대로 출력
        printf("큐 내용 : ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        printf("\n");
    }

    int size()
    {
        return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
};

int main()
{
    int n;
    char ad;
    int input;
    CircularQueue arr;
    CircularQueue que;
    ArrayStack stack;

    cin >> n >> ad; // 반복 횟수와 오름차순,내림차순 입력

    for (int i = 0; i < n; i++) //입력큐를 반복횟수만큼 입력
    {
        cin >> input;
        arr.enqueue(input);
    }
    if (ad == 'a') // 오름차순시
    {
        int num = 1; //1부터 시작
        for (int i = 0; i < n; i++)
        {
            while (!stack.isEmpty() && stack.peek() == num) //저장스택이 비어있지않고, 스택의 맨위가 num과 맞을때
            {
                que.enqueue(stack.peek()); //출력큐에 저장스택의 맨위를 입력후 스택에서 삭제
                stack.pop();
                num++; // 숫자 1 증가
            }

            if (arr.peek() > 0 && arr.peek() < n + 1) //입력큐의 값이 범위 내에 있을 때
            {
                if (arr.peek() == num) //입력큐의 값이 지금 원하는 숫자와 같으면
                {   
                    int a;
                    a=arr.peek();
                    que.enqueue(a); //출력큐에 입력큐의 값을 저장후 삭제
                    arr.dequeue();
                    num++; //숫자 1 증가
                }
                else{ //지금 원하는 숫자와 다르면
                    int b;
                    b=arr.peek();
                    stack.push(b); //저장스택에 입력큐의 값을 저장후 삭제
                    arr.dequeue();
                }
            }
        }
        if (que.size() == n) //출력큐의 사이즈가 입력큐의 사이즈와 같으면 yes출력 아니면 no 출력
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    if (ad == 'd') //내림차순시
    {
        int num = n; //최댓값부터 시작
        for (int i = 0; i < n; i++)
        {
            while (!stack.isEmpty() && stack.peek() == num) //저장스택이 비어있지않고, 스택의 맨위가 num과 맞을때
            {
                que.enqueue(stack.peek()); //출력큐에 저장스택의 맨위를 입력후 스택에서 삭제
                stack.pop();
                num--; //숫자 1 감소
            }
            if (arr.peek() > 0 && arr.peek() < n + 1) //입력큐의 값이 범위 내에 있을 때
            {
                if (arr.peek() == num)  //입력큐의 값이 지금 원하는 숫자와 같으면
                {
                    que.enqueue(arr.dequeue()); //출력큐에 입력큐의 값을 저장후 삭제
                    num--; //숫자 1 감소
                }
                else //지금 원하는 숫자와 다르면
                    stack.push(arr.dequeue()); //저장스택에 입력큐의 값을 저장후 삭제
            }

        }
        if (que.size() == n)
            cout << "Yes" << endl;  //출력큐의 사이즈가 입력큐의 사이즈와 같으면 yes출력 아니면 no 출력
        else
            cout << "No" << endl;
    }
}