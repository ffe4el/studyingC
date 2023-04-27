
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

const int MAX_QUEUE_SIZE = 21;


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
        if (!isFull()) {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    int dequeue() { // 첫 항목을 큐에서 빼서 반환
        if (!isEmpty()) {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    int peek() { // 첫 항목을 큐에서 빼지 않고 반환
        if (!isEmpty())
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }

    int size()
    {
        return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
};

int main()
{
    int n;
    int tmp;
    int prev=0;
    int input;
    CircularQueue arr;
    CircularQueue que;
    stack <int> stack;

    cin >> n; // 반복 횟수와 오름차순,내림차순 입력

    for (int i = 0; i < n; i++) //입력큐를 반복횟수만큼 입력
    {
        cin >> input;
        arr.enqueue(input);
        
       
    }
    while (arr.size() > 0)
    {
        int save = arr.peek();
        if (stack.empty() || stack.top() > arr.peek())
        {
            
            stack.push(arr.dequeue());
        }
        while (!stack.empty() && stack.top() < save)
        {
            prev = stack.top();
            que.enqueue(prev);
            stack.pop();
        }
       

    }
    if (!stack.empty())
    {
        tmp = stack.top();
        stack.pop();
        if (stack.empty()&&prev<tmp)
            que.enqueue(tmp);
        while (!stack.empty() && tmp < stack.top() && prev<tmp)
        {
            prev = tmp;
            que.enqueue(tmp);
            if (stack.size() == 1&&prev<stack.top())
            {
                que.enqueue(stack.top());
                stack.pop();
                break;
            }
            tmp = stack.top();
            stack.pop();
            
        }
    }
    
    
    cout << que.size();
    
}