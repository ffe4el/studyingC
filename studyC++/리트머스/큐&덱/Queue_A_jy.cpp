#include <iostream>
#include <string>

#define MAX_QUEUE_SIZE 100
using namespace std;

inline void error(const char* message) {
    printf("%s\n", message);
    exit(1);
}

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
    CircularDeque m_Que, w_Que;
    int cnt, num, match_Count = 0, m_Count = 0, w_Count = 0;
    char name[100][30];
    char s, rf;

    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        cin >> num >> name[i] >> s >> rf;

        if (s == 'm') {
            m_Count++;
            if (rf == 'R') {
                if (!w_Que.isEmpty()) {
                    cout << "Matched : " << name[i] << " " << name [w_Que.dequeue() - 1] << endl;
                    match_Count++;
                }
                else m_Que.enqueue(num);
            }
            else if (rf == 'F') {
                if (!w_Que.isEmpty()) {
                    cout << "Matched : " << name[i] << " " << name[w_Que.dequeue() - 1] << endl;
                    match_Count++;
                }
                else m_Que.addFront(num);
            }
        }
        else if (s == 'f'){
            w_Count++;
            if (rf == 'R') {
                if (!m_Que.isEmpty()) {
                    cout << "Matched : " << name[m_Que.dequeue() - 1] << " " << name[i] << endl;
                    match_Count++;
                }
                else w_Que.enqueue(num);
            }
            else if (rf == 'F') {
                if (!m_Que.isEmpty()) {
                    cout << "Matched : " << name[m_Que.dequeue() - 1] << " " << name[i] << endl;
                    match_Count++;
                }
                else m_Que.addFront(num);
            }
        }
    }

    cout << match_Count << " " << m_Count - match_Count << " " << w_Count - match_Count << endl;
}
